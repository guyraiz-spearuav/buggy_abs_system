void solenoids() {
  solenoids_function(rear_right_brake_solenoid_strength, Right);
  solenoids_function(rear_left_brake_solenoid_strength, Left);
  solenoids_function(front_brake_solenoid_strength, Front);
}

void solenoids_function(int x, int y) {
  if (y == Front) {
    for (int i = 0; i <= 2; i ++) {
      front_solenoids[i] = false;
    }
    if (x > 0) {
      for (int i = 0; i <= x; i ++) {
        front_solenoids[i + 1] = true;
      }
    }
  }
  if (y == Right) {
    for (int i = 0; i <= 2; i ++) {
      rear_right_solenoids[i] = false;
    }
    if (x > 0) {
      for (int i = 0; i <= x; i ++) {
        rear_right_solenoids[i] = true;
      }
    }
  }
  if (y == Left) {
    for (int i = 0; i <= 2; i ++) {
      rear_left_solenoids[i] = false;
    }
    if (x > 0) {
      for (int i = 0; i <= x; i ++) {
        rear_left_solenoids[i] = true;
      }
    }
  }
}
