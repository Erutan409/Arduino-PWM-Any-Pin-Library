#ifndef PWM_H
#define PWM_H

#include <Arduino.h>
#include <Avail.h>

typedef unsigned char uint24_t[3];

class PWM {

	public:
		PWM(uint8_t pin);
		PWM &mode(uint8_t mode);
		PWM &write(uint8_t pwm);
		void run(void);

	private:
		uint8_t _pin;
		uint32_t _lastAction = micros();
		uint8_t _pwm = 0;
		bool _state = false;

};

#endif