#include "rec.h"
#include "user_define.h"

#include "p0.h"
#include "p1.h"

P0 PP0;
P1 PP1;

//Default stopping function for every protocol where it's not defined
void proto::stopping(){
  if(DEBUG) Serial.println("default_stopping");
}


void setup() {
  expr.begin("ELAB_LED_ARDUINO_V1.0");
  
  //For every protocol a line similar to the ones above must be added
  //Do not forget to change NARGUMENTS and NPROTOCOLS at user_define.h
  expr.protocol[0] = &PP0;
  expr.protocol[1] = &PP1;
  
}

void loop() {
  expr.state_machine();
}

