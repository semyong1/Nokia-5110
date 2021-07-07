#include "U8glib.h"
#include "rus4x6.h"
#define backlight_pin 11
U8GLIB_PCD8544 u8g(8, 9, 12, 10, 11);  // CLK=10, DIN=8, CE=9, DC=12, RST=11

void draw(void) {
  u8g.drawLine(0, 9, 90, 9);
  u8g.drawLine(0, 25, 90, 25);
  u8g.drawLine(20, 5, 20, 180);
  u8g.drawLine(60, 5, 60, 180);
  u8g.drawLine(0, 40, 90, 40);
  u8g.setFont(rus4x6);
  u8g.drawStr(35, 40, "Привет");  // текст и X Y 
  u8g.drawStr(21, 32, "Тест");
  u8g.setPrintPos(15, 15);  // позиция текста
  u8g.drawStr(33, 32, "Таблицы");
  u8g.drawStr(21, 15, "С помощью");
  u8g.drawStr(21, 24, "drawstr");
}

void setup(void) {
  analogWrite(backlight_pin, 60);  // яркость дисплея
}

void loop(void) {

  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  delay(5000); 
}
