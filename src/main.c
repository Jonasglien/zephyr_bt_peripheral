

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>


#include "bluetooth/gap_peripheral.h"



void main(void)
{
	init_bt_peripheral();
}