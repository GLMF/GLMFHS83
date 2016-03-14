#include <Element/Element.h>

using namespace cassebrique;

Element::Element(const Vecteur &p) : m_position(p) { };

void Element::nouvellePosition(const Vecteur &p)
{
	m_position = p;
}

Vecteur Element::recupererPosition(void) const
{
	return m_position;
}

