#include <LowPower.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int ledPin = 13;
int outPin = 3;
int inPin = 4;
int i, value;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(inPin ,INPUT_PULLUP);
  Serial.begin(9600);//speed
  mySwitch.enableTransmit(10);//board pi #10
  mySwitch.setPulseLength(320);
  mySwitch.setProtocol(1);
  mySwitch.setRepeatTransmit(10);
  
}

void loop() {
//  for(i=0;i<40;i++){
//   LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
//  }
    digitalWrite(outPin, LOW);
    value = digitalRead(inPin);
  
    if (value == LOW) {
        mySwitch.send("111100000001010100010001");
        digitalWrite(ledPin, HIGH);
        delay(1000);  
        mySwitch.send("000000111111010100010100");
        delay(1000);
        digitalWrite(ledPin, LOW);
     }
}

