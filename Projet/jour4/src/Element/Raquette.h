
#pragma once

#include <Element/Element.h>

namespace cassebrique
{
	class Raquette : public Element {
		public:
			Raquette() : Element(Vecteur(10, 10)) {}
			Raquette(const Vecteur &v) : Element(v) {}
			ElementType type() const override { return ElementType::RAQUETTE; }

	};

};
