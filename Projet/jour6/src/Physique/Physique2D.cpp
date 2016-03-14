
#include <Physique/Physique2D.h>

using namespace cassebrique;

bool Physique2D::mise_a_jour(SpriteObservable &obs)
{
	Sprite &s = obs.sprite();
	detruire(s);
	return ajouter(s);
}

