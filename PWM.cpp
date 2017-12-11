#include <PWM.h>
#include <Arduino.h>

PWM::PWM(unsigned short pin) {
	this->_pin = pin;
	this->_last_read = micros();
}

PWM &PWM::write(unsigned short pwm) {
	if (pwm > 255) { pwm = 255; }
	this->_pwm = pwm;
	this->_compare = this->_pwm * this->_pwm_increment;
	digitalWrite(this->_pin, LOW);
	this->_last_read = micros();

	return *this;
}

void PWM::run(void) {

	unsigned short *pin = &this->_pin;

	switch (this->_pwm) {

	case 255:
		digitalWrite(*pin, HIGH);
		return;

	case 0:
		digitalWrite(*pin, LOW);
		break;

	default:
		// approximately 3906 microseconds for each pwm
		if ((this->last_read + this->_compare) <= micros()) {
			digitalWrite();
		}

	}

}