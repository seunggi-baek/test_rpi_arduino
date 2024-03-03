void setup() {
  Serial.begin(115200);
  while(!Serial) {}

}

void loop() {
  Serial.println("Hello from Arduino");
  delay(1000);
}