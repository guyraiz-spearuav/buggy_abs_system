void abs_pump() {
  if (brake_strength_from_lever > 0) { // pulled brake lever 
    abs_pump_strength = brake_strength_from_lever;
  } else if (brake_strength_from_lock == PWM_MAX_VALUE) { // one of the lock functions is on
    abs_pump_strength = brake_strength_from_lock;
  }
}
