#include <Ecran/EcranCurses.h>
#include <Ecran/SpriteCurses.h>
#include <unistd.h>

using namespace cassebrique;

EcranCurses::EcranCurses()
{
	initscr();
	clear();
	noecho();
	curs_set(0);
	cbreak();
	timeout(0);

	start_color();

	init_pair(EcranCouleur::COULEUR_BLANC, COLOR_WHITE, COLOR_BLACK);
	init_pair(EcranCouleur::COULEUR_BLEU, COLOR_BLUE, COLOR_BLACK);
	init_pair(EcranCouleur::COULEUR_ROUGE, COLOR_RED, COLOR_BLACK);

}

EcranCurses::~EcranCurses()
{
	endwin();
}

bool EcranCurses::effacer()
{
	if (erase() == ERR) {
		return false;
	}
	return true;
}

bool EcranCurses::rafraichir()
{
	if (refresh() == ERR) {
		return false;
	}
	return true;
}

bool EcranCurses::recupererDimensions(int &x, int &y) const
{
	/* getmaxyx(stdscr, x, y);*/
	x = MAX_WIDTH - 1;
	y = MAX_HEIGHT - 1;
	return true;
}

Action EcranCurses::lireAction()
{
	struct timeval timeout = { 0, 1000000/25 };
	fd_set rfds;
	int ret;
	int key = ERR;

	FD_ZERO(&rfds);
	FD_SET(fileno(stdin), &rfds);

	/* on boucle jusqu'au timeout du select */
	do {
		ret = select(1, &rfds, NULL, NULL, &timeout);
		if (ret <= 0) {
			/* timeout atteint, on quitte la boucle */		
			break;
		}

		/* on récupère les touches qu'on a pu trouver et on la mémorise */
		key = getch();

	} while (true);

	/* on execute l'action qu'on a trouvé pendant la période */
	switch (key) {
		case 'C': /* arrow */
			return Action::DROITE;
		case 'D':
			return Action::GAUCHE;
		case 'q':
			return Action::QUITTER;
		case ' ':
			return Action::DEMARRER;

		case ERR:
			/* pas de touche appuyée */
		default:;
			return Action::AUCUNE;
			/* rien pour l'instant */
	}


	return Action::QUITTER;
}

bool EcranCurses::ajouterPixel(const Vecteur<int> &v, char pix, Couleur c)
{
	int x,y;
	int color;

	v.recupererCoordonnees(x, y);

	switch (c) {
		case Couleur::BLANC:
			color = COLOR_PAIR(EcranCouleur::COULEUR_BLANC);
			break;
		case Couleur::BLEU:
			color = COLOR_PAIR(EcranCouleur::COULEUR_BLEU);
			break;
		case Couleur::ROUGE:
			color = COLOR_PAIR(EcranCouleur::COULEUR_ROUGE);
			break;
		default:
			return false;
	}

	mvaddch(y, x, pix | color);
	return true;
}

