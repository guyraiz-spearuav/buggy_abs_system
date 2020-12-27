void rear_lock_option() {
  if (lock_right || lock_left || lock_rear) {
    brake_strength_from_lock = PWM_MAX_VALUE;
  } else {
    brake_strength_from_lock = PWM_MIN_VALUE;
  }
  if (lock_right) {
    rear_right_brake_solenoid_strength = 3;
    rear_left_brake_solenoid_strength = 0;
    front_brake_solenoid_strength = 0;
  } else if (lock_left) {
    rear_right_brake_solenoid_strength = 0;
    rear_left_brake_solenoid_strength = 3;
    front_brake_solenoid_strength = 0;
  } else if (lock_rear) {
    rear_right_brake_solenoid_strength = 3;
    rear_left_brake_solenoid_strength = 3;
    front_brake_solenoid_strength = 0;
  }
}
