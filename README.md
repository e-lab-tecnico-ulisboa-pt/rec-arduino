# e-lab's ReC for arduino

This repository aims to provide the official library of e-lab's ReC for the arduino platform: A tool to control remote experiments within (but not limited to) the e-lab infrastructure. It is written in C++.

##e-lab
[e-lab](http://www.elab.ist.utl.pt) is a remotely controlled laboratory localized at Instituto Superior Técnico (IST) of the University of Lisbon.

This laboratory provides remote control of real physics experiments over the Internet. It’s main purposes are:

- to provide e-learning of science (24 hours per day and 7 days a week), by providing real scientific experiments (remotely controlled ) and the tools needed for the subsequent data analysis ,
- to provide to teachers and professors an auxiliary tool based on information and communication technologies for science,
- to motivate students to learn science by showing them real situations that prove the theory,
- to allow the realization of not so safe experiments (e.g. radioactivity), and
- to provide expensive experiments which can not be acquired by a school or institution. Because of this, e-lab is a free, accessible, remotely controlled laboratory and can be accessed by everyone which has a computer with internet.

##Rec Generic Driver
In the e-lab laboratory, experiments are controlled using the ReC (Remote Experiment Control) Generic Driver, a standard protocol for all experiments. It is based on a state machine with 4 possible states, as well as 4 transition states, where states in **bold** are active states, for which functions shall be defined as explained below.
- **stopping**
- stopped
- **configuring**
- configured
- **starting**
- **started**
- reseting
- reseted

Communication between software (user) and hardware is made through a serial connection. This is handled by the library (baudrate can be changed at `user_define.h`, default 115200). The software (user) interacts with the following commands:
- `cfg`: configuration string. It accepts a minimum of 2 and a maximum of `NPROTOCOLS + 1`. The first argument is always the protocol number.


Example for a 3 parameters experiment:
```
cfg 2 45 9 24
```
This command configures the experiment to run protocol number 2 with parameters param[0] = 45, param[1] = 9, param[2] = 24.
> Note that the number of parameters must be the same for all protocols (but not all need to be used)





##Using the library
Simply clone this repository and open the file `e-lab.ino`.

##Adding a new protocol
(Replace ? with the protocol number)

1) Add a file named `p?.h` according to the following model 
```
//Protocol ? class


//Defining every function is opcional, as they can be defined as common for all protocols
//Defining them here will override the default only for this protocol

extern class P?: public proto {
  public:
    void stopping() {
      if (DEBUG) Serial.println("?_stopping");
    }

    void configuring() {
      if (DEBUG) Serial.println("?_configuring");
    }

    void starting() {
      if (DEBUG) Serial.println("?_starting");
    }

    void started() {
      if (DEBUG) Serial.println("?_started");
    }
} PP?;
```
2) Change the value of NPROTOCOLS in `user_define.h` for the appropriate number
```
#define NPROTOCOLS ?
```


3) Write the intended code within
- `stopping()`
- `configured()`
- `starting()`
- `started()`

If one of the above functions is to be used in several protocols, consider defining it at `pdefault.h`.
In this case clear the references to this functions at `p?.h`.
