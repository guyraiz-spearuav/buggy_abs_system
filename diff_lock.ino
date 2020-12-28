


void rear_speed_difference() {
  rear_speeds_delta = abs(right_wheel_speed - left_wheel_speed);
  if (right_wheel_speed > left_wheel_speed) {
    faster_right_or_left = Right;
  } else {
    faster_right_or_left = Left;
  }
}

int diff_lock_brake(float speed_delta) {
  Input = speed_delta;
  diff_lock_PID.Compute();
  return Output;
}


void setup_pid() {
  //initialize the variables we're linked to
  Input = 0;
  Setpoint = 0;

  //turn the PID on
  diff_lock_PID.SetMode(AUTOMATIC);
}
