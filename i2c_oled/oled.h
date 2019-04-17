/*
 * oled.h
 *
 *  Created on: 12-Mar-2019
 *      Author: RAJ JOHRI
 */

#ifndef OLED_H_
#define OLED_H_

#define SLAVE_ADDR              0x3C

#define SSD1306_DISPLAYON       0xAF
#define SSD1306_DISPLAYOFF      0xAE
#define SSD1306_NORMALDISPLAY   0xA6
#define SSD1306_INVERTDISPLAY   0xA7
#define SSD1306_MULTIPLEX_RATIO 0xA8

// registers
#define SSD1306_CONTROL_REG     0x00  // Co = 0, DC = 0
#define SSD1306_DATA_REG        0x40



#endif /* OLED_H_ */
