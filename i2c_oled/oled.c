#include "oled.h"
#include "i2c_ops.h"
/*
 * oled.c
 *
 *  Created on: 12-Mar-2019
 *      Author: RAJ JOHRI
 */



void sendCommand(unsigned char);
void sendData(unsigned char*);
void write_display(unsigned char *data);

void sendCommand(unsigned char cmd)
{
    unsigned char i2c_data[2] = {SSD1306_CONTROL_REG,cmd};
    i2c_send(i2c_data,2);
}

void sendData(unsigned char *data)
{
    int i;
    unsigned char i2c_data[2] = {0};
    i2c_data[0] = SSD1306_DATA_REG;
    for(i=0;i<1024;i++)
    {
        i2c_data[1] = data[i];
        i2c_send(i2c_data,2);
    }
}

void write_display(unsigned char *data)
{
    int i;
    unsigned char i2c_data[2];
    i2c_data[0] = SSD1306_DATA_REG;
    for(i=0;i<1024;i++)
    {
        i2c_data[1] = data[i];
        i2c_send(i2c_data,2);
    }
}

