
#pragma once

namespace cassebrique
{
	class Canevas : public Element {
		public:
			Canevas() : Element(Vecteur<int>(0,0)) {}
			ElementType type() const override { return ElementType::CANEVAS; }
	};
}
