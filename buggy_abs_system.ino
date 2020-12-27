void wheel_speed_calculation(void);


float wheel_speed(long unsigned int, long unsigned int);
void rightwheelping (void);
void leftwheelping (void);

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


//timers
long unsigned int right_wheel_timer;
long unsigned int previous_right_wheel_timer;
long unsigned int left_wheel_timer;
long unsigned int previous_left_wheel_timer;


float right_wheel_speed;
float left_wheel_speed;
bool run_left_wheel_speed_function;
bool run_right_wheel_speed_function;



//bool rightback[3]; //solenoids for rear right brake
//bool leftback[3];  //solenoids for rear left brake
//bool front[3];   //solenoids for fornt brakes
//// solenoids are open while booleans are LOW
//int pump; // abs pump pwm value
//bool difflock; // store if difflock is on or off
//bool rearlock; // store if rearlock is on or off
//
//const float tirecircumfrence = tirediameter * 0.0254 * PI; // calculates tire circumfrence
//long unsigned int rightwheeltimer; // timer for calculating right wheel speed
//long unsigned int leftwheeltimer; // timer for calculating left wheel speed
//float rightmps; // right wheel speed
//float leftmps; // left wheel speed
//float speeddelta; //speed difference between rear wheels
void setup() {
  attachInterrupt(digitalPinToInterrupt(rightwheelpin), rightwheelping, RISING); //right wheel speed interrupt
  attachInterrupt(digitalPinToInterrupt(leftwheelpin), leftwheelping, RISING); //left wheel speed interrupt
}

void loop() {
  wheel_speed_calculation;
}
