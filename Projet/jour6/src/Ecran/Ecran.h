#pragma once

#include <Element/Brique.h>
#include <Element/Balle.h>
#include <Element/Raquette.h>
#include <Element/Canevas.h>

#include <Couleur/Couleur.h>

namespace cassebrique {

	enum class Action { DROITE, GAUCHE, QUITTER, DEMARRER, AUCUNE };

	class Ecran {
	public:
		Ecran() {};
		virtual ~Ecran() {};
		virtual bool effacer() = 0;
		virtual bool rafraichir() = 0;
		virtual Action lireAction() = 0;
		virtual bool recupererDimensions(int &x, int &y) const = 0;
		virtual bool ajouterPixel(const Vecteur<int> &v, char pix, Couleur c) = 0;
	};
};
