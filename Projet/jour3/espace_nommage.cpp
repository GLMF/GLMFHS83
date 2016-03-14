#include <iostream>

namespace balle
{
	double centre_x = 50, centre_y = 0;
	int rayon = 5;

	void deplacer(double x, double y)
	{
		centre_x += x;
		centre_y += y;
	}

	void afficher()
	{
		std::cout << "<Balle (" << centre_x << ", " << centre_y << ")>" << std::endl;
	}
}

void test_balle()
{
	balle::afficher();
	balle::deplacer(1.2, 3);
	balle::afficher();
}

namespace chose {
	namespace truc {
		int machin = 42;
	}
}

void test_namespaces()
{
	std::cout << "machin=" << chose::truc::machin << std::endl;
}


int main()
{
	test_balle();
	test_namespaces();
	return 0;
}
