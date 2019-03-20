#include "wiringPi.h"
int main(void)
{
	wiringPiSetup();
	pinMode(28, OUTPUT);
	for (int i=0;i<10000;i++)
	{
		digitalWrite(28, HIGH); delay(500);
		digitalWrite(28, LOW); delay(500);
	}
	return 0;
}
