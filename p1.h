//Protocol 1 class
class P1: public proto {
  public:
//Defining stopping function is opcional, as it has already been defined
//Defining it here will override the default for this protocol
//A similar approach can be used with configuring(), starting() and started()
/*
    void stopping() {
      if(DEBUG) Serial.println("1stopping");
    }
*/
    void configuring() {
      if(DEBUG) Serial.println("1configuring");
    }

    void starting() {
      if(DEBUG) Serial.println("1starting");
    }

    void started() {
      if(DEBUG) Serial.println("1started");
    }
};

extern P1 PP1;
