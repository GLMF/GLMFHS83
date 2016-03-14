#pragma once

#include <math.h>

namespace cassebrique
{
	/* template */

	template <class T>
	class Vecteur {
		public:
			Vecteur() : m_x(0), m_y(0) {}
			Vecteur(T x, T y);

			void nouvellesCoordonnees(T x, T y);

			/* doit etre marqué const pour notifier que les
			* données de l'objet ne seront pas modifiés */
			/* utilisé pour l'opérateur de comparaison par
			 * exemple */
			void recupererCoordonnees(T &x, T &y) const;

			/* surcharge d'opérateur. liste des operateurs : http://en.cppreference.com/w/cpp/language/operators */

			/* Quand le prototype de l'opérateur est déclaré dans la classe, il ne prend qu'un argument */
			Vecteur<T>& operator+=(const Vecteur<T> &rhs);
			Vecteur<T>& operator-=(const Vecteur<T> &rhs);
			Vecteur<T> operator+(const Vecteur<T> &rhs) const;
			Vecteur<T> operator-(const Vecteur<T> &rhs) const;

			bool operator==(const Vecteur<T> &rhs) const;
			bool operator!=(const Vecteur<T> &rhs) const;

		private:
			T m_x;
			T m_y;
	};

	/* helper */
	static inline Vecteur<int> VecteurDoubleVersInt(const Vecteur<double> &d) {
		double x,y; d.recupererCoordonnees(x, y);
		return Vecteur<int>(floor(x + 0.5), floor(y + 0.5)); }

#include <Vecteur/Vecteur.tpp>

}
