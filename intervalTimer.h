// intervalTimer 2022 by Erik Dorstel
// published 2022 under GNU GENERAL PUBLIC LICENSE Version 3
// https://github.com/ErikDorstel/intervalTimer
//
// This library defines a C++ class which makes it possible to control the call of code parts
// within functions or functions at timed intervals. The Arduino function millis() is required.
//
// Four attributes are used for parameterization:
//
// * uint32_t time - The time between two intervals in milliseconds. (default value 1000)
// * bool active - Activates and deactivates the interval timer. (default value false)
// * int count - The number of cycles. -1 for infinite operation. (default value -1)
// * void call - A function pointer to call a specific function. (default value false)
//
// The following methods are supported:
//
// * constructor - Set nothing, all parameters are set to default.
// * constructor(time) - Set time.
// * constructor(time,active) - Set time and active.
// * constructor(time,active,count) - Set time, active and count.
// * constructor(time,active,count,call) - Set time, active, count and call.
// * enable() - Set active to true.
// * disable() - Set active to false.
// * reset() - The interval time and the cycle counter are set to the start value.
// * set(time) - Set time.
// * set(time,active) - Set time and active.
// * set(time,active,count) - Set time, active and count.
// * set(time,active,count,call) - Set time, active, count and call.
// * check() - Checks whether the next interval has been reached. Returns true or false. Calls a function if call parameter not false.

#ifndef INTERVAL_TIMER_H
#define INTERVAL_TIMER_H

class intervalTimer {
  public:
    uint32_t timer=1000;
    uint32_t time=1000;
    bool active=false;
    int counter=-1;
    int count=-1;
    void (*call)(void)=false;
    intervalTimer() { }
    intervalTimer(uint32_t value1) { timer=millis()+value1; time=value1; }
    intervalTimer(uint32_t value1,bool value2) { timer=millis()+value1; time=value1; active=value2; }
    intervalTimer(uint32_t value1,bool value2,int value3) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; }
    intervalTimer(uint32_t value1,bool value2,int value3,void (*value4)(void)) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; call=value4; }
    void enable() { active=true; }
    void disable() { active=false; }
    void reset() { timer=millis()+time; counter=count; }
    void set(uint32_t value1) { timer=millis()+value1; time=value1; }
    void set(uint32_t value1,bool value2) { timer=millis()+value1; time=value1; active=value2; }
    void set(uint32_t value1,bool value2,int value3) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; }
    void set(uint32_t value1,bool value2,int value3,void (*value4)(void)) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; call=value4; }
    bool check() {
      if (millis()>=timer) {
        if (active && counter!=0) {
          if (count>0 && counter>0) { counter--; }
          timer=millis()+time; if (call) { call(); } return true; }
        else { return false; } }
      else { return false; } } };

#endif