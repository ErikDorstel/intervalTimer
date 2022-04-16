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
// * void call - A function pointer to call a specific function. (default nullptr)
//
// The following methods are supported:
//
// * constructor(time,active,count,call)
// * enable() - Set active to true.
// * disable() - Set active to false.
// * reset() - The interval time and the cycle counter are set to the start value.
// * set(time,active,count,call)
// * check() - Checks whether the next interval has been reached. Returns true or false. Calls a function if call not nullptr.

#ifndef INTERVAL_TIMER_H
#define INTERVAL_TIMER_H

class intervalTimer {
  public:
    uint32_t timer=1000;
    uint32_t time=1000;
    bool active=false;
    int counter=-1;
    int count=-1;
    void (*call)(void)=nullptr;

    intervalTimer(uint32_t value1=1000,bool value2=false,int value3=-1,void (*value4)(void)=nullptr) {
      timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; call=value4; }

    void set(uint32_t value1=1000,bool value2=false,int value3=-1,void (*value4)(void)=nullptr) {
      timer=millis()+value1; time=value1; active=value2; counter=value3; count=value3; call=value4; }

    void enable() { active=true; }
    void disable() { active=false; }

    void reset() { timer=millis()+time; counter=count; }

    bool check() {
      if (millis()>=timer) {
        if (active && counter!=0) {
          if (count>0 && counter>0) { counter--; }
          timer=millis()+time; if (call!=nullptr) { call(); } return true; }
        else { return false; } }
      else { return false; } } };

#endif
