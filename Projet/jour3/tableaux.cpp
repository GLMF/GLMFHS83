#include <iostream>

short tableau_non_init[7];

short tableau[7] = {1, 2, 3, 4, 5, 6, 7};

short tableau2[6][7]; /* les valeurs ne sont pas définies */

void afficher_tableau()
{
	int i;
	for (i = 0 ; i < 7 ; i++)
	{
		// Code à exécuter, pour chaque case du tableau, par exemple:
		std::cout << "tableau[" << i << "] = " << tableau[i] << std::endl;
	}
}

void afficher_tableau2()
{
	int i, j;
	for (i = 0 ; i < 6 ; i++)
	{
		for (j = 0 ; j < 7 ; j++)
		{
			// Code à exécuter pour chaque case du tableau:
			std::cout << "tableau2[" << i << "][" << j << "] = " << tableau2[i][j] << std::endl;
		}
	}
}

int main()
{
	afficher_tableau();
	afficher_tableau2();
	return 0;
}
