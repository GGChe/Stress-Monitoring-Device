#include <unistd.h>	
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <iostream>
#include "stressControl1_1.h"
using namespace std;

int main()
{
	std::cout << "Hello World!\n";
	// data buffer
	char buf[2];
	// open the I2C device (check with "ls -l/ dev/i2c*")
	int file = open("/dev/i2c-2", O_RDWR);
	// tell the kernel which I2C address it is
	int addr = 0x58;
	ioctl(file, I2C_SLAVE, addr);
	// read two bytes
	read(file, buf, 2);
	cout << (int)buf << "skjh" << endl;
	std::cout << "Hello World!\n";
	// write one byte
	write(file, buf, 1);
	return 0;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
