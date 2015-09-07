//Protocol 1 class


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
    }
} PP1;
