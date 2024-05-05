#include <iostream>
#include "Jetski.h"

using namespace std;

int main()
{
	Jetski enemigo1;
	enemigo1.setspeed(500);
	enemigo1.setdistance(22);
	enemigo1.setnitro(1);
	enemigo1.setName("Javi");
	enemigo1.getParameters();

	Jetski enemigo2 =
		Jetski(1000, 50, "Adria");
	enemigo2.getParameters();

	Jetski enemigo3 = Jetski();
	enemigo3.getParameters();
}