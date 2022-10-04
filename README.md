# intervalTimer
Arduino millis() based intervalTimer library

This library defines a C++ class which makes it possible to control the call of code parts
within functions or functions at timed intervals. The Arduino function millis() is required.

Five attributes are used for parameterization:

* uint32_t time - The time between two intervals in milliseconds. (default value 1000)
* bool active - Activates and deactivates the interval timer. (default value false)
* uint32_t start - The time after which the first interval starts. (default value 1000)
* int count - The number of cycles. Value infinite for infinite operation. (default value infinite)
* void call - A function pointer to call a specific function. (default nullptr)

The following methods are supported:

* constructor(time,active,start,count,call)
* enable() - Set active to true.
* disable() - Set active to false.
* reset() - The interval time and the cycle counter are set to the start values.
* set(time,active,start,count,call)
* check() - Checks whether the next interval has been reached. Returns true or false. Calls a function if call not nullptr.

### Basic example
Outputs "exampleOne" on the serial interface once per second.

    #include "intervalTimer.h"
    
    void doExampleOne() { Serial.println("exampleOne"); }
    
    intervalTimer exampleOne(1000,true,1000,infinite,doExampleOne);
    
    void setup() { Serial.begin(115200); }
    
    void loop() { exampleOne.check(); }