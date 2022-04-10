// intervalTimer 2022 by Erik Dorstel
// published 2022 under GNU GENERAL PUBLIC LICENSE Version 3
//
// This library defines a C++ class which makes it possible to control the call of code parts
// at timed intervals within functions. The Arduino function millis() is required.
//
// Three attributes are used for parameterization:
//
// uint32_t time - The time between two intervals in milliseconds.
// bool active - Activates and deactivates the interval timer.
// int count - The number of cycles. -1 for infinite operation.
//
// The following methods are supported:
//
// constructor - Set nothing, defaults: time 1000; active false; count -1.
// constructor(time) - Set time, defaults: active false; count -1.
// constructor(time,active) - Set time and active, defaults: count -1.
// constructor(time,active,count) - Set time, active and count.
// enable() - Set active to true.
// disable() - Set active to false.
// reset() - The interval time and the repetition counter are set to the start value.
// set(time) - Set time.
// set(time,active) - Set time and active.
// set(time,active,count) - Set time, active and count.
// check() - Checks whether the next interval has been reached. Returns true or false.

#ifndef INTERVAL_TIMER_H
#define INTERVAL_TIMER_H

class intervalTimer {
  public:
    uint32_t timer;
    uint32_t time;
    bool active;
    int counter;
    int count;
    intervalTimer() { timer=millis()+1000; time=1000; active=false; counter=-1; count=-1; }
    intervalTimer(uint32_t value) { timer=millis()+value; time=value; active=false; counter=-1; count=-1; }
    intervalTimer(uint32_t value1,bool value2) { timer=millis()+value1; time=value1; active=value2; counter=-1; count=-1; }
    intervalTimer(uint32_t value1,bool value2,int value3) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; }
    void enable() { active=true; }
    void disable() { active=false; }
    void reset() { timer=millis()+time; counter=count; }
    void set(uint32_t value) { timer=millis()+value; time=value; }
    void set(uint32_t value1,bool value2) { timer=millis()+value1; time=value1; active=value2; }
    void set(uint32_t value1,bool value2,int value3) { timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; }
    bool check() {
      if (millis()>=timer) {
        if (active && counter!=0) {
          if (count>0 && counter>0 ) { counter--; }
          timer=millis()+time; return true; }
        else { return false; } }
      else { return false; } } };

#endif
