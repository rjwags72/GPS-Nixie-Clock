
int print_time(){
    // hour
    hr = now.hour() + time_zone_hr_conversion;
    if(hr < 0){
      hr = hr + 24;
      }
    if(hr > 23){
      hr = hr - 24;
      }

    hour0.numb(int(hr/10) % 10);
    //Serial.print(int(hr/10) % 10);
    //Serial.print(int(hr % 10),0);
    hour1.numb(int(round(hr % 10)));
    //Serial.print(':');
    min0.numb(int(round((now.minute()/10) % 10)));
    //Serial.print(round((now.minute()/10) % 10),0);
    min1.numb(int(round(now.minute() % 10)));
    //Serial.print(int(round(now.minute() % 10)));
    //Serial.print(':');
    sec0.numb(int(round((now.second()/10) % 10)));
    //Serial.print(int(round((now.second()/10) % 10)));
    sec1.numb(int(round(now.second() % 10)));
    //Serial.print(int(round(now.second() % 10)));
    //Serial.println();


     return now.second(); 
     //prev_time = now.second();
    
}
