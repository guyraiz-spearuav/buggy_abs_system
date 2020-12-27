void abs_pump() {
  if (brake_strength_from_lever > 0) {
    abs_pump_strength = brake_strength_from_lever;
  } else if (brake_strength_from_lock == PWM_MAX_VALUE) {
    abs_pump_strength = brake_strength_from_lock;
  }
}
