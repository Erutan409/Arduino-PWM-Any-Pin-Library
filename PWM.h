#ifndef PWM_H
#define PWM_H

#include <Arduino.h>
#include <Avail.h>

enum PWM_Mode {
	PWM_High = HIGH
	,PWM_Low = LOW
};

class PWM {

	public:
		PWM(uint8_t pin);
		PWM &mode(PWM_Mode mode);
		PWM_Mode *getMode(void);
		PWM &write(uint8_t pwm);
		void run(void);

	private:
		uint8_t _pin;
		uint32_t _lastAction = micros();
		uint8_t _pwm = 0;
		PWM_Mode _mode = PWM_High;
		bool _state = false;

};

#endif