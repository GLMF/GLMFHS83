#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <Ecran/Sprite.h>
#include <Ecran/SpriteObservable.h>

namespace cassebrique {

	class Physique2D : public SpriteObservateur {
		public:
			Physique2D() {}
			virtual ~Physique2D() {}

			virtual bool canevas(Sprite *canevas, int min_x, int min_y, int max_x, int max_y) = 0;

			virtual bool collision(const Sprite &sprite, const Vecteur<int> &v, Sprite **rencontre) const = 0;

			virtual bool ajouter(Sprite &s) = 0;
			virtual bool detruire(Sprite &s) = 0;

			virtual void dump(std::ostream &out) const = 0;

			/* observable */
			bool mise_a_jour(SpriteObservable &) override;


		protected:
			/* dimension autorisées et objet associé */
			int m_x_min;
			int m_y_min;
			int m_x_max;
			int m_y_max;
			Sprite *m_canevas;
	};

}
