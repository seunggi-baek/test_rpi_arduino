#include <SoftwareSerial.h>

// RX, TX 핀을 정의합니다. 아두이노에 따라 사용 가능한 핀이 다를 수 있으니 확인이 필요합니다.
SoftwareSerial mySerial(2, 3); // RX, TX

int outputPin = 7;
int inputValue = 0;

String inputString = "";
boolean stringComplete = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);

  digitalWrite(outputPin, HIGH);
  
//  Serial.begin(115200);
  mySerial.begin(115200);
  while(!mySerial) { }

  while(mySerial.available() <= 0) {
    sendStatus();
    delay(300);
  }
}

void loop() {
  if (stringComplete) {
    if (inputString.startsWith("status")) {
      sendStatus();
    }
    else if (inputString.startsWith("set")) {
      if (inputString.indexOf("on") > -1) {
        digitalWrite(outputPin, HIGH);
        mySerial.println("led turned on");
      }
      else if (inputString.indexOf("off") > -1) {
        digitalWrite(outputPin, LOW);
        mySerial.println("led turned off");
      }
      else {
        mySerial.println("invalid set command");
      }
    }
    else {
      mySerial.println("invalid command");
    }

    stringComplete = false;
    inputString = "";
  }
  delay(100);

  if (mySerial.available() > 0) {
    serialEvent();
  }
}

void sendStatus() {
  char buffer[50];
  inputValue = random(300);
  sprintf(buffer, "Random input is %d", inputValue);
  mySerial.println(buffer);
}

void serialEvent() {
  while (mySerial.available()) {
    char inChar = (char)mySerial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}