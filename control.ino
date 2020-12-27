void control () { // output values to actual controls
  digitalWrite (rightsole1, rightback[0]);
  digitalWrite (rightsole2, rightback[1]);
  digitalWrite (rightsole3, rightback[2]);
  digitalWrite (leftsole1, leftback[0]);
  digitalWrite (leftsole2, leftback[1]);
  digitalWrite (leftsole3, leftback[2]);
  digitalWrite (frontsole1, front[0]);
  digitalWrite (frontsole2, front[1]);
  digitalWrite (frontsole3, front[2]);
  analogWrite(pumppin, pump);
}
