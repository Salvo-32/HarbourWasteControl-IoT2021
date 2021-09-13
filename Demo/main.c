// Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "xtimer.h"       // https://doc.riot-os.org/xtimer_8h.html
#include "periph/gpio.h"  // https://doc.riot-os.org/gpio_8h.html
#include "periph/adc.h"   // https://doc.riot-os.org/adc_8h.html
#include "analog_util.h"  // https://doc.riot-os.org/analog__util_8h.html

//Libraries for LoRa
#include "fmt.h"
#include "net/loramac.h"
#include "semtech_loramac.h"
#include "fmt.h"
#if IS_USED(MODULE_SX127X)
#include "sx127x.h" //SX1276
#include "sx127x_netdev.h"
#include "sx127x_params.h"
#endif

//LoRa Global variables - constants
static semtech_loramac_t loramac;
#if IS_USED(MODULE_SX127X)
static sx127x_t sx127x;
#endif

//static uint8_t deveui[LORAMAC_DEVEUI_LEN] = {0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x04, 0x32, 0xC0};
//static uint8_t appeui[LORAMAC_APPEUI_LEN] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
//static uint8_t appkey[LORAMAC_APPKEY_LEN] = {0x5D, 0x6A, 0x0F, 0x79, 0x08, 0x5E, 0xDA, 0xC7, 0x93, 0x3D, 0x42, 0x14, 0x48, 0xEF, 0xBF, 0xC8};

static uint8_t deveui[LORAMAC_DEVEUI_LEN];
static uint8_t appeui[LORAMAC_APPEUI_LEN];
static uint8_t appkey[LORAMAC_APPKEY_LEN];


#define MESSAGE_MAXLEN      (80U)  //Messages

// Global Constants
#define ANALOG_INPUT_LINE_NUM 2

//Output leds - board.h File Reference - https://doc.riot-os.org/b-l072z-lrwan1_2include_2board_8h.html
#define	LED0_PIN	GPIO_PIN(PORT_A, 5) //(Not working)
#define	LED1_PIN	GPIO_PIN(PORT_B, 5)
#define LED2_PIN    GPIO_PIN(PORT_B, 6)
#define LED3_PIN	GPIO_PIN(PORT_B, 7)

// Global variables
//Analog inputs
int analog_input_line[ANALOG_INPUT_LINE_NUM] = { ADC_LINE(0), ADC_LINE(2) }; //Real PIN: 0 pH-sensor, 2 Turbidity-sensor //Software PIN: 0 pH-sensor, 1 Turbidity-sensor
#define ADC_RES     ADC_RES_12BIT
//adc_res_t adc_res = ADC_RES_12BIT; //TODO
int8_t sample_rate = 3; // X s

//Functions
int8_t lora_initialization(void) {

    /* Convert identifiers and application key */
    fmt_hex_bytes(deveui, "001D4F81A3AB11BE");
    fmt_hex_bytes(appeui, "70B3D57ED0042DA3");
    fmt_hex_bytes(appkey, "BD3353125C80DFCF83C71438579EAF40");


	/* Initialize the radio driver */
#if IS_USED(MODULE_SX127X)
    sx127x_setup(&sx127x, &sx127x_params[0], 0);
    loramac.netdev = &sx127x.netdev;
    loramac.netdev->driver = &sx127x_driver;
#endif

    /* Initialize the loramac stack */
    if(semtech_loramac_init(&loramac) == -1){
    	printf("semtech_loramac_init() failed! ");
    	return (-1);
    };
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);

    u_int8_t tmp1[50];
    semtech_loramac_get_deveui(&loramac, tmp1);
    printf("\n %u %u %u %u %u %u %u %u \n", tmp1[0], tmp1[1], tmp1[2], tmp1[3], tmp1[4], tmp1[5], tmp1[6], tmp1[7]);

    u_int8_t tmp2[50];
    semtech_loramac_get_appeui(&loramac, tmp2);
    printf("\n %u %u %u %u %u %u %u %u \n", tmp2[0], tmp2[1], tmp2[2], tmp2[3], tmp2[4], tmp2[5], tmp2[6], tmp2[7]);

    u_int8_t tmp3[50];
    semtech_loramac_get_appeui(&loramac, tmp3);
    printf("\n %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u \n", tmp3[0], tmp3[1], tmp3[2], tmp3[3], tmp3[4], tmp3[5], tmp3[6], tmp3[7], tmp3[8], tmp3[9], tmp3[10], tmp3[11], tmp3[12], tmp3[13], tmp3[14], tmp3[15]);

    /* Use a fast datarate, e.g. BW125/SF7 in EU868 */
    //semtech_loramac_set_dr(&loramac, LORAMAC_DR_5);
    semtech_loramac_set_dr(&loramac, 5);

    /* Start the Over-The-Air Activation (OTAA) procedure to retrieve the
     * generated device address and to get the network and application session
     * keys.
     */

    puts("Starting join procedure");
    u_int8_t res = semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA);
    switch (res) {
      	case SEMTECH_LORAMAC_JOIN_FAILED:
			puts("semtech_loramac_join() - SEMTECH_LORAMAC_JOIN_FAILED");
			return (-1);
			break;
    	case SEMTECH_LORAMAC_BUSY:
    		puts("semtech_loramac_join() - SEMTECH_LORAMAC_BUSY - the mac is already active (join or tx in progress)");
    		return (-1);
    		break;
    	case SEMTECH_LORAMAC_ALREADY_JOINED:
    		puts("semtech_loramac_join() - SEMTECH_LORAMAC_ALREADY_JOINED - network was already joined");
    		return (-1);
    		break;
    	default:
			break;
	}
    puts("Join procedure succeeded");
    return (0);
}

