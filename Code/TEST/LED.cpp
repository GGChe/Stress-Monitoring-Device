#include <wiringPi.h>
int main(void)
{
	wiringPiSetup();
	pinMode(40, OUTPUT);
	for (;;)
	{
		digitalWrite(40, HIGH); delay(500);
		digitalWrite(40, LOW); delay(500);
	}
	return 0;
}