#include <stdlib.h>
#include <string>

#include <Strat/Niveau1.h>
#include <Element/Brique.h>
#include <Element/Canevas.h>
#include <Ecran/EcranCurses.h>

#include <Physique/Physique2DFaibleRes.h>

#include <Jeu.h>

using namespace cassebrique;

int main(int argc, char **argv)
{
	EcranCurses ecran;
	Niveau1 niveau1;
	Physique2DFaibleRes physique;

	Jeu jeu(ecran, physique);
	jeu.demarrer(niveau1);

	Action action;
	do { 
		jeu.afficher();
		action = ecran.lireAction();
	} while(jeu.executer(action));

	return EXIT_SUCCESS;
}
