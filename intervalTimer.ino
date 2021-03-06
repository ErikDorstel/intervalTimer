// Example of using the intervalTimer library.

// includes the library header file
#include "intervalTimer.h"

// instantiates the intervalTimer class to exampleOne with the
// default parameters time=1000; active=false; count=-1; call=NULL;
intervalTimer exampleOne;

// instantiates the intervalTimer class to exampleTwo with the
// parameters time=2000; active=true; count=5; call=NULL;
intervalTimer exampleTwo(2000,true,5);

// instantiates the intervalTimer class to exampleThree with the
// default parameters time=1000; active=false; count=-1; call=NULL;
intervalTimer exampleThree;

void doExampleThree() {
  // reset object exampleTwo
  exampleTwo.reset();
  Serial.print("exampleThree"); Serial.print(",");
  Serial.print(exampleThree.timer); Serial.print(",");
  Serial.print(exampleThree.time); Serial.print(",");
  Serial.print(exampleThree.counter); Serial.print(",");
  Serial.print(exampleThree.count); Serial.print("\r\n"); }

void setup() {
  Serial.begin(115200); delay(500);
  // set the object exampleOne attributes to active=true;
  exampleOne.enable();
  // set the object exampleThree attributes to time=20000; active=true; count=-1; call=doExampleThree;
  exampleThree.set(20000,true,-1,doExampleThree); }

void loop() {
  if (exampleOne.check()) {
    Serial.print("exampleOne"); Serial.print(",");
    Serial.print(exampleOne.timer); Serial.print(",");
    Serial.print(exampleOne.time); Serial.print(",");
    Serial.print(exampleOne.counter); Serial.print(",");
    Serial.print(exampleOne.count); Serial.print("\r\n"); }
  if (exampleTwo.check()) {
    Serial.print("exampleTwo"); Serial.print(",");
    Serial.print(exampleTwo.timer); Serial.print(",");
    Serial.print(exampleTwo.time); Serial.print(",");
    Serial.print(exampleTwo.counter); Serial.print(",");
    Serial.print(exampleTwo.count); Serial.print("\r\n"); }
  exampleThree.check(); }
