#pragma once

namespace cassebrique
{
	class Vecteur {
		public:
			Vecteur(int x, int y);

			void nouvellesCoordonnees(int x, int y);

			/* doit etre marqué const pour notifier que les
			* données de l'objet ne seront pas modifiés */
			/* utilisé pour l'opérateur de comparaison par
			 * exemple */
			void recupererCoordonnees(int &x, int &y) const;

			/* surcharge d'opérateur. liste des operateurs : http://en.cppreference.com/w/cpp/language/operators */

			/* Quand le prototype de l'opérateur est déclaré dans la classe, il ne prend qu'un argument */
			Vecteur& operator+=(const Vecteur &rhs);
			Vecteur& operator-=(const Vecteur &rhs);
			Vecteur operator+(const Vecteur &rhs) const;
			Vecteur operator-(const Vecteur &rhs) const;

			bool operator==(const Vecteur &rhs) const;
			bool operator!=(const Vecteur &rhs) const;

		private:
			int m_x;
			int m_y;
	};

}
