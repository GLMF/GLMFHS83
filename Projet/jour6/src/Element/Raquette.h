
#pragma once

#include <Element/Element.h>

namespace cassebrique
{
	class Raquette : public Element {
		public:
			Raquette() : Element(Vecteur<int>(10, 10)) {}
			Raquette(const Vecteur<int> &v) : Element(v) {}
			ElementType type() const override { return ElementType::RAQUETTE; }

	};

};
