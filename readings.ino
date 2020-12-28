void readings() {
  brake_strength_from_lever = analogRead(brake_strength_pin); // brake lever input
  lock_right = digitalRead(lock_right_pin); // lock rear right wheel input
  lock_left = digitalRead(lock_left_pin); // lock rear left wheel input
  lock_rear = digitalRead(lock_rear_pin); // lock rear axle wheel input
  difflock = digitalRead(difflock_pin); // emulate rear diff lock button
}
