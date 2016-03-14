#pragma once

#include <math.h>

#include <Vecteur/Vecteur.h>
#include <Element/Brique.h>
#include <Element/Raquette.h>
#include <Element/Balle.h>
#include <Element/Canevas.h>
#include <Ecran/Ecran.h>
#include <Ecran/SpriteObservable.h>

namespace cassebrique {

	class Sprite {
		public:
			Sprite(const Vecteur<double> &p, const Vecteur<int> &t, Element &e) : 
				m_position(p), m_mouvement(Vecteur<double>(0,0)), m_taille(t), m_element(e) {}
			virtual ~Sprite() {}

			/* taille du sprite */
			void nouvelleTaille(const Vecteur<int> &taille) { m_taille = taille; }
			Vecteur<int> recupererTaille() const { return m_taille; }

			/* mouvement du sprite */
			void nouveauMouvement(const Vecteur<double> &mouvement) { m_mouvement = mouvement; }
			Vecteur<double> recupererMouvement() const { return m_mouvement; }

			/* position */
			Vecteur<double> recupererPosition() const { return m_position; }
			/* observé */
			virtual void nouvellePosition(const Vecteur<double> &position) { m_position = position; }
			virtual void deplacer(const Vecteur<double> &mouvement) { m_position += mouvement; }

			/* affichage, dépend de l'écran */
			virtual bool afficher(Ecran &) = 0;

			/* recupération de l'objet du jeu */
			Element &element() { return m_element; }
		protected:
			Vecteur<double> m_position;
			Vecteur<double> m_mouvement;
			Vecteur<int> m_taille;
			Element &m_element;
	};

	/* SpriteObservé est utilisé pour les objets suivis  */
	class SpriteObserve : public Sprite, public SpriteObservable {
		public:
			SpriteObserve(SpriteObservateur &o,
				const Vecteur<double> &p,
				const Vecteur<int> &t,
				Element &r) : Sprite(p, t, r), SpriteObservable(o, *this) {}

			/* observable */
			void nouvellePosition(const Vecteur<double> &position) override {
				m_position = position;
				mise_a_jour();
			}

			void deplacer(const Vecteur<double> &mouvement) override {
				m_position += mouvement;
				mise_a_jour();
			}
	};

	/* la raquette est observée */
	class SpriteRaquette : public SpriteObserve {
		public:
			SpriteRaquette(SpriteObservateur &o,
				const Vecteur<double> &p,
				const Vecteur<int> &t,
				Element &r) : SpriteObserve(o, p, t, r) {}

	};

}
