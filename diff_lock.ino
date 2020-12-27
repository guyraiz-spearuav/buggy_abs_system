void brakeright () {
  rightback[0] = LOW;
  rightback[1] = LOW;
  rightback[2] = LOW;
  leftback[0] = HIGH;
  leftback[1] = HIGH;
  leftback[2] = HIGH;

}
void brakeleft () {
  rightback[0] = HIGH;
  rightback[1] = HIGH;
  rightback[2] = HIGH;
  leftback[0] = LOW;
  leftback[1] = LOW;
  leftback[2] = LOW;
}
void nobrake () {
  rightback[0] = LOW;
  rightback[1] = LOW;
  rightback[2] = LOW;
  leftback[0] = LOW;
  leftback[1] = LOW;
  leftback[2] = LOW;
}

void pumpcalc() {
  pump = (abs(speeddelta) - mindelta);
  pump = constrain(pump, 0, 20);
  pump = map (pump, 0, 20, 0, 255);
}
