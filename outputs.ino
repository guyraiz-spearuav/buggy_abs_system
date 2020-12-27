void outputs() {
  solenoid_output(rear_right_solenoids_pin, rear_right_solenoids);
  solenoid_output(rear_left_solenoids_pin, rear_left_solenoids);
  solenoid_output(front_solenoids_pin, front_solenoids);
  analogWrite(pump_pin, abs_pump_strength);
}

void solenoid_output(const int x[], bool y[]) {
  for (int i = 0; i <= 2; i ++) {
    digitalWrite(x [i], y [i]);
  }
}
