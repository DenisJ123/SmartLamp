#include <LiquidCrystal.h>

int h=14,m=46,s=0;
int alarmH = 14, alarmMin = 46, alarmSec = 15;
LiquidCrystal My_LCD(19, 23, 18, 17, 16, 15);
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buzzer = 33;



String inputString = "";
boolean stringComplete = false;

void setup() {

  My_LCD.begin(16, 2);
  pinMode(buzzer, OUTPUT);

}

void loop() {
 
 s=s+1;
  if(s==60){
    m=m+1;
    s=0;
  }
  
  if(m==60){
    m=0;
    h=h+1;
  }
  
  My_LCD.print("HOURS=");
  My_LCD.print(h);
  My_LCD.setCursor(10,0);
  My_LCD.print("MIN=");
  My_LCD.print(m);
  My_LCD.setCursor(0,1);
  My_LCD.print("SEC=");
  My_LCD.print(s);
  delay(1000);
  My_LCD.clear();

 if((h == alarmH) && (m == alarmMin) && (alarmSec == s)){
    if((h == alarmH) && (m == alarmMin) && (alarmSec == s)){
    tone(buzzer, 500); 
    delay(1000);       
    noTone(buzzer);     
    }  
     
  }
}
