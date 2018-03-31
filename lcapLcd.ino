
#include <LiquidCrystal.h>

#define analogPin      0          
#define chargePin      12       
#define dischargePin   11        
#define resistorValue  10000.0F   



// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, rw = 8, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                
float nanoFarads;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Cap meter ");
  
  pinMode(chargePin, OUTPUT);     
  digitalWrite(chargePin, LOW); 
  
}

void loop() {
  

  lcd.print("Cap meter       ");
  lcd.setCursor(0, 1);
  
  digitalWrite(chargePin, HIGH);  
  startTime = millis();
  while(analogRead(analogPin) < 648){       
  }

  elapsedTime= millis() - startTime;
  microFarads = ((float)elapsedTime / resistorValue) * 1000;   
  lcd.print(elapsedTime);       
  lcd.print(" mS ");         

  if (microFarads > 1){
    lcd.print((long)microFarads);       
    lcd.print(" uF        ");         
  }

  else{
    nanoFarads = microFarads * 1000.0;      
    lcd.print((long)nanoFarads);         
    lcd.print(" nF        ");          
    delay(500); 
  }

  digitalWrite(chargePin, LOW);            
  pinMode(dischargePin, OUTPUT);            
  digitalWrite(dischargePin, LOW);          
  while(analogRead(analogPin) > 0){         
  }

  pinMode(dischargePin, INPUT);            

  //lcd.clear();
 
}

