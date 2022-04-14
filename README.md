# intervalTimer
Arduino millis() based intervalTimer library

This library defines a C++ class which makes it possible to control the call of code parts
within functions or functions at timed intervals. The Arduino function millis() is required.

Four attributes are used for parameterization:

* uint32_t time - The time between two intervals in milliseconds. (default value 1000)
* bool active - Activates and deactivates the interval timer. (default value false)
* int count - The number of cycles. -1 for infinite operation. (default value -1)
* void call - A function pointer to call a specific function. (default value NULL)

The following methods are supported:

* constructor - Set nothing, all parameters are set to default.
* constructor(time) - Set time.
* constructor(time,active) - Set time and active.
* constructor(time,active,count) - Set time, active and count.
* constructor(time,active,count,call) - Set time, active, count and call.
* enable() - Set active to true.
* disable() - Set active to false.
* reset() - The interval time and the cycle counter are set to the start value.
* set(time) - Set time.
* set(time,active) - Set time and active.
* set(time,active,count) - Set time, active and count.
* set(time,active,count,call) - Set time, active, count and call.
* check() - Checks whether the next interval has been reached. Returns true or false. Calls a function if call parameter not NULL.

### Basic example
Outputs "exampleOne" on the serial interface once per second.

    #include "intervalTimer.h"
    
    void doExampleOne() { Serial.println("exampleOne"); }
    
    intervalTimer exampleOne(1000,true,-1,doExampleOne);
    
    void setup() { Serial.begin(115200); }
    
    void loop() { exampleOne.check(); }