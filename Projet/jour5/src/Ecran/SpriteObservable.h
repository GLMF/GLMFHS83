#pragma once

#include <Ecran/Ecran.h>
#include <Ecran/Sprite.h>

namespace cassebrique {

	class Ecran;
	class Sprite;
	class SpriteObservable;

	/* définition pour Sprite : */

	class SpriteObservateur {
		public:
			virtual bool mise_a_jour(SpriteObservable &) = 0;
	};

	class SpriteObservable {
		public:
			SpriteObservable(SpriteObservateur &o, Sprite &s) : m_sprite(s), m_observateur(o) {}
			Sprite &sprite() { return m_sprite; }

		protected:
			void mise_a_jour() { m_observateur.mise_a_jour(*this); }

		private:
			Sprite &m_sprite;
			SpriteObservateur &m_observateur;
	};

}
