#include "rec.h"
#include "user_define.h"

//Default stopping function for every protocol where it's not defined
void proto::stopping(){
  if(DEBUG) Serial.println("stopping");
  ;
}


//Protocol 0 class
class P0: public proto {
  public:
//Defining stopping function is opcional, as it has already been defined
//Defining it here will override the default for this protocol
//A similar approach can be used with configuring(), starting() and started()
/*
    void stopping() {
      if(DEBUG) Serial.println("0stopping");
      ;
    }
*/
    void configuring() {
      if(DEBUG) Serial.println("0configuring");
      ;
    }

    void starting() {
      if(DEBUG) Serial.println("0starting");
      ;
    }

    void started() {
      if(DEBUG) Serial.println("0started");
      ;
    }
} PP0;

//Protocol 1 class
class P1: public proto {
  public:
//Defining stopping function is opcional, as it has already been defined
//Defining it here will override the default for this protocol
//A similar approach can be used with configuring(), starting() and started()
/*
    void stopping() {
      if(DEBUG) Serial.println("1stopping");
      ;
    }
*/

    void configuring() {
      if(DEBUG) Serial.println("1configuring");
      ;
    }

    void starting() {
      if(DEBUG) Serial.println("1starting");
      ;
    }

    void started() {
      if(DEBUG) Serial.println("1started");
      ;
    }
} PP1;


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

