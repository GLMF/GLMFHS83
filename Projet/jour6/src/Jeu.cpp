
#include <Jeu.h>
#include <math.h>

using namespace cassebrique;

bool Jeu::demarrer(Niveau &niveau)
{
	int x, y;
	m_ecran.recupererDimensions(x, y);

	/* creation du canevas */
	if (m_sprite_factory.creer(m_canevas, &m_sprite_canevas) != true) {
		return false;
	}
	
	/* définition des limites de l'aire de jeu dans le moteur de collision */
	m_physique.canevas(m_sprite_canevas, 1, 1, x, y);

	/* creation des briques */
	for (Element *it : niveau) {
		Element &b = *it;
		Sprite *s;
		if (m_sprite_factory.creer(b, &s) == false) {
			return false;
		}

		m_sprites.push_back(s);
		m_physique.ajouter(*s);
	}

	/* création de la raquette et suivi de celle ci */
	if (m_sprite_factory.creer(m_physique, m_raquette, (SpriteObserve**)&m_sprite_raquette) != true) {
		return false;
	}
	m_physique.ajouter(*m_sprite_raquette);

	/* création de la balle */
	if (m_sprite_factory.creer(m_balle, &m_sprite_balle) != true) {
		return false;
	}

	m_niveau = &niveau;

	return true;
}

bool Jeu::collision(Sprite *rencontre)
{
	switch (rencontre->element().collision()) {
		case ObstacleResultat::INTACT:
			return false;

		case ObstacleResultat::DETRUIT:
			/* l'objet doit etre détruit */
			m_sprites.remove(rencontre); /* de la liste des choses affichées */
			m_physique.detruire(*rencontre); /* du moteur de collision */
			m_niveau->detruire(rencontre->element()); /* du niveau */
			return true;
	}
	return false;
}

bool Jeu::afficher()
{
	m_ecran.effacer();

	for (Sprite *s : m_sprites) {
		s->afficher(m_ecran);
	}

	m_sprite_balle->afficher(m_ecran);
	m_sprite_raquette->afficher(m_ecran);
	m_sprite_canevas->afficher(m_ecran);

	m_ecran.rafraichir();

	return true;
}

bool Jeu::executer(Action action)
{
	std::list<Sprite*> collisions;
	Vecteur<double> mouvement;
	/* on execute l'action qu'on a trouvé pendant la période */
	switch (action) {
		case Action::DROITE:
			m_sprite_raquette->nouveauMouvement(Vecteur<double>(1,0));
			mouvement = faireDeplacement(m_physique, m_sprite_raquette, collisions);
			m_sprite_raquette->nouveauMouvement(mouvement);
			break;
		case Action::GAUCHE:
			m_sprite_raquette->nouveauMouvement(Vecteur<double>(-1,0));
			mouvement = faireDeplacement(m_physique, m_sprite_raquette, collisions);
			m_sprite_raquette->nouveauMouvement(mouvement);
			break;

		case Action::DEMARRER:
			/* lance la balle : démarre le jeu */
			m_jeu_en_cours = true;
			break;

		case Action::QUITTER:
			/* quitte le jeu */
			return false;

		case Action::AUCUNE:
			break;
	}

	/* on déplace la balle a chaque iteration */
	if (m_jeu_en_cours) {
		int ex, ey, bx, by;
		m_ecran.recupererDimensions(ex, ey);

		Vecteur<double> mouvement = faireDeplacement(m_physique, m_sprite_balle, collisions);
		m_sprite_balle->nouveauMouvement(mouvement);

		/* vérifier la sortie de la balle */
		VecteurDoubleVersInt(m_sprite_balle->recupererPosition()).recupererCoordonnees(bx, by);
		if (by == ey - 1) {
			return false;
		}

		if (collisions.size()) {
			/* on a eu une collision */
			for (auto sprite : collisions) {
				collision(sprite);
			}

			if (m_niveau->estTermine() == true) {
				return false;
			}
		}
	}

	return true;
}
