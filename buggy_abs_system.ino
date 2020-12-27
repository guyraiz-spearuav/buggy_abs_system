float wheel_speed(long unsigned int, long unsigned int);

//input pins
const int right_wheel_sensor_pin = 2;
const int left_wheel_sensor_pin = 3;


//output pins
const int right_solenoids_pin [3] = {4, 5, 6};
const int left_solenoids_pin [3] = {7, 8, 9};
const int front_solenoids_pin [3] = {10, 11, 12};
const int pump_pin = 13;


//tyre dimensions
const int TYRE_WIDTH_MM = 90;
const int TYRE_PROFILE_PERCENT = 90;
const int RIM_DIAMETER_INCH = 21;


//base calculation
const int TYRE_CIRCUMFRENCE_MM = (TYRE_WIDTH_MM / 100 * TYRE_PROFILE_PERCENT * 2 + RIM_DIAMETER_INCH * 25.4) * PI;



long unsigned int right_wheel_timer;
long unsigned int previous_right_wheel_timer;
long unsigned int left_wheel_timer;
long unsigned int previous_left_wheel_timer;


#define rightwheelpin 1 // in inches
#define leftwheelpin 2 // in inches
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
  attachInterrupt(digitalPinToInterrupt(rightwheelpin), rightwheelping, RISING); //right wheel speed interrupt
  attachInterrupt(digitalPinToInterrupt(leftwheelpin), leftwheelping, RISING); //left wheel speed interrupt
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


void rightwheelping () {
  previous_right_wheel_timer = right_wheel_timer;
  right_wheel_timer = millis();
}

void leftwheelping () {
  previous_left_wheel_timer = right_wheel_timer;
  left_wheel_timer = millis();
}
