> This is a brief description of this repository. Please refer to the [Wiki](../../wiki) for more detailed documentation.

# e-lab's ReC generic driver for Arduino

This repository aims to provide the official library of e-lab's ReC for the arduino platform: A tool to control remote experiments within (but not limited to) the e-lab infrastructure, written in C++.

##e-lab
[e-lab](http://www.elab.ist.utl.pt) is a remotely controlled laboratory localized at Instituto Superior Técnico (IST) of the University of Lisbon.

This laboratory provides remote control of real physics experiments over the Internet. 

##ReC Generic Driver
In the e-lab laboratory, experiments are controlled using the ReC (Remote Experiment Control) Generic Driver, a standard protocol for all experiments. It is based on a state machine with 4 possible states, as well as 4 transition states.
Communication between software (user) and hardware is made through a serial connection, handled by the library.

Information is passed from the computer to the Arduino with standardized *commands*, and from it to the computer in a preformated string - *data*. The execution of the experiment uses *protocols*.

Please refer to the [Wiki](../../wiki) for more detailed documentation.
