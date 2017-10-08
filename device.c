/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libusb.h>
#include "device.h"
#include "driver.h"

struct corsair_device_info corsairlink_devices[] = {
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c02,
		.device_id = 0xFF,
		.name = "Corsair Hydro Series 7289 USB Device",
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c03,
		.device_id = 0xFF, /** H100i GTX*/
		.name = "H100i GTX",
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c04,
		.device_id = 0x3b, /** H80i */
		.name = "H80i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_hid,
		.led_control_count = 1,
		.fan_control_count = 4,
		.pump_index = 5,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c04,
		.device_id = 0x3c, /** H100i */
		.name = "H100i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_hid,
		.led_control_count = 1,
		.fan_control_count = 4,
		.pump_index = 5,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c04,
		.device_id = 0x41, /** H110i */
		.name = "H110i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_hid,
		.led_control_count = 1,
		.fan_control_count = 4,
		.pump_index = 5,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c04,
		.device_id = 0x42, /** H110i Extreme*/
		.name = "H110i Extreme",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_hid,
		.led_control_count = 1,
		.fan_control_count = 4,
		.pump_index = 5,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c07,
		.device_id = 0xFF,
		.name = "H110i GTX", /** H110i GTX */
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c08,
		.device_id = 0xFF,
		.name = "H80i V2", /** H80i V2 */
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c09,
		.device_id = 0xFF,
		.name = "H100i V2", /** H100i V2 */
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c0a,
		.device_id = 0xFF,
		.name = "H115i", /** H115i */
		.read_endpoint = 0x02|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x02|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_asetek,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c0b,
		.device_id = 0xFF,
		.name = "Lighting Node PRO",
		.read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
		.read_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_pro,
		.led_control_count = 2, // two ports
		.fan_control_count = 0,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x0c0c,
		.device_id = 0xFF,
		.name = "Commander PRO",
		.read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
		.read_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_pro,
		.led_control_count = 2, // two ports
		.fan_control_count = 6,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c00,
		.device_id = 0xFF,
		.name = "USB Dongle", /** H115i */
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_dongle,
		.led_control_count = 1,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c03,
		.device_id = 0xFF,
		.name = "HX550i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c04,
		.device_id = 0xFF,
		.name = "HX650i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c05,
		.device_id = 0xFF,
		.name = "HX750i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c06,
		.device_id = 0xFF,
		.name = "HX850i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c07,
		.device_id = 0xFF,
		.name = "HX1000i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c08,
		.device_id = 0xFF,
		.name = "HX1200i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},	
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c09,
		.device_id = 0xFF,
		.name = "RM550i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c0a,
		.device_id = 0xFF,
		.name = "RM650i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c0b,
		.device_id = 0xFF,
		.name = "RM750i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c0c,
		.device_id = 0xFF,
		.name = "RM850i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0x1b1c,
		.product_id = 0x1c0d,
		.device_id = 0xFF,
		.name = "RM1000i",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_rmi,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
	{
		.vendor_id = 0xFFFF,
		.product_id = 0xFFFF,
		.device_id = 0xFF,
		.name = "Test Dummy",
		.read_endpoint = 0x01|LIBUSB_ENDPOINT_IN,
		.write_endpoint = 0x01|LIBUSB_ENDPOINT_OUT,
		.driver = &corsairlink_driver_dummy,
		.led_control_count = 0,
		.fan_control_count = 1,
		.pump_index = 0,
	},
};

size_t corsairlink_device_count = sizeof(corsairlink_devices)/sizeof(corsairlink_devices[0]);
