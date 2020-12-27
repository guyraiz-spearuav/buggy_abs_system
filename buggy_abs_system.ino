// main function - to run in loop
void wheel_speed_calculation(void);
void readings(void);
void outputs(void);
void abs_pump(void);
void solenoids(void);


//side functions - to run when needed
float wheel_speed(long unsigned int, long unsigned int);
void rightwheelping (void);
void leftwheelping (void);
void solenoid_output(int, bool);
void solenoids_function(const int, int);


//input pins
const int right_wheel_sensor_pin = 1;
const int left_wheel_sensor_pin = 1;
const int brake_strength_pin = 1;
const int lock_right_pin = 1;
const int lock_left_pin = 1;
const int lock_rear_pin = 1;
const int difflock_pin = 1;


//output pins
const int rear_right_solenoids_pin [3] = {1, 1, 1};
const int rear_left_solenoids_pin [3] = {1, 1, 1};
const int front_solenoids_pin [3] = {1, 1, 1};
const int pump_pin = 1;


//tyre and wheel constants
const int TYRE_WIDTH_MM = 90;
const int TYRE_PROFILE_PERCENT = 90;
const int RIM_DIAMETER_INCH = 21;
const int NUMBER_OF_PROBES = 1;


//base calculation
const int TYRE_CIRCUMFRENCE_MM = (TYRE_WIDTH_MM / 100 * TYRE_PROFILE_PERCENT * 2 + RIM_DIAMETER_INCH * 25.4) * PI;


// constants
const int Right = 0;
const int Left = 1;
const int Front = 2;
const int PWM_MAX_VALUE = 0;
const int PWM_MIN_VALUE = 255;
const int WHEEL_SPEED_TIMEOUT_MS = 2500;


//timers
long unsigned int right_wheel_timer;
long unsigned int previous_right_wheel_timer;
long unsigned int left_wheel_timer;
long unsigned int previous_left_wheel_timer;


//global variables
float right_wheel_speed;
float left_wheel_speed;
bool run_left_wheel_speed_function;
bool run_right_wheel_speed_function;
int rear_right_brake_solenoid_strength;
int rear_left_brake_solenoid_strength;
int front_brake_solenoid_strength;
int abs_pump_strength;
bool rear_right_solenoids[3];
bool rear_left_solenoids[3];
bool front_solenoids[3];
int brake_strength_from_lock;


//readings
int brake_strength_from_lever;
bool lock_right;
bool lock_left;
bool lock_rear;
bool difflock;


void setup() {
  attachInterrupt(digitalPinToInterrupt(right_wheel_sensor_pin), rightwheelping, RISING); //right wheel speed interrupt
  attachInterrupt(digitalPinToInterrupt(left_wheel_sensor_pin), leftwheelping, RISING); //left wheel speed interrupt
}


void loop() {
  wheel_speed_calculation();
  readings();
  solenoids();
  abs_pump();
  outputs();
}
