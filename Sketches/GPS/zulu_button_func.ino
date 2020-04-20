void set_zulu(){
  if(Is_Zulu_Shown == false){
       time_zone_hr_conversion = 0;
       Is_Zulu_Shown = true;
        }
      else{
        Is_Zulu_Shown = false;
        time_zone_hr_conversion = time_zone_hr_conversion_input;
      }
  delay(400);
  }
