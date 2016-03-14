
#pragma once

#include <list>
#include <Ecran/Sprite.h>
#include <Ecran/EcranCurses.h>

namespace cassebrique {

	class SpriteBriqueCurses : public Sprite {
		public:
			SpriteBriqueCurses(Element &b);
			bool afficher(Ecran &) override;
		private:
			const Couleur m_couleur;
	};

	class SpriteBalleCurses : public Sprite {
		public:
			SpriteBalleCurses(Element &b);
			bool afficher(Ecran &) override;
	};

	class SpriteCanevasCurses : public Sprite {
		public:
			SpriteCanevasCurses(Element &c);
			bool afficher(Ecran &) override;
	};

	/* la raquette est observée */
	class SpriteRaquetteCurses : public SpriteRaquette {
		public:
			SpriteRaquetteCurses(SpriteObservateur &o, Element &r);
			bool afficher(Ecran &) override;
	};

	/* pourrait etre un singleton et une classe générique SpriteFactory */
	class SpriteCursesFactory {
		public:
			SpriteCursesFactory() { m_list.clear(); }
			~SpriteCursesFactory() {
				for (Sprite *s : m_list) { delete s; } m_list.clear();
			}

			bool creer(Element &e, Sprite **s);
			bool creer(SpriteObservateur &o, Element &e, SpriteObserve **s);
			bool detruire(Sprite *s) { m_list.remove(s); delete s; return true; }

		private:
			std::list<Sprite*> m_list;
	};

}
