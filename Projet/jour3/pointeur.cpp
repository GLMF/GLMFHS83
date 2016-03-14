
#include <iostream>
#include <math.h>

using namespace std;

void test_pointeurs()
{
	int tableau[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = tableau;

	cout << p << endl;
	*p += 42;
	++p;
	cout << p << endl;
	*p += 33;
	p += 2;
	cout << p << endl;
	*p += 51;
	*(p+2) = 68;

	for (int i=0; i<10; ++i)
	{
		cout << ' ' << tableau[i];
	}

	cout << endl;
	double tableau2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	double *p2 = tableau2;

	cout << p2 << endl;
	*p2 += 42;
	++p2;
	cout << p2 << endl;
	*p2 += 33;
	p2 += 2;
	cout << p2 << endl;
	*p2 += 51;
	*(p2+2) = 68;

	for (int i=0; i<10; ++i)
	{
		cout << ' ' << tableau2[i];
	}
}


double vitesse = 2.0;
double angle = 210;

void deplacer(double x,  double y)
{
	x += vitesse * cos(angle);
	y += vitesse * sin(angle);
}

void test_deplacer()
{
	double pos_x = 42, pos_y = 34;
	deplacer(pos_x, pos_y);
	std::cout << pos_x << ',' << pos_y << std::endl;
}

void incrementer(int *x, int *y)
{
	*x += vitesse * cos(angle);
	*y += vitesse * sin(angle);
}

void test_incrementer()
{
	int pos_x = 42, pos_y = 34;
	incrementer(&pos_x, &pos_y);
	std::cout << pos_x << ',' << pos_y << std::endl;
}

int main()
{
	test_pointeurs();
	test_deplacer();
	test_incrementer();
	return 0;
}



