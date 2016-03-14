#pragma once

#include <Vecteur/Vecteur.h>
#include <Interface/Obstacle.h>
#include <Couleur/Couleur.h>

namespace cassebrique
{

	enum class ElementType { ELEMENT, CANEVAS, BRIQUE, BRIQUE_INCASSABLE, RAQUETTE, BALLE };

	class Element {
		public:
			Element(const Vecteur<int> &p);

			void nouvellePosition(const Vecteur<int> &p);
			Vecteur<int> recupererPosition(void) const;

			/* interface Obstacle */
			virtual ObstacleResultat collision() const { return ObstacleResultat::INTACT; }

			virtual Couleur recupererCouleur() const { return Couleur::BLANC; }
			virtual ElementType type() const { return ElementType::ELEMENT; }

		private: /* heritage : tant qu'on n'accede pas a position depuis une sous classe mais uniquement via ces accesseurs, pas besoin de private */
			Vecteur<int> m_position;
	};
};
