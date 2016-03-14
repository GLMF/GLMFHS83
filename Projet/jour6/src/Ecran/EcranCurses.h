#pragma once

#include <ncurses.h>

#include <Ecran/Ecran.h>
#include <Vecteur/Vecteur.h>
#include <Couleur/Couleur.h>
#include <Ecran/SpriteCurses.h>

namespace cassebrique {

#define MAX_WIDTH 80
#define MAX_HEIGHT 35

	enum EcranCouleur : short int { COULEUR_AUCUNE, COULEUR_BLANC, COULEUR_BLEU, COULEUR_ROUGE };

	class EcranCurses : public Ecran {
		public:
			EcranCurses();
			~EcranCurses();
			bool effacer() override;
			bool rafraichir() override;
			Action lireAction() override;
			bool recupererDimensions(int &x, int &y) const override;
			bool ajouterPixel(const Vecteur<int> &v, char pix, Couleur c) override;
	};
};
