#include <Vecteur/Vecteur.h> 

using namespace cassebrique; 

Vecteur::Vecteur(int x, int y) : m_x(x), m_y(y) {}  

void Vecteur::nouvellesCoordonnees(int x, int y)
{
	*this = Vecteur(x,y);
}

void Vecteur::recupererCoordonnees(int &x, int &y) const 
{ 
	x = m_x; 
	y = m_y; 
}

Vecteur Vecteur::operator+(const Vecteur &rhs) const
{
	/* on retourne un nouvel objet qui est la somme
	 * des deux objets *this et rhs */
	return Vecteur(m_x + rhs.m_x,
	               m_y + rhs.m_y);
}

Vecteur Vecteur::operator-(const Vecteur &rhs) const
{
	return Vecteur(m_x - rhs.m_x,
	               m_y - rhs.m_y);
}

Vecteur& Vecteur::operator+=(const Vecteur &rhs)
{
	/* on affecte dans l'objet courant la somme des deux objets
	 * avec réutilisation de l'opérateur + */
	*this = *this + rhs;

	/* on retourne l'objet modifié */
	return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur &rhs)
{
	*this = *this - rhs;
	return *this;
}

bool Vecteur::operator==(const Vecteur &rhs) const
{
	return (m_x == rhs.m_x) && (m_y == rhs.m_y);
}

bool Vecteur::operator!=(const Vecteur &rhs) const
{
	return !(*this == rhs); /* on réutilise l'opérateur == */
}

