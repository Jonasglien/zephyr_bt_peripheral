/*
 * Copyright (c) 2020 Inventas AS
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef FLOKK_BEACON_SERVICE_H__
#define FLOKK_BEACON_SERVICE_H__

#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <bluetooth/gatt.h>
#include <bluetooth/hci.h>
#include <bluetooth/uuid.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/byteorder.h>
#include <sys/printk.h>
#include <zephyr.h>
#include <zephyr/types.h>

static struct bt_uuid_128 bt_uuid_custom_service = BT_UUID_INIT_128(
	0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 bt_uuid_custom_characteristic1 = BT_UUID_INIT_128(
	0xf1, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 bt_uuid_custom_characteristic2 = BT_UUID_INIT_128(
	0xf2, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 bt_uuid_custom_characteristic3 = BT_UUID_INIT_128(
	0xf3, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
	0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);


ssize_t read_characteristic1(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    void *buf, uint16_t len, uint16_t offset);

ssize_t write_characteristic2(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

ssize_t read_characteristic3(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    void *buf, uint16_t len, uint16_t offset);


ssize_t write_characteristic3(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

void helper_printer(uint8_t* buffer, ssize_t len);

#endif /* FLOKK_BEACON_SERVICE_H__ */