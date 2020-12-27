void wheel_speed_calculation() {
  if (millis() < right_wheel_timer + WHEEL_SPEED_TIMEOUT_MS / NUMBER_OF_PROBES) {
    right_wheel_speed = 0;
  }
  if (millis() < left_wheel_timer + WHEEL_SPEED_TIMEOUT_MS / NUMBER_OF_PROBES) {
    right_wheel_speed = 0;
  }
  if (run_right_wheel_speed_function) {
    right_wheel_speed = wheel_speed (right_wheel_timer, previous_right_wheel_timer);
    run_right_wheel_speed_function = false;
  }
  if (run_left_wheel_speed_function) {
    left_wheel_speed = wheel_speed (left_wheel_timer, previous_left_wheel_timer);
    run_left_wheel_speed_function = false;
  }
}


float wheel_speed(long unsigned int x, long unsigned int y) {
  int delta = x - y;
  float RPS = 1000 / delta / NUMBER_OF_PROBES;
  return RPS * TYRE_CIRCUMFRENCE_MM / 1000;
}

void rightwheelping () {
  previous_right_wheel_timer = right_wheel_timer;
  right_wheel_timer = millis();
  run_right_wheel_speed_function = true;
}

void leftwheelping () {
  previous_left_wheel_timer = right_wheel_timer;
  left_wheel_timer = millis();
  run_left_wheel_speed_function = true;
}
