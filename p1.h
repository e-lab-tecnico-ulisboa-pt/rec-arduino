//Protocol 1 class
#include "rec.h"

//Defining every function is opcional, as they can be defined as common for all protocols
//Defining them here will override the default only for this protocol

extern class P1: public proto {
  public:
    void stopping() {
      if (DEBUG) Serial.println("1_stopping");
    }

    void configuring() {
      if (DEBUG) Serial.println("1_configuring");
    }

    void starting() {
      if (DEBUG) Serial.println("1_starting");
    }

    void started() {
      if (DEBUG) Serial.println("1_started");

      //Begin data transmission
      Serial.print("DAT\r");
      if (DEBUG) Serial.println("\n");

      //New line of data
      Serial.print(1);
      Serial.print("\t");
      Serial.print(2);
      Serial.print("\t");
      //...
      Serial.print(101);
      Serial.print("\r");
      if (DEBUG) Serial.println("\n");
      //end of data line (multiple lines can be added here


      //End data transmission
      Serial.print("END\r");
      if (DEBUG) Serial.println("\n");

    }
} PP1;
