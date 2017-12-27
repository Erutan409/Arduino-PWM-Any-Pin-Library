# Arduino PWM Any Pin Library

Please note that this library uses [Arduino Avail](https://github.com/Erutan409/Arduino-Avail)

Usage example:
```c++
// Fade the built-in LED on pin 13

#include <PWM.h>

#define LED 13

PWM led(LED);

void setup()
{

}

void loop()
{
	ledController();
}

void ledController(void) {
	static uint32_t last = millis();
	static uint8_t pwm = 0;
	static bool direction;

	uint32_t diff = 2;
	
	if (Avail::millis(&diff, &last)) {
		last = millis();

		if (pwm == 0) {
			direction = true;
		} else if (pwm == 255) {
			direction = false;
		}

		if (direction) {
			led.write(++pwm);
		} else {
			led.write(--pwm);
		}
	}

	led.run();
}
```