# e-lab's ReC generic driver for Arduino

This repository aims to provide the official library of e-lab's ReC for the arduino platform: A tool to control remote experiments within (but not limited to) the e-lab infrastructure. It is written in C++.

##e-lab
[e-lab](http://www.elab.ist.utl.pt) is a remotely controlled laboratory localized at Instituto Superior Técnico (IST) of the University of Lisbon.

This laboratory provides remote control of real physics experiments over the Internet. It’s main purposes are:

- to provide e-learning of science (24 hours per day and 7 days a week), by providing real scientific experiments (remotely controlled ) and the tools needed for the subsequent data analysis ,
- to provide to teachers and professors an auxiliary tool based on information and communication technologies for science,
- to motivate students to learn science by showing them real situations that prove the theory,
- to allow the realization of not so safe experiments (e.g. radioactivity), and
- to provide expensive experiments which can not be acquired by a school or institution. Because of this, e-lab is a free, accessible, remotely controlled laboratory and can be accessed by everyone which has a computer with internet.

##ReC Generic Driver
In the e-lab laboratory, experiments are controlled using the ReC (Remote Experiment Control) Generic Driver, a standard protocol for all experiments. It is based on a state machine with 4 possible states, as well as 4 transition states, where states in bold are **active states**, for which functions shall be defined as explained below.
- **stopping**
- stopped
- **configuring**
- configured
- **starting**
- **started**
- reseting
- reseted

Communication between software (user) and hardware is made through a serial connection. This is handled by the library (baudrate can be changed at `user_define.h`, default 115200).

Information is passed from the computer to the Arduino with standardized *commands*, and from it to the computer in a preformated string - *data*.

The execution of the experiment uses *protocols*. The same apparatus can be runned in different modes, for example an optical apparatus can be used to measure the refraction index of a material or to study Fresnell's equations. In this case the configurations and *data* retrieved would necessarily be different.
> If by now you are not sure of what a protocol means, just stick to protocol 1.
> Protocol 0 is to be used only for presenting help messages or for debug purposes.

###Commands
The software (user) interacts with the following commands:
- `cfg`: configuration string. It accepts a minimum of 2 and a maximum of `NARGUMENTS + 1` arguments. The first argument is always the protocol number. The following `NARGUMENTS` arguments, separated by spaces or `\r` will be stored at `param` vector.

Example for a 3 parameters experiment:
```
cfg 2 45 9 24
```
This command configures the experiment to run protocol number 2 with parameters:

Variable | Value
------------ | -------------
p_run         | 2
expr.param[0] | 45
expr.param[1] | 9
expr.param[2] | 24

> You should not use p_run unless you know what you are doing

> Note that the number of parameters must be the same for all protocols (but not all need to be used)

> Only integer values are accepted. If you are on the need for decimal values, consider modifing the scale (using miliseconds instead of seconds for example)



This commands runs function `configuring()` for the selected protocol.

- `str`: start instruction. After receiving this command the experiment will start executing by running function `starting()` of the selected protocol. No arguments are needed. When this function ends, function `started()` of the selected protocol will start.
- `stp`: stop instruction. After receiving this command the experiment will stop executing by running function `stopping()` of the selected protocol. No arguments are needed.
- `rst`: reset instruction. Normaly not used. No arguments are needed.

###Data
Data is to be sent back in the `started()` function as soon as available (no action required from the user). Data transmission starts with a `DAT\r` and ends with a `END\r`. Data is to be sent in lines. In each line values are separated by a `\t` and end with a `\r`.
Example:
```C

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
```

##Using this library
Simply clone this repository and open the file `e-lab.ino`.
Add the code to the appropriate functions, as described below.

##Adding a new protocol

> Find/Replace all `?` with the protocol number.
>`?` must be a positive integer.
> Do not skip numbers

1) Add a file named `p?.h` according to the following model:
```Cpp
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
2) Change the value of `NPROTOCOLS` in `user_define.h` for the appropriate number (number of diferent protocols used in the experiment).
```
#define NPROTOCOLS ?
```


3) Write the intended code within the following functions:
- `stopping()`
  This function shall include the code needed for the experiment to safely stop.
- `configured()`
  Where the experiment is to become ready for the starting command.
- `starting()`
  Start of the protocol.
- `started()`
  This function starts after starting() has been completed and shall be used for the transmission of data.

> If one of the above functions is to be used in several protocols, consider defining it at `pdefault.h`.
In this case clear the references to this functions at `p?.h`.

4) When you find the code has been fully tested, turn off debug mode at `user_define.h`
```C
#define DEBUG 0 //1 for ON, 0 for OFF
```
