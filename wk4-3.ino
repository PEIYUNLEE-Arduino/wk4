//include library
#include <Wire.h>
#include <SPI.h>
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "animation.h"

#define Logo_width 64
#define Logo_height 64

//設定腳位
SSD1306Wire  display(0x3c, 21, 22);


int walk_duration=120,idle_duration=250;
int buttonPin=32;
int buttonState = 1;
int posx=0;
int walk_count=0,idle_count=0;

void setup() {
  //設定包率
  display.init();//初始化(init)
  display.setContrast(255); //數值介於0~255，調整對比
  display.clear();//清除螢幕和緩衝區(clear)
  digitalWrite(buttonPin,LOW);
  pinMode(buttonPin,INPUT);
}

void loop() { 
  buttonState = digitalRead(buttonPin);
  if(buttonState==HIGH){//walking
      for(;buttonState == HIGH;walk_count++){
        if(walk_count==8)walk_count=0;
        buttonState = digitalRead(buttonPin);
        display.clear();
        display.drawXbm(posx, 0, Logo_width, Logo_height,walk[walk_count]);
        display.display();
        if (buttonState == LOW){goto aa;}
        if(posx==110){posx=-60;}
        posx+=10;
        delay(150);
     }
  }
  if(buttonState==LOW){//idle
   for(;buttonState == LOW;idle_count++){
        if(idle_count==2){idle_count=0;}
        buttonState = digitalRead(buttonPin);
        display.clear();
        display.drawXbm(posx, 0, Logo_width, Logo_height,idle[idle_count]);
        display.display();
        if (buttonState == HIGH){goto aa;}
        delay(500);
     }
  }
  aa:;
}
