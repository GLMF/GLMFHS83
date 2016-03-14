#include <Vecteur/Vecteur.h>

using namespace cassebrique;

template <class T>
Vecteur<T>::Vecteur(T x, T y) : m_x(x), m_y(y) {}

template <class T>
void Vecteur<T>::nouvellesCoordonnees(T x, T y)
{
	*this = Vecteur(x,y);
}

template <class T>
void Vecteur<T>::recupererCoordonnees(T &x, T &y) const
{
	x = m_x;
	y = m_y;
}

template <class T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T> &rhs) const
{
	/* on retourne un nouvel objet qui est la somme
	 * des deux objets *this et rhs */
	return Vecteur<T>(m_x + rhs.m_x,
	                  m_y + rhs.m_y);
}

template <class T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur<T> &rhs) const
{
	return Vecteur<T>(m_x - rhs.m_x,
                      m_y - rhs.m_y);
}

template <class T>
Vecteur<T>& Vecteur<T>::operator+=(const Vecteur<T> &rhs)
{
	/* on affecte dans l'objet courant la somme des deux objets
	 * avec réutilisation de l'opérateur + */
	*this = *this + rhs;

	/* on retourne l'objet modifié */
	return *this;
}

template <class T>
Vecteur<T>& Vecteur<T>::operator-=(const Vecteur<T> &rhs)
{
	*this = *this - rhs;
	return *this;

	/*
	this.m_x -= rhs.m_x;
	this.m_y -= rhs.m_y;

	return *this;
    */
}

template <class T>
bool Vecteur<T>::operator==(const Vecteur<T> &rhs) const
{
	return (m_x == rhs.m_x) && (m_y == rhs.m_y);
}

template <class T>
bool Vecteur<T>::operator!=(const Vecteur<T> &rhs) const
{
	return !(*this == rhs); /* on réutilise l'opérateur == */
}
