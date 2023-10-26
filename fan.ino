void burn_fan() {
  // the webasto fan runs on 10v so we need to that into account
  int percent_map = mapf(fan_speed, 0, 100, 1000, 1800); // Turn 0-100% into 1000 to 2000uS Pulse

  pulseOut(burn_fan_pin, percent_map);
  //ledcWrite(air_channel, percent_map);
  //pwm.analogWrite(burn_fan_pin, percent_map);
}
void pulseOut(int pin, int us)
{
    digitalWrite(pin, HIGH);
    us = max(us - 5, 1);
    delayMicroseconds(us);
    digitalWrite(pin, LOW);
    delayMicroseconds(20000-us); //Wait until 20ms in total has passed
}
