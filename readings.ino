void readings() {
  brake_strength_from_lever = analogRead(brake_strength_pin);
  lock_right = digitalRead(lock_right_pin);
  lock_left = digitalRead(lock_left_pin);
  lock_rear = digitalRead(lock_rear_pin);
  difflock = digitalRead(difflock_pin);
}
