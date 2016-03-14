#include <Element/Brique.h>

using namespace cassebrique;

Brique::Brique(const Vecteur<int> &v, Couleur couleur) : Element(v), m_couleur(couleur) {}
ObstacleResultat Brique::collision() const { return ObstacleResultat::DETRUIT; }

BriqueIncassable::BriqueIncassable(const Vecteur<int> &v) : Brique(v, Couleur::ROUGE) {}
ObstacleResultat BriqueIncassable::collision() const { return ObstacleResultat::INTACT; }

