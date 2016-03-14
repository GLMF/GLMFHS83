
#pragma once

#include <array>
#include <Couleur/Couleur.h>
#include <Element/Element.h>
#include <Interface/Obstacle.h>

namespace cassebrique
{
	class Brique : public Element, private Obstacle {
		public:
			Brique(const Vecteur &, Couleur);

			Couleur recupererCouleur() const override { return m_couleur; }

			ObstacleResultat collision() const override;
			virtual ElementType type() const override { return ElementType::BRIQUE; }

		private:
			Couleur m_couleur;
	};

	class BriqueIncassable : public Brique {
		public:
			BriqueIncassable(const Vecteur &);
			ObstacleResultat collision() const override;
			ElementType type() const override { return ElementType::BRIQUE_INCASSABLE; }
	};
};
