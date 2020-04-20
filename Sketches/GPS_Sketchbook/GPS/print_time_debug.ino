/*

int print_time(){
    // hour
    now = rtc.now();
    hr = now.hour() + time_zone_hr_conversion;
    if(hr < 0){
      hr = hr + 24;
      }
    if(hr > 23){
      hr = hr - 24;
      }

    Serial.print(int(hr/10) % 10);
    Serial.print(int(hr % 10),0);
    Serial.print(':');
    Serial.print(round((now.minute()/10) % 10),0);
    Serial.print(int(round(now.minute() % 10)));
    Serial.print(':');
    Serial.print(int(round((now.second()/10) % 10)));
    Serial.print(int(round(now.second() % 10)));
    Serial.println();


     return now.second(); 
     //prev_time = now.second();
    
}
*/
