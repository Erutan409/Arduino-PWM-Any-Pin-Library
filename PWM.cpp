#include <PWM.h>
#include <math.h>

PWM::PWM(uint8_t pin) {
	this->_pin = pin;
	pinMode(this->_pin, OUTPUT);
	this->_lastAction = micros();
}

PWM &PWM::mode(PWM_Mode mode) {
	this->_mode = mode;

	return *this;
}

PWM_Mode *PWM::getMode(void) {
	return &this->_mode;
}

PWM &PWM::write(uint8_t pwm) {
	this->_pwm = pwm;

	return *this;
}

void PWM::run(void) {
	uint8_t &pwm = this->_pwm;
	bool &state = this->_state;
	uint32_t &last = this->_lastAction;
	uint8_t &pin = this->_pin;
	PWM_Mode &mode = this->_mode;

	uint32_t width = round((float)(pwm * 7.8125));
	uint32_t inverse = 0x7D0 - width;

	if (!state && pwm > 0 && Avail::micros(&inverse, &last)) {
		last = micros();
		state = true;
		digitalWrite(pin, mode);
	} else if (state && pwm < 255 && Avail::micros(&width, &last)) {
		last = micros();
		state = false;
		digitalWrite(pin, !mode);
	} else if (!state && pwm == 255) { // left potential bug in code that could trigger on rollover
		state = true;
		digitalWrite(pin, mode);
	} else if (state && pwm == 0) { // left potential bug in code that could trigger on rollover
		state = false;
		digitalWrite(pin, !mode);
	}
}