void solenoids() { // set solenoid positions
  set_solenoids_position(rear_right_brake_solenoid_strength, Right); // rear right
  set_solenoids_position(rear_left_brake_solenoid_strength, Left); // rear left
  set_solenoids_position(front_brake_solenoid_strength, Front); // front
}

void set_solenoids_position(int strength, int Position) {
  if (Position == Front) {
    for (int i = 0; i <= 2; i ++) {
      front_solenoids[i] = false;
    }
    if (strength > 0) {
      for (int i = 0; i <= strength; i ++) {
        front_solenoids[i + 1] = true;
      }
    }
  }
  if (Position == Right) {
    for (int i = 0; i <= 2; i ++) {
      rear_right_solenoids[i] = false;
    }
    if (strength > 0) {
      for (int i = 0; i <= strength; i ++) {
        rear_right_solenoids[i] = true;
      }
    }
  }
  if (Position == Left) {
    for (int i = 0; i <= 2; i ++) {
      rear_left_solenoids[i] = false;
    }
    if (strength > 0) {
      for (int i = 0; i <= strength; i ++) {
        rear_left_solenoids[i] = true;
      }
    }
  }
}
