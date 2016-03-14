#pragma once

#include <list>

#include <Element/Brique.h>

namespace cassebrique {

	class Niveau {
			using element_t = std::list<Element*>;
		public:
			using iterator = element_t::iterator;

			Niveau(int element_restants) : m_element_restants(element_restants) {}

			bool ajouter(Element &b) {
				m_element.push_back(&b);
				return true;
			}

			bool detruire(Element &b) {
				m_element.remove(&b);
				m_element_restants --;
				return true;
			}

			bool estTermine() { return m_element_restants == 0; }

			/* iterateur sur les element */
			iterator begin() { return m_element.begin(); }
			iterator end() { return m_element.end(); }

		private:
			unsigned m_element_restants;
			element_t m_element;

	};

}
