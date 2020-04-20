#include <Wire.h>
#include <RTClib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "K155NA1.cpp"
//bring function from associated sketches

extern void update_time_from_gps();
extern void set_zulu();
extern int print_time();
extern void GPS_on();



//define some I/O's & baud rate
#define gps_ss Serial1
static const byte gps_power = 2;
static const byte gps_failure = 8;
static const byte gps_failure13 = 13;
static const byte Zulu_button = 7;
static const uint32_t GPSBaud = 9600;

//define outputs to nixie driver
K155NA1  sec0(46, 42, 40, 44);
K155NA1  sec1(39, 43, 45, 41);
K155NA1  min0(30, 26, 24, 28);
K155NA1  min1(38, 34, 32, 36);
K155NA1 hour0(31, 35, 37, 33);
K155NA1 hour1(23, 27, 29, 25);
//create objects for RTC, GPS serial, and GPS
RTC_DS3231 rtc;
TinyGPSPlus gps;
//SoftwareSerial gps_ss(gps_rx, gps_tx);


// define some variables
DateTime now;
double prev_sec = 0;
int hr;
int time_zone_hr_conversion_input = -5;
int time_zone_hr_conversion = time_zone_hr_conversion_input;
int time_try_gps_update_initial = 300;    //.1 sec * variable
int time_try_gps_update;                  //.1 sec * variable
int time_try_gps_update_reg = 120;        //.1 sec * variable
bool Is_Zulu_Shown = false;

  //for when the gps will sync
int min_to_sync = 45;
int hr_div_to_sync  = 11;                    //will sync when (now.hour % hr_div_to_sync) == 0
//for when gps will turn on to git sat link
int min_to_turn_gps_on = min_to_sync-20;
int hr_div_to_turn_gps_on = hr_div_to_sync;


void setup () 
{ 

  //check that the time for the gps to turn on is >= 0
  if(min_to_turn_gps_on < 0){
    min_to_turn_gps_on = min_to_turn_gps_on + 60;
    hr_div_to_turn_gps_on = hr_div_to_turn_gps_on - 1;
  }
  
  //initalize pins
  pinMode(gps_power, OUTPUT);
  digitalWrite(gps_power, HIGH);
  pinMode(gps_failure, OUTPUT);
  digitalWrite(gps_failure, LOW);
  pinMode(gps_failure13, OUTPUT);
  digitalWrite(gps_failure13, LOW);

  
  
  pinMode(Zulu_button, INPUT);

  //start/initalize serial comms
  rtc.begin();
  Serial.begin(9600);
  gps_ss.begin(GPSBaud);

  delay(3000);

  // attempt to calibrate RTC with GPS
  time_try_gps_update = time_try_gps_update_initial;
  update_time_from_gps();
  time_try_gps_update = time_try_gps_update_reg;


  // wait for console opening when debugging
  delay(3000);
  
  // Check if RTC is there
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}

void loop (){
    now = rtc.now();
    if((now.second() > prev_sec) or ((prev_sec == 59) and (now.second()==0))){
      prev_sec = print_time();
    }
    if(((now.second() == 0) and (now.minute() == min_to_turn_gps_on) and ((now.hour() % hr_div_to_turn_gps_on) == 0))){
      digitalWrite(gps_power, HIGH);
    }
    if((now.second() == 0) and (now.minute() == min_to_sync) and ((now.hour() % hr_div_to_sync) == 0)){
      prev_sec = print_time();
      update_time_from_gps();
    }
    //Zulu/central time button
    if(digitalRead(Zulu_button) == HIGH){
      set_zulu();
    }
  }
