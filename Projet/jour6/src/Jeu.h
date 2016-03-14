#pragma once

#include <Strat/Niveau.h>
#include <Ecran/Ecran.h>
#include <Physique/Physique2D.h>
#include <Ecran/SpriteCurses.h> /* XXX TODO generic */
#include <Vecteur/Vecteur.h>
#include <Deplacement/Deplacement.h>

namespace cassebrique {

	class Jeu {
		public:
			Jeu(Ecran &ecran, Physique2D &physique) : m_ecran(ecran), m_physique(physique), m_jeu_en_cours(false) {}
			bool demarrer(Niveau &niveau);
			bool afficher();

			bool executer(Action action);
		private:
			bool collision(Sprite *rencontre);

			Balle m_balle;
			Canevas m_canevas;
			Raquette m_raquette;

			Sprite *m_sprite_balle;
			Sprite *m_sprite_canevas;
			SpriteRaquette *m_sprite_raquette;
			std::list<Sprite*> m_sprites;

			Ecran &m_ecran;
			Physique2D &m_physique;

			Niveau *m_niveau;
			SpriteCursesFactory m_sprite_factory; /* XXX TODO replace generic */
			bool m_jeu_en_cours;
			

	};

}
