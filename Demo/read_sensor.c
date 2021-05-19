#include "read_sensor.h"
#include "random.h"

#include <stdio.h>
#include <stdint.h>

uint32_t virtual_sensor(void) {
	return random_uint32();
}

int read_turbidity(void) {
	return virtual_sensor();
}

int read_ph(void) {
	return virtual_sensor();
}

int read_temperature(void) {
	return virtual_sensor();
}
