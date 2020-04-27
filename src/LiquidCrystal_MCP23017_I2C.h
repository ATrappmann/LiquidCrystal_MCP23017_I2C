// NAME: LiquidCrystal_MCP23017_I2C.h
//
// DESC: This is a library for an LCD display with an I2C board based on the
// MCP23017 I2C Port Expander. It allows individual pin mapping from the MCP23017
// to the 1602 LCD.
//
// This file is part of the LiquidCrystal_MCP23017_I2C for the Arduino environment.
// https://github.com/ATrappmann/LiquidCrystal_MCP23017_I2C
//
// MIT License
//
// Copyright (c) 2020 Andreas Trappmann
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef LIQUIDCRYSTAL_MCP23017_I2C_H
#define LIQUIDCRYSTAL_MCP23017_I2C_H

#include <inttypes.h>
#include "Print.h"

#define MCP23017_PA0  0x0001
#define MCP23017_PA1  0x0002
#define MCP23017_PA2  0x0004
#define MCP23017_PA3  0x0008
#define MCP23017_PA4  0x0010
#define MCP23017_PA5  0x0020
#define MCP23017_PA6  0x0040
#define MCP23017_PA7  0x0080
#define MCP23017_PB0  0x0100
#define MCP23017_PB1  0x0200
#define MCP23017_PB2  0x0400
#define MCP23017_PB3  0x0800
#define MCP23017_PB4  0x1000
#define MCP23017_PB5  0x2000
#define MCP23017_PB6  0x4000
#define MCP23017_PB7  0x8000

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class LiquidCrystal_MCP23017_I2C : public Print {
public:
  LiquidCrystal_MCP23017_I2C(uint8_t i2c_addr);

  LiquidCrystal_MCP23017_I2C(uint8_t i2c_addr, uint16_t rs, uint16_t rw, uint16_t enable, uint16_t backlight,
    uint16_t d0, uint16_t d1, uint16_t d2, uint16_t d3,
    uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7);
  LiquidCrystal_MCP23017_I2C(uint8_t i2c_addr, uint16_t rs, uint16_t rw, uint16_t enable,
		uint16_t d0, uint16_t d1, uint16_t d2, uint16_t d3,
		uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7);

  LiquidCrystal_MCP23017_I2C(uint8_t i2c_addr, uint16_t rs, uint16_t rw, uint16_t enable, uint16_t backlight,
    uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7);
  LiquidCrystal_MCP23017_I2C(uint8_t i2c_addr, uint16_t rs, uint16_t rw, uint16_t enable,
    uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7);

  void init(bool fourbitmode, uint8_t i2c_addr, uint16_t rs, uint16_t rw, uint16_t enable, uint16_t backlight,
	    uint16_t d0, uint16_t d1, uint16_t d2, uint16_t d3,
	    uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7);

  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void noBacklight();
  void backlight();
  void autoscroll();
  void noAutoscroll();

  void setRowOffsets(int row1, int row2, int row3, int row4);
  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t);
  virtual size_t write(uint8_t);
  void command(uint8_t);

  using Print::write;

#ifdef MCP23017_DIRECT_PIN_ACCESS
public:
#else
private:
#endif
  void writePin(uint16_t pin, uint8_t value);

private:
  void writeRegister(uint8_t regAddr, uint8_t regValue);
  void writeRS(uint8_t value);
  void writeRW(uint8_t value);
  void writeEnable(uint8_t value);

  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void write8bits(uint8_t);
  void pulseEnable();

  uint8_t  _i2c_addr;
  uint16_t _rs_pin;       // LOW: command.  HIGH: character.
  uint16_t _rw_pin;       // LOW: write to LCD.  HIGH: read from LCD.
  uint16_t _en_pin;       // activated by a HIGH pulse.
  uint16_t _data_pins[8];
  uint16_t _data_port;
  uint16_t _backlight_pin;

  uint8_t _gpioa_value;
  uint8_t _gpiob_value;

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines;
  uint8_t _row_offsets[4];
};

#endif /* LIQUIDCRYSTAL_MCP23017_I2C_H */
