/*
 * oled_ops.h
 *
 *  Created on: 12-Mar-2019
 *      Author: RAJ JOHRI
 */

#ifndef OLED_OPS_H_
#define OLED_OPS_H_


extern void sendCommand(unsigned char);
extern void sendData(unsigned char*);
extern void write_display(unsigned char *data);


#endif /* OLED_OPS_H_ */