void blink_led(gpio_t led_pin, u_int16_t duration){
    gpio_write(led_pin, 1); //Switch ON to inform about the start of read
    //puts("Led is ON");
    xtimer_sleep(duration);
    gpio_write(led_pin, 0); //Switch OFF to inform about the end of read
    //puts("Led is OFF");
}

int main(void) {
    int8_t res;
    uint8_t ret;
    printf("\n RIOT application - B-L072Z-LRWAN1 \n");
    printf("1) Analog read from Pins: A0 & A2 only. A1, A3 - A5 are not deployable \n");

    //Connection initialization
    res = lora_initialization();
    if (res != 0) {
        printf("LoRa initialization failed with **Error %d**", res);
        return (res);
    }
    puts("LoRa initialization completed successfully");

    // initialize the ADC lines
    for (int i = 0; i < ANALOG_INPUT_LINE_NUM; i++) {
        if ((res = adc_init(analog_input_line[i])) == -1) {
            printf("Initialization of ADC_LINE(%d) failed\n", analog_input_line[i]);
            return (res);
        }
    }
    printf("Initialization of ADC_LINEs completed\n");

    int line_num; // 0 pH sensor, 1 for Turbidity sensor, 2 LM-35 Temperature
    int sample;
    float mapped_voltage;
    float physical_quantity1;
    float physical_quantity2;
    float min_physical_value[ANALOG_INPUT_LINE_NUM] = { 0, 0 }; // pH is Adimensional, Turbidity is 0 mg/L
    float max_physical_value[ANALOG_INPUT_LINE_NUM] = { 14.0, 100.0 }; //mg/L

    //LoRa messages
    const char message_structure[] = "{\"turbidity\":\"%f\", \"ph\":\"%f\"}"; //"device" field is removed since it is already in TTN message
    char buffer[MESSAGE_MAXLEN];
    strcpy(buffer, "");

    while (1) {
        // ph-Sensor
        line_num = 0; // 0 pH sensor
        sample = adc_sample(analog_input_line[line_num], ADC_RES);
        if (sample == -1) { // Error with sample resolution
            printf("ADC_LINE(%d): selected resolution not applicable\n", analog_input_line[line_num]);
            return (sample); //In this case sample contains Error code
        }
        printf("Sampled bit (raw sample) from pin A%d: %d\n", line_num, sample);
        mapped_voltage = sample * (5.0 / pow(2, 12)); //Bit -> Voltage
        printf("Voltage read: %f V \n", mapped_voltage);
        physical_quantity1 = adc_util_mapf(sample, ADC_RES, min_physical_value[0], max_physical_value[0]);
        printf("pH values: %f \n\n", physical_quantity1);

        blink_led(LED1_PIN, 1); //User information about pH read

        // Turbidity sensor
        line_num = 1;
        sample = adc_sample(analog_input_line[line_num], ADC_RES);
        if (sample == -1) { // Error with sample resolution
            printf("ADC_LINE(%d): selected resolution not applicable\n", analog_input_line[line_num]);
            return (sample); //Bit
        }
        printf("Analog raw value from pin A%d: %d\n", line_num, sample);
        mapped_voltage = sample * (5.0 / pow(2, 12)); //Bit -> Voltage
        printf("Voltage read: %f V \n", mapped_voltage);
        physical_quantity2 = adc_util_mapf(sample, ADC_RES, min_physical_value[1], max_physical_value[1]);
        printf("Turbidity values: %f mg/L \n", physical_quantity2);

        blink_led(LED2_PIN, 1); //User information about turbidity read

        //Send data via Lora
        sprintf(buffer, message_structure, physical_quantity1, physical_quantity2);
        ret = semtech_loramac_send(&loramac, (uint8_t*) buffer, strlen(buffer));
        if (ret != SEMTECH_LORAMAC_TX_DONE) {
            printf("Cannot send message '%s', returned code: %u\n", buffer, ret);
            return (-1);
        }
        blink_led(LED3_PIN, 2); //User information about sending Lora message
        puts("--------------");

        xtimer_sleep(sample_rate);
    }

    /* should be never reached */
    return (0);
}
