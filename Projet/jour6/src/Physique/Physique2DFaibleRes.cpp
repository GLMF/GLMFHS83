
#include <Physique/Physique2DFaibleRes.h>

using namespace cassebrique;

bool Physique2DFaibleRes::canevas(Sprite *canevas, int min_x, int min_y, int max_x, int max_y)
{
	m_canevas = canevas;
	m_sprites.clear();

	m_x_max = max_x;
	m_y_max = max_y;

	//int min_x, int min_y, int max_x, int max_y;
	//canevas get dimension jouable => SpriteCanevas


	//m_sprites = new Sprite* [max_x][max_y];
	m_sprites.resize(max_y);
	for (int y = 0; y < max_y; y++) {
		m_sprites[y].resize(max_x);
	}

	/* clear */
	marquer(Vecteur<int>(0, 0), Vecteur<int>(max_x, max_y), nullptr);

	/* canevas */
	marquer(Vecteur<int>(0, 0), Vecteur<int>(min_x, max_y), canevas);
	marquer(Vecteur<int>(0, 0), Vecteur<int>(max_x, min_y), canevas);
	return true;
}

bool Physique2DFaibleRes::ajouter(Sprite &s)
{
	/* on sauvegarde la position qu'on enregistre */
	m_obs_position[&s] = VecteurDoubleVersInt(s.recupererPosition());
	return marquer(VecteurDoubleVersInt(s.recupererPosition()), s.recupererTaille(), &s);
}

bool Physique2DFaibleRes::detruire(Sprite &s)
{
	/* on récupère la position enregistrée */
	Vecteur<int> ancienne_position = m_obs_position[&s];
	return marquer(ancienne_position, s.recupererTaille(), nullptr);
}

bool Physique2DFaibleRes::marquer(const Vecteur<int> &pos, const Vecteur<int> &dim, Sprite *obj)
{
	int pos_x, pos_y;
	int max_pos_x, max_pos_y;
	int dim_x, dim_y;

	pos.recupererCoordonnees(pos_x, pos_y);
	dim.recupererCoordonnees(dim_x, dim_y);

	max_pos_x = pos_x + dim_x;
	max_pos_y = pos_y + dim_y;

	if (max_pos_x > m_x_max || max_pos_y > m_y_max) {
		return false;
	}

	for (int x = pos_x; x < max_pos_x; x++) {
		for (int y = pos_y; y < max_pos_y; y++) {
			m_sprites[y][x] = obj;
		}
	}
	return true;
}

bool Physique2DFaibleRes::collision(const Sprite &objet, const Vecteur<int> &v, Sprite **rencontre) const
{
	int pos_x, pos_y;
	int max_pos_x, max_pos_y;
	int dim_x, dim_y;

	Vecteur<int> dim = objet.recupererTaille();

	v.recupererCoordonnees(pos_x, pos_y);
	dim.recupererCoordonnees(dim_x, dim_y);

	max_pos_x = pos_x + dim_x;
	max_pos_y = pos_y + dim_y;

	if (max_pos_x > m_x_max) {
		*rencontre = m_canevas;
		return true;
	}

	if (max_pos_y > m_y_max) {
		*rencontre = m_canevas;
		return true;
	}

	for (int y = pos_y; y < max_pos_y; y++) {
		for (int x = pos_x; x < max_pos_x; x++) {
			*rencontre = m_sprites[y][x];
			if (*rencontre != nullptr) {
				/* il y a qqch a cet emplacement */
				if (*rencontre == &objet) {
					/* cas de l'element qui se trouve lui meme (raquette) */
					continue;
				}
				
				/* un autre objet est présent sur la case destination */
				return true;
			}
		}
	}

	/* il n'y a rien dans le tableau, la voie est libre */
	return false;
}

/* debug fonction : dump l'état de remplissage a l'écran */
void Physique2DFaibleRes::dump(std::ostream &out) const
{
	out << std::endl;
	for (int y = 0; y < m_y_max; y++) {
		for (int x = 0; x < m_x_max; x++) {
			if (m_sprites[y][x]) {
				out << "#";
			} else {
				out << ".";
			}
		}
		out << std::endl;
	}
	out << std::endl;
}

