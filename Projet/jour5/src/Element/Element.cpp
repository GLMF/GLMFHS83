#include <Element/Element.h>

using namespace cassebrique;

Element::Element(const Vecteur<int> &p) : m_position(p) { };

void Element::nouvellePosition(const Vecteur<int> &p)
{
	m_position = p;
}

Vecteur<int> Element::recupererPosition(void) const
{
	return m_position;
}

