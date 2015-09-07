//Protocol 0 class
//This protocol shall be used for help and/or debug purposes

//Defining every function is opcional, as they can be defined as common for all protocols
//Defining them here will override the default only for this protocol

extern class P0: public proto {
  public:
    void stopping() {
      if (DEBUG) Serial.println("0_stopping");
    }

    void configuring() {
      if (DEBUG) Serial.println("0_configuring");
    }

    void starting() {
      if (DEBUG) Serial.println("0_starting");
    }

    void started() {
      if (DEBUG) Serial.println("0_started");
    }
} PP0;
