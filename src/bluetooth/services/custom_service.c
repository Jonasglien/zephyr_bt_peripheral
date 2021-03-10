

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

#include "custom_service.h"



uint8_t charac1[2] = {0x00, 0x01};
uint8_t charac2[3] = {0x00, 0x01, 0x02};
uint8_t charac3[4] = {0x00, 0x01, 0x02, 0x03};

BT_GATT_SERVICE_DEFINE(custom_service,
  BT_GATT_PRIMARY_SERVICE(&bt_uuid_custom_service),
  BT_GATT_CHARACTERISTIC(&bt_uuid_custom_characteristic1.uuid, BT_GATT_CHRC_READ,
                        BT_GATT_PERM_READ_ENCRYPT, read_characteristic1, NULL, NULL),
  BT_GATT_CHARACTERISTIC(&bt_uuid_custom_characteristic2.uuid, BT_GATT_CHRC_WRITE,
                         BT_GATT_PERM_WRITE_ENCRYPT, NULL, write_characteristic2, NULL),
  BT_GATT_CHARACTERISTIC(&bt_uuid_custom_characteristic3.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                        BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT, read_characteristic3, write_characteristic3, NULL),
);


ssize_t read_characteristic1(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    void *buf, uint16_t len, uint16_t offset)
{
  printk("read charac1: ");
  helper_printer(charac1, sizeof(charac1));
  
  
  return bt_gatt_attr_read(conn, attr, buf, len, offset, &charac1,
                           sizeof(charac1));
} 


ssize_t write_characteristic2(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
  const uint8_t *write_buffer = buf;

  if (len == sizeof(charac2))
  {
    memcpy(&charac2, write_buffer, sizeof(write_buffer));
    printk("Written to charac2: ");
    helper_printer(buf, len);
  } else 
  {
    printk("write-buffer to charac2 is %u long and contains: ", len);
    helper_printer(buf, len);
  }
  

  if (!len) {
    return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
  }

  return len;
}

ssize_t read_characteristic3(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    void *buf, uint16_t len, uint16_t offset)
{
  printk("read charac3: ");
  helper_printer(charac3, sizeof(charac3));
  
  
  return bt_gatt_attr_read(conn, attr, buf, len, offset, &charac3,
                           sizeof(charac3));
} 

ssize_t write_characteristic3(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                    const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
  const uint8_t *write_buffer = buf;

  if (len == sizeof(charac3))
  {
    memcpy(&charac3, write_buffer, sizeof(write_buffer));
    printk("Written to charac3: ");
    helper_printer(buf, len);
  } else 
  {
    printk("write-buffer to charac3 is %u long and contains: ", len);
    helper_printer(buf, len);
  }
  

  if (!len) {
    return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
  }

  return len;
}

void helper_printer(uint8_t* buffer, ssize_t len)
{
  for (int i = 0; i<len; i++)
  {
    printk(" %d", buffer[i]);
  }
  printk("\n");
  return;
}
