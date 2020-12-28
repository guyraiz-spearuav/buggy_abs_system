// main function - to run in loop
void wheel_speed_calculation(void); // calculate wheel speed
void readings(void); // read inputs from user
void outputs(void); // output all data to physical components
void abs_pump(void); // abs pump running loop
void solenoids(void); // solenoids running loop


//helper functions - to run when needed
float wheel_speed(long unsigned int, long unsigned int); //wheel speed calculation
void rightwheelping (void); // interrupt for right wheel speed
void leftwheelping (void); // interrupt for left wheel speed
void solenoid_output(int, bool); // for outputing values to solenoids
void solenoids_function(int, const int); //to calculate which solenoids are open/closed


//input pins
const int right_wheel_sensor_pin = 1; // pin for right wheel sensor
const int left_wheel_sensor_pin = 1; // pin for left wheel sensor
const int brake_strength_pin = 1; // pin for brake sensor from lever
const int lock_right_pin = 1; // lock rear right wheel button
const int lock_left_pin = 1; // lock rear left wheel button
const int lock_rear_pin = 1; // lock rear axle wheel button
const int difflock_pin = 1; //difflock enable button


//output pins
const int rear_right_solenoids_pin [3] = {1, 1, 1}; // output pins of solenoids of rear right wheel
const int rear_left_solenoids_pin [3] = {1, 1, 1}; // output pins of solenoids of rear left wheel
const int front_solenoids_pin [3] = {1, 1, 1}; // output pins of solenoids of front wheels
const int pump_pin = 1; //// output pin of abs pump


//tyre and wheel constants
const int TYRE_WIDTH_MM = 90; // width of tyre in mm
const int TYRE_PROFILE_PERCENT = 90; //  tyre profile in percentage of tyre widht
const int RIM_DIAMETER_INCH = 21; // diameter of tyre rim in inches
const int NUMBER_OF_PROBES = 1; // number of wheel speed probes


//base calculation
const int TYRE_CIRCUMFRENCE_MM = (TYRE_WIDTH_MM / 100 * TYRE_PROFILE_PERCENT * 2 + RIM_DIAMETER_INCH * 25.4) * PI; // calculate tyre circumfrence


// constants
const int Right = 0; // for "solenoids_function" helper function
const int Left = 1; // for "solenoids_function" helper function
const int Front = 2; // for "solenoids_function" helper function
const int PWM_MAX_VALUE = 0; // pwm minimum viable value
const int PWM_MIN_VALUE = 255; // pwm maximum viable value
const int WHEEL_SPEED_TIMEOUT_MS = 2500; // if this time passed since a wheel speed sensor pinged, speed will be set as zero m/s


//timers
long unsigned int right_wheel_timer; // timer for rear right wheel speed calculation
long unsigned int previous_right_wheel_timer; // timer for rear right wheel speed calculation
long unsigned int left_wheel_timer; // timer for rear left wheel speed calculation
long unsigned int previous_left_wheel_timer; // timer for rear left wheel speed calculation


//global variables
float right_wheel_speed; // rear right wheel real time speed
float left_wheel_speed; // rear left wheel real time speed
bool run_left_wheel_speed_function; // for rear left wheel speed calculation
bool run_right_wheel_speed_function; // for rear left wheel speed calculation
int rear_right_brake_solenoid_strength; // how many solenoids should be open for rear right brake
int rear_left_brake_solenoid_strength; // how many solenoids should be open for rear left brake
int front_brake_solenoid_strength; // how many solenoids should be open for front brake
int abs_pump_strength; // strength of ABS pump
bool rear_right_solenoids[3]; // for solenoids operation - rear right
bool rear_left_solenoids[3]; // for solenoids operation - rear left
bool front_solenoids[3]; // for solenoids operation - front
int brake_strength_from_lock; // for locking loops operation


//readings
int brake_strength_from_lever; // how strong is the user applying the brake
bool lock_right; // lock the rear right wheel
bool lock_left; // lock the rear left wheel
bool lock_rear; // lock the rear axle
bool difflock; // imitate differential lock


void setup() {
  attachInterrupt(digitalPinToInterrupt(right_wheel_sensor_pin), rightwheelping, RISING); //right wheel speed interrupt
  attachInterrupt(digitalPinToInterrupt(left_wheel_sensor_pin), leftwheelping, RISING); //left wheel speed interrupt
}


void loop() {
  wheel_speed_calculation(); // calculate wheels speeds 
  readings(); // read inputs from user
  solenoids(); // solenoid functions
  abs_pump(); // abs pump functions
  outputs(); // output values to physical elements
}
