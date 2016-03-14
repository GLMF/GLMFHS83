
#include <Ecran/SpriteCurses.h>
#include <Couleur/Couleur.h>
#include <math.h>

using namespace cassebrique;

#define VECTEUR_MOUVEMENT_BALLE Vecteur<double>(0.3, -0.8) // deplacement en cases par 1/24e de secondes
#define VECTEUR_POSITION_BALLE  Vecteur<double>(30, 30) // deplacement en cases par 1/24e de secondes
#define VECTEUR_TAILLE_BALLE    Vecteur<int>(1, 1) // deplacement en cases par 1/24e de secondes

#define VECTEUR_POSITION_RAQUETTE  Vecteur<double>(28, 31) // deplacement en cases par 1/24e de secondes
#define TAILLE_RAQUETTE 5
#define VECTEUR_TAILLE_RAQUETTE  Vecteur<int>(TAILLE_RAQUETTE, 1) // deplacement en cases par 1/24e de secondes




namespace cassebrique {

	static Vecteur<double> positionElementVersPositionSprite(const Vecteur<int> &v)
	{
		int x,y;
		v.recupererCoordonnees(x, y);
		return Vecteur<double>(1 + x * 5, 1 + y * 2);
	}

}

/* brique */
SpriteBriqueCurses::SpriteBriqueCurses(Element &b) : 
	Sprite(positionElementVersPositionSprite(b.recupererPosition()),
               Vecteur<int>(5,2), b), m_couleur(b.recupererCouleur()) {}

bool SpriteBriqueCurses::afficher(Ecran &e)
{
	Vecteur<int> position = VecteurDoubleVersInt(positionElementVersPositionSprite(m_element.recupererPosition()));

	e.ajouterPixel(position + Vecteur<int>( 1, 0), '_', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 2, 0), '_', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 3, 0), '_', m_couleur);

	e.ajouterPixel(position + Vecteur<int>( 0, 1), '[', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 1, 1), '_', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 2, 1), '_', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 3, 1), '_', m_couleur);
	e.ajouterPixel(position + Vecteur<int>( 4, 1), ']', m_couleur);

	return true;
}

/* raquette */
SpriteRaquetteCurses::SpriteRaquetteCurses(SpriteObservateur &o, Element &r) :
	SpriteRaquette(o, VECTEUR_POSITION_RAQUETTE, VECTEUR_TAILLE_RAQUETTE, r) {}

bool SpriteRaquetteCurses::afficher(Ecran &e)
{
	Vecteur<int> position = VecteurDoubleVersInt(recupererPosition());

	for (int i = 0; i < TAILLE_RAQUETTE; i++) {
		e.ajouterPixel(position + Vecteur<int>( i, 0), '=', Couleur::BLANC);
	}

	return true;
}

/* balle */
SpriteBalleCurses::SpriteBalleCurses(Element &b) :
	Sprite(VECTEUR_POSITION_BALLE, VECTEUR_TAILLE_BALLE, b)
{
	nouveauMouvement(VECTEUR_MOUVEMENT_BALLE);
}

bool SpriteBalleCurses::afficher(Ecran &e)
{
	e.ajouterPixel(VecteurDoubleVersInt(recupererPosition()), '*', Couleur::BLANC);
	return true;
}

/* canevas */
SpriteCanevasCurses::SpriteCanevasCurses(Element &c) :
	Sprite(Vecteur<double>(0,0), Vecteur<int>(MAX_WIDTH, MAX_HEIGHT), c) {}

bool SpriteCanevasCurses::afficher(Ecran &e)
{
	int max_height = MAX_HEIGHT;
	int max_width  = MAX_WIDTH;

	for (int i = 1; i < max_width-1; i++) {
		e.ajouterPixel(Vecteur<int>(i,0), '-', Couleur::BLANC);
	}

	for (int i = 1; i < max_height-1; i++) {
		e.ajouterPixel(Vecteur<int>(0,i),           '|', Couleur::BLANC);
		e.ajouterPixel(Vecteur<int>(max_width-1,i), '|', Couleur::BLANC);
	}

	e.ajouterPixel(Vecteur<int>(0,0),           '+', Couleur::BLANC);
	e.ajouterPixel(Vecteur<int>(max_width-1,0), '+', Couleur::BLANC);

	return true;
}

bool SpriteCursesFactory::creer(Element &e, Sprite **s)
{
	switch (e.type()) {
		case ElementType::BRIQUE:
		case ElementType::BRIQUE_INCASSABLE:
			*s = new SpriteBriqueCurses(e);
			break;
		case ElementType::BALLE:
			*s = new SpriteBalleCurses(e);
			break;
		case ElementType::CANEVAS:
			*s = new SpriteCanevasCurses(e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}

bool SpriteCursesFactory::creer(SpriteObservateur &o, Element &e, SpriteObserve **s)
{
	switch (e.type()) {
		case ElementType::RAQUETTE:
			*s = new SpriteRaquetteCurses(o, e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}
