#include "msp.h"
#include "oled.h"
/*
 * i2c_ops.c
 *
 *  Created on: 12-Mar-2019
 *      Author: RAJ JOHRI
 */

void i2c_init();
void i2c_send(unsigned char*, unsigned int);
static void i2c_write_txbuf(unsigned char);
static void enable_i2c();
static void disable_i2c();
static void generate_start();
static void generate_stop();

void i2c_init()
{
    /* make sure module is disabled */
    disable_i2c();

    /* change P1.6 and P1.7 as primary function */
    P1SEL0 |= BIT6;
    P1SEL1 &= ~(BIT6);

    P1SEL0 |= BIT7;
    P1SEL1 &= ~(BIT7);

    /* modes selected:
     * master, i2c, synchronous, SMCLK, transmitter */
    UCB0CTLW0 |= 0x0FD0;

    /* clock: 100 KHz */
    UCB0BRW = 30;

    /* initialize slave address */
    UCB0I2CSA = SLAVE_ADDR;

    /* enable module only when transmission is required */
}

void i2c_send(unsigned char *data, unsigned int len)
{

    /* write number of bytes to be sent to slave
     * enable auto stop generation in UCBxCTLW1
     */

    /* enable i2c module */
    enable_i2c();

    /* generate start condition and wait for the bus */
    generate_start();
    while((UCB0IFG & UCTXIFG0) == 0);

    /* write data byte by byte to buffer */
    while(len--)
    {
        i2c_write_txbuf(*data);
        data++;
    }

    /* force stop and check if stop is generated or not */
    generate_stop();
    while((UCB0IFG & UCSTPIFG) == 0);

    /* transmission completed, disable the module */
    disable_i2c();
}

/* write data on i2c bus */
static void i2c_write_txbuf(unsigned char byte)
{
    UCB0TXBUF = byte;
    while((UCB0IFG & UCTXIFG0) == 0);
}

/* enable i2c bus */
static void enable_i2c()
{
    UCB0CTLW0 &= ~(0x01);

}

/* disable i2c bus */
static void disable_i2c()
{
    UCB0CTLW0 |= 0x01;
}

/* generate start condition */
static void generate_start()
{
    UCB0CTLW0 |= 0x0002;
}

/* force stop condition */
static void generate_stop()
{
    UCB0CTLW0 |= 0x0004;
}
