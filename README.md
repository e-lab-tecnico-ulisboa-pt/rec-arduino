# e-lab's REC for arduino

This repository aims to provide the official library of e-lab's REC for the arduino platform: A tool to control remote experiments within (but not limited to) the e-lab infrastructure. It is written in C++.

##e-lab
e-lab http://www.elab.ist.utl.pt is a remotely controlled laboratory localized at Instituto Superior Técnico (IST) of the University of Lisbon.

This laboratory provides remote control of real physics experiments over the Internet. It’s main purposes are:

- to provide e-learning of science (24 hours per day and 7 days a week), by providing real scientific experiments (remotely controlled ) and the tools needed for the subsequent data analysis ,
- to provide to teachers and professors an auxiliary tool based on information and communication technologies for science,
- to motivate students to learn science by showing them real situations that prove the theory,
- to allow the realization of not so safe experiments (e.g. radioactivity), and
- to provide expensive experiments which can not be acquired by a school or institution. Because of this, e-lab is a free, accessible, remotely controlled laboratory and can be accessed by everyone which has a computer with internet.

##Adding a protocol
(Replace ? with the protocol number)

file p?.h
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
