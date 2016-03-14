
#pragma once

#include <Vecteur/Vecteur.h>
#include <Ecran/Sprite.h>
#include <Physique/Physique2D.h>

namespace cassebrique {

template <typename P>
bool testerDeplacement(const P &physique, Sprite *sprite, Vecteur<double> mouvement, Sprite **rencontre)
{
	/* test si il n'y a pas de collision */
	Vecteur<double> position  = sprite->recupererPosition();

	Vecteur<int> prochaine_position = VecteurDoubleVersInt(position + mouvement);

	if (physique.collision(*sprite, prochaine_position, rencontre) == false) {
		return false;
	}

	/* on a une collision */
	return true;
}

template <typename P, typename S>
Vecteur<double> faireDeplacement(const P &physique, S *sprite, std::list<Sprite*> &collisions)
{
	S *rencontre;
	Vecteur<double> mouvement = sprite->recupererMouvement();

	/* on a une collision : inverser le déplacement */
	/* il faut tester quel coordonnee a generer le rebond : 1 ou 2 */
	double mv_x, mv_y;
	mouvement.recupererCoordonnees(mv_x, mv_y);

	/* on teste d'abord X */
	Vecteur<double> deplacement = Vecteur<double>(mv_x, 0);
	if (testerDeplacement(physique, sprite, deplacement, &rencontre) == false) {
		sprite->deplacer(deplacement);
	} else {
		/* on inverse et on gère la collision */
		mv_x = -mv_x;
		collisions.push_back(rencontre);
	}

	/* puis Y */
	deplacement = Vecteur<double>(0, mv_y);
	if (testerDeplacement(physique, sprite, deplacement, &rencontre) == false) {
		sprite->deplacer(deplacement);
	} else {
		/* on inverse et on gère la collision */
		mv_y = -mv_y;
		collisions.push_back(rencontre);
	}

	return Vecteur<double>(mv_x, mv_y);
}

template <typename P>
Vecteur<double> faireDeplacement(const P &physique, SpriteRaquette *sprite, std::list<Sprite*> &collisions)
{
	Sprite *rencontre;
	if (testerDeplacement(physique, sprite, sprite->recupererMouvement(), &rencontre) == false) {
		sprite->deplacer(sprite->recupererMouvement());
	}
	return Vecteur<double>(0,0);
}

};
