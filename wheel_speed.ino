void wheel_speed_calculation() {
  if (millis() < right_wheel_timer + WHEEL_SPEED_TIMEOUT_MS / NUMBER_OF_PROBES) { // set speed to 0 if timeout has occurred - rear right
    right_wheel_speed = 0;
  }
  if (millis() < left_wheel_timer + WHEEL_SPEED_TIMEOUT_MS / NUMBER_OF_PROBES) { // set speed to 0 if timeout has occurred - rear left
    left_wheel_speed = 0;
  }
  if (run_right_wheel_speed_function) { // calculate wheel speed - rear right
    right_wheel_speed = wheel_speed (right_wheel_timer, previous_right_wheel_timer);
    run_right_wheel_speed_function = false;
  }
  if (run_left_wheel_speed_function) { // calculate wheel speed - rear left
    left_wheel_speed = wheel_speed (left_wheel_timer, previous_left_wheel_timer);
    run_left_wheel_speed_function = false;
  }
}


float wheel_speed(long unsigned int x, long unsigned int y) {
  int delta = x - y;
  float RPS = 1000 / delta / NUMBER_OF_PROBES;
  return RPS * TYRE_CIRCUMFRENCE_MM / 1000;
}

void rightwheelping () { // run when rear right wheel sensor pings
  previous_right_wheel_timer = right_wheel_timer;
  right_wheel_timer = millis();
  run_right_wheel_speed_function = true;
}

void leftwheelping () { // run when rear left wheel sensor pings
  previous_left_wheel_timer = right_wheel_timer;
  left_wheel_timer = millis();
  run_left_wheel_speed_function = true;
}
