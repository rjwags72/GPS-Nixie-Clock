
extern void GPS_off();
void update_time_from_gps(){
   //Serial.println("Updating ...");
   bool lights = lights_off();
   bool run_again = true;
   int run_ = 0;
   while(run_again == true){
    run_ = run_ + 1;
      while(gps_ss.available() > 0){
        gps.encode(gps_ss.read());
        if(gps.location.isUpdated()){
           gps.location.lng();
           rtc.adjust(DateTime(gps.date.year(),gps.date.month(),gps.date.day(), gps.time.hour(),gps.time.minute(),gps.time.second()));
           digitalWrite(gps_failure, LOW);
           //Serial.println();
           //Serial.println("Time Update sucessfull");
           GPS_off();
           run_ = time_try_gps_update;
           run_again = false;
           break;
          }
        }
      if(run_again == true){
        delay(100);
        if((run_ % 10) == 0){
          //Serial.print("|");
          if(lights == false){
            lights = lights_on();
            }
          else{
            lights = lights_off();
          }
        }
      }
      if((run_ == time_try_gps_update) and (run_again == true)){
        Serial.println();
        Serial.println("Failed To Update Time");
        digitalWrite(gps_failure, HIGH);
        break;
        
      }
   }
}
bool lights_off(){
   sec0.off();
   sec1.off();
   min0.off();
   min1.off();
   hour0.off();
   hour1.off();
   return false;
}
bool lights_on(){
   sec0.numb(0);
   sec1.numb(0);
   min0.numb(0);
   min1.numb(0);
   hour0.numb(0);
   hour1.numb(0);
   return true;
}
