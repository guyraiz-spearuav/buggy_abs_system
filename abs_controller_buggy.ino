#define rightwheelpin 2 // pin to interrupt for right wheel speed
#define leftwheelpin 3 // pin to interrupt for left wheel speed
#define tirediameter 20 // in inches
#define pings 1 // number of pings expected for a single revolution
#define mindelta 3 //minimum speed delta between right and left wheels to initiate compensation
#define rightsole1 4 //pin for 1st right solenoid
#define rightsole2 5 //pin for 2nd right solenoid
#define rightsole3 6 //pin for 3rd right solenoid
#define leftsole1 7 //pin for 1st left solenoid
#define leftsole2 8 //pin for 2nd left solenoid
#define leftsole3 9 //pin for 3rd left solenoid
#define frontsole1 10 //pin for 1st front solenoid
#define frontsole2 11 //pin for 2nd front solenoid
#define frontsole3 12 //pin for 3rd front solenoid
#define pumppin 13 //pin for pump
#define difflockpin 14 //pin for diff lock button
#define rearlockpin 15 //pin for diff lock button


bool rightback[3]; //solenoids for rear right brake
bool leftback[3];  //solenoids for rear left brake
bool front[3];   //solenoids for fornt brakes
// solenoids are open while booleans are LOW
int pump; // abs pump pwm value
bool difflock; // store if difflock is on or off
bool rearlock; // store if rearlock is on or off

const float tirecircumfrence = tirediameter * 0.0254 * PI; // calculates tire circumfrence
long unsigned int rightwheeltimer; // timer for calculating right wheel speed
long unsigned int leftwheeltimer; // timer for calculating left wheel speed
float rightmps; // right wheel speed
float leftmps; // left wheel speed
float speeddelta; //speed difference between rear wheels
void setup() {
  attachInterrupt(digitalPinToInterrupt(rightwheelpin), rightwheelspeed, RISING); //right wheel speed interrupt
  attachInterrupt(digitalPinToInterrupt(leftwheelpin), leftwheelspeed, RISING); //left wheel speed interrupt
}

void loop() {
  difflock = digitalRead (difflockpin);
  rearlock = digitalRead (rearlockpin);
  if (difflock) {
    speeddelta = rightmps - leftmps; //calculate speed difference between right and left wheels. negative values are left faster than right
    // negative values are left faster than right
    if (speeddelta > mindelta) { // enable braking only on right wheel
      brakeright();
    }
    if (speeddelta < -mindelta) { // enable braking only on left wheel
      brakeleft();
    }
    if (speeddelta > -mindelta && speeddelta < mindelta) {
      nobrake();
    }
    pumpcalc();
    control();
  }

}


void rightwheelspeed () {
  int delta = millis() - rightwheeltimer; // calculate time delta from previous ping
  float rps = 1000 / delta / pings; //calculate revolution per second
  rightmps = rps * tirecircumfrence; //calculate speed in meters/second
  rightwheeltimer = millis(); //zero the delta
}

void leftwheelspeed () {
  int delta = millis() - leftwheeltimer; // calculate time delta from previous ping
  float rps = 1000 / delta / pings; //calculate revolution per second
  leftmps = rps * tirecircumfrence; //calculate speed in meters/second
  leftwheeltimer = millis(); //zero the delta
}
