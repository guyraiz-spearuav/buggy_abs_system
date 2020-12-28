void outputs() {
  solenoid_output(rear_right_solenoids_pin, rear_right_solenoids); // output to rear right wheel solenoids
  solenoid_output(rear_left_solenoids_pin, rear_left_solenoids); // output to rear left wheel solenoids
  solenoid_output(front_solenoids_pin, front_solenoids); // output to front wheels solenoids
  analogWrite(pump_pin, abs_pump_strength); // output to abs pump
}

void solenoid_output(const int pin[], bool Position[]) {
  for (int i = 0; i <= 2; i ++) {
    digitalWrite(pin [i], Position [i]);
  }
}
