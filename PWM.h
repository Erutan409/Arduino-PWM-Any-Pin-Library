#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class PWM {

	public:
		PWM(unsigned short pin);
		PWM &write(unsigned short pwm);
		void run(void);

	private:
		unsigned short _pin;
		unsigned long _last_read;
		unsigned short _pwm;
		unsigned int _compare;
		unsigned long _pwm_increment = 3906;

};

#endif