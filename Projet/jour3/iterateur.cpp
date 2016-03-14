
#include <vector>
#include <iostream>

void test_iterateur()
{
	std::vector<int> nombres = {34, 42, 54, 16, 27, 42};

	for (unsigned i=0; i < nombres.size(); i++)
	{
		std::cout << ' ' << nombres[i];
	}

	std::vector<int>::iterator it_debut = nombres.begin();
	std::vector<int>::iterator it_fin = nombres.end();

	/* boucle classique */
	for (std::vector<int>::iterator it = it_debut ; it != it_fin; ++it)
	{
		std::cout << ' ' << *it;
	}

	/* mot clé auto */
	for (auto it = nombres.begin() ; it != nombres.end(); ++it)
	{
		std::cout << ' ' << *it;
	}

	/* boucle simplifiée */
	for (auto it : nombres)
	{
		std::cout << ' ' << it;
	}

	/* forcer une reference */
	for (auto &nb : nombres)
	{
		std::cout << ' ' << nb;
	}

	std::cout << std::endl;
}

int main()
{
	test_iterateur();
	return 0;
}


