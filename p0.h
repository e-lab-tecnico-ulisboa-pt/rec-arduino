//Protocol 0 class

//This protocol shall be used for help and/or debug purposes
class P0: public proto {
  public:
//Defining stopping function is opcional, as it has already been defined
//Defining it here will override the default only for this protocol
//A similar approach can be used with configuring(), starting() and started()
/*
    void stopping() {
      if(DEBUG) Serial.println("0stopping");
    }
*/
    void configuring() { 
      if(DEBUG) Serial.println("0configuring");
    }

    void starting() {
      if(DEBUG) Serial.println("0starting");
    }

    void started() {
      if(DEBUG) Serial.println("0started");
    }
};

extern P0 PP0;
