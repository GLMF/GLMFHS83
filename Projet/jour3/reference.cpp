
#include <iostream>
#include <math.h>

void test_reference()
{
	int reponse = 42;
	int &r = reponse;

	reponse /= 2; // r et reponse valent 21
	r += reponse; // r et reponse valent 42
}

double vitesse = 2.0;
double angle = 210;

void incrementer(double &x, double &y)
{
	x += vitesse * cos(angle);
	y += vitesse * sin(angle);
}

void test_incrementer()
{
	double pos_x = 42, pos_y = 34;
	incrementer(pos_x, pos_y);
	std::cout << pos_x << ',' << pos_y << std::endl;
}

int main()
{
	test_reference();
	test_incrementer();
	return 0;
}


