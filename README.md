# intervalTimer
Arduino millis() based intervalTimer library

This library defines a C++ class which makes it possible to control the call of code parts
at timed intervals within functions. The Arduino function millis() is required.

Three attributes are used for parameterization:

* uint32_t time - The time between two intervals in milliseconds.
* bool active - Activates and deactivates the interval timer.
* int count - The number of cycles. -1 for infinite operation.

The following methods are supported:

* constructor - Set nothing, defaults: time 1000; active false; count -1.
* constructor(time) - Set time, defaults: active false; count -1.
* constructor(time,active) - Set time and active, defaults: count -1.
* constructor(time,active,count) - Set time, active and count.
* enable() - Set active to true.
* disable() - Set active to false.
* reset() - The interval time and the repetition counter are set to the start value.
* set(time) - Set time.
* set(time,active) - Set time and active.
* set(time,active,count) - Set time, active and count.
* check() - Checks whether the next interval has been reached. Returns true or false.
