void setup(){
  Serial.begin(38400);
  pinMode(2, INPUT);
}

void loop(){
  int switchStatus = digitalRead(2);
  Serial.println(switchStatus);
  delay(100);
}
