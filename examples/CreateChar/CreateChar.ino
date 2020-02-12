// NAME: CreateChar.ino
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
#include <LiquidCrystal_MCP23017_I2C.h>

uint8_t arrow[8] = {
  B00000,
  B00100,
  B00010,
  B11111,
  B11111,
  B00010,
  B00100,
  B00000
};

#define LCD_RS_PIN  MCP23017_PA7
#define LCD_RW_PIN  MCP23017_PA6
#define LCD_EN_PIN  MCP23017_PA5

#define LCD_D0_PIN  MCP23017_PB0
#define LCD_D1_PIN  MCP23017_PB1
#define LCD_D2_PIN  MCP23017_PB2
#define LCD_D3_PIN  MCP23017_PB3
#define LCD_D4_PIN  MCP23017_PB4
#define LCD_D5_PIN  MCP23017_PB5
#define LCD_D6_PIN  MCP23017_PB6
#define LCD_D7_PIN  MCP23017_PB7

#define LCD_BACKLIGHT_PIN MCP23017_PA1

#define LCD_I2C_ADDR  0x20

LiquidCrystal_MCP23017_I2C lcd(LCD_I2C_ADDR, LCD_RS_PIN, LCD_RW_PIN, LCD_EN_PIN, LCD_BACKLIGHT_PIN,
                               LCD_D0_PIN, LCD_D1_PIN, LCD_D2_PIN, LCD_D3_PIN,
                               LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(1, arrow);
  lcd.clear();

  lcd.write(1);
  lcd.print(" Hello World!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
