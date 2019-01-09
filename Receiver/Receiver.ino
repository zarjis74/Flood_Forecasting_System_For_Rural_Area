#include <RCSwitch.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
RCSwitch mySwitch = RCSwitch();

float level;

int Hval=12;
int Lval=2;
int BUZZER = 10 ;

void setup() {
  mySwitch.enableReceive(0);

  lcd.begin(16, 2);
  lcd.print("WATER LEVEL INDI");
  
  pinMode(BUZZER,OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
    
    level = mySwitch.getReceivedValue();

    level = (Hval - Lval)/level;
    level = level*100;

    if (level>100) {level=100;}
    
    lcd.setCursor(0, 1);
    lcd.print("LEVEL ");
    lcd.print(level);
    lcd.print(" %       ");
    
    mySwitch.resetAvailable();
    
  }   
  digitalWrite(BUZZER,LOW);
  if (level > 99) {digitalWrite(BUZZER,LOW); delay(100); digitalWrite(BUZZER,HIGH); delay(100);}
  else  {digitalWrite(BUZZER,HIGH);}
}
