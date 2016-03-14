#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <Ecran/Sprite.h>
#include <Ecran/SpriteObservable.h>
#include <Physique/Physique2D.h>

namespace cassebrique {

	class Physique2DFaibleRes : public Physique2D {
		public:
			Physique2DFaibleRes() {}
			~Physique2DFaibleRes() override { effacer(); }

			bool canevas(Sprite *canevas, int min_x, int min_y, int max_x, int max_y) override;

			bool collision(const Sprite &sprite, const Vecteur<int> &v, Sprite **rencontre) const override;

			bool ajouter(Sprite &s) override;
			bool detruire(Sprite &s) override;

			void dump(std::ostream &out) const override;

		private:
			void effacer() { m_sprites.clear(); }
			bool marquer(const Vecteur<int> &pos, const Vecteur<int> &dim, Sprite *obj);

			/* dimension autorisées et objet associé */
			int m_x_max;
			int m_y_max;
			Sprite *m_canevas;

			/* tableau des objets par Vecteur */
			std::vector<std::vector<Sprite*>> m_sprites;

			std::unordered_map<const Sprite*, Vecteur<int>> m_obs_position;
	};

}
