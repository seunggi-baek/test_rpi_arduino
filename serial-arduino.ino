int outputPin = 2;
int inputValue = 0;

String inputString = "";
boolean stringComplete = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);

  digitalWrite(outputPin, HIGH);
  Serial.begin(115200);
  while(!Serial) { }

  while(Serial.available() <= 0) {
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
        Serial.println("led turned on");
      }
      else if (inputString.indexOf("off") > -1) {
        digitalWrite(outputPin, LOW);
        Serial.println("led turned off");
      }
      else {
        Serial.println("invalid set command");
      }
    }
    else {
      Serial.println("invalid command");
    }

    stringComplete = false;
    inputString = "";
  }
  delay(100);

  if (Serial.available() > 0) {
    serialEvent();
  }
}

void sendStatus() {
  char buffer[50];
  inputValue = random(300);
  sprintf(buffer, "Random input is %d", inputValue);
  Serial.println(buffer);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
