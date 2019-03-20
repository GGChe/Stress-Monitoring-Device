#include <wiringPi.h>
int main(void)
{
	wiringPiSetup();
	pinMode(37, OUTPUT);
	for (;;)
	{
		digitalWrite(37, HIGH); delay(500);
		digitalWrite(37, LOW); delay(500);
	}
	return 0;
}