#include <iostream>

namespace univers {
    namespace question {
        int reponse = 42;
    }
}

namespace balle {
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

namespace
{

    void test()
    {
        std::cout << "LA réponse = " << univers::question::reponse << std::endl;

        balle::afficher();
        balle::deplacer(1.2, 3);
        balle::afficher();

        return;
    }

}

void test_namespace()
{
    test();
}
