#include "read_sensor.h"

#include "xtimer.h"
#include "net/loramac.h"     /* core loramac definitions */
#include "semtech_loramac.h" /* package API */

#include <stdio.h>
#include <string.h>


#define TX_INTERVAL (60000LU * US_PER_MS)

#define MSG_MAXLEN 20

extern semtech_loramac_t loramac;  /* The loramac stack device descriptor */
/* define the required keys for OTAA, e.g over-the-air activation (the
   null arrays need to be updated with valid LoRa values) */
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x00, 0x1D, 0x4F, 0x81, \
                                                    0xA3, 0xAB, 0x11, 0xBE };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x70, 0xB3, 0xD5, 0x7E, \
                                                    0xD0, 0x04, 0x2D, 0xA3 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = {0xBD,0x33,0x53,0x12,0x5C,0x80,0xDF,0xCF,0x83,0xC7,0x14,0x38,0x57,0x9E,0xAF,0x40};

int main(void)
{
	char message[MSG_MAXLEN];

	/* 1. initialize the LoRaMAC MAC layer */
	semtech_loramac_init(&loramac);
	/* 2. set the keys identifying the device */
	semtech_loramac_set_deveui(&loramac, deveui);
	semtech_loramac_set_appeui(&loramac, appeui);
	semtech_loramac_set_appkey(&loramac, appkey);
	
	/* Use a fast datarate, e.g. BW125/SF7 in EU868 */  
	semtech_loramac_set_dr(&loramac, LORAMAC_DR_5);

	/* 3. join the network */
	if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
	        puts("Join procedure failed");
        return 1;
    }
    puts("Join procedure succeeded");
			
	int turbidity = read_turbidity();

	sprintf(message, "%s\n%s\n%d", ALTITUDE, LATITUDE, turbidity);
	int ret = semtech_loramac_send(&loramac, (uint8_t *)message, strlen(message));

	if (ret != SEMTECH_LORAMAC_TX_DONE) {
		printf("Cannot send message '%s'\nsemtech_loramac_send(): returned %d'\n", message, ret);
		return 1;
	}

}


