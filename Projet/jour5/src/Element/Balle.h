
#pragma once

#include <Element/Element.h>

namespace cassebrique
{
	class Balle : public Element {
		public:
			Balle() : Element(Vecteur<int>(10, 9)) {}
			Balle(const Vecteur<int> &v) : Element(v) {}
			ElementType type() const override { return ElementType::BALLE; }

	};

};
