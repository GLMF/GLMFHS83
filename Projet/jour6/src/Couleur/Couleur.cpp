#include <Couleur/Couleur.h>

using namespace cassebrique;

namespace cassebrique {
	std::string CouleurVersString(Couleur c) {
		switch(c) {
			case Couleur::BLEU: return "BLEU";
			case Couleur::BLANC: return "BLANC";
			case Couleur::ROUGE: return "ROUGE";
		}
		return "ERREUR";
	}
}

