
#include <iostream>

#include <Physique/Physique2D.h>
#include <Physique/Physique2DFaibleRes.h>
#include <Physique/Physique2DTest.h>

#include <Ecran/SpriteCurses.h>

using namespace cassebrique;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( Physique2DTest );


void Physique2DTest::setUp() { 
}

void Physique2DTest::tearDown() { }

void Physique2DTest::testCollisionLimites()
{
	Canevas canevas = Canevas();
	SpriteCanevasCurses scanevas = SpriteCanevasCurses(canevas);
	Physique2DFaibleRes phys = Physique2DFaibleRes();

	phys.canevas(&scanevas, 1, 1, 11, 21); /* espace de jeu = carré de 20x20 avec 10x10 utile */

	phys.dump(std::cout);

	Balle balle = Balle();
	SpriteBalleCurses sballe = SpriteBalleCurses(balle);

	Sprite *collision;
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(0, 0), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 0), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 0), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(0, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(0, 20), &collision) == true);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 1), &collision) == false);
	/* limite max x */
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 1), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(11, 1), &collision) == true);

	/* limite max x */
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 20), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 21), &collision) == true);

	/* limite max x,y */
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 20), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 21), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(11, 20), &collision) == true);

}

void Physique2DTest::testCollisionBalle()
{
	Canevas canevas = Canevas();
	SpriteCanevasCurses scanevas = SpriteCanevasCurses(canevas);
	Physique2DFaibleRes phys = Physique2DFaibleRes();
	phys.canevas(&scanevas, 1, 1, 11, 21); /* espace de jeu = carré de 20x20 avec 10x10 utile */

	Raquette raquette = Raquette();
	SpriteRaquetteCurses sraquette = SpriteRaquetteCurses(phys, raquette);
	sraquette.nouvellePosition(Vecteur<double>(5,8));
	CPPUNIT_ASSERT(phys.ajouter(sraquette) == true);

	Brique b1 = Brique(Vecteur<int>(0,0), Couleur::BLANC);
	Brique b2 = Brique(Vecteur<int>(1,1), Couleur::BLANC);

	SpriteBriqueCurses sb1 = SpriteBriqueCurses(b1);
	SpriteBriqueCurses sb2 = SpriteBriqueCurses(b2);

	CPPUNIT_ASSERT(phys.ajouter(sb1) == true);
	CPPUNIT_ASSERT(phys.ajouter(sb2) == true);

	phys.dump(std::cout);

	Balle balle = Balle();
	SpriteBalleCurses sballe = SpriteBalleCurses(balle);
	Sprite *collision;
	/* brique 1 */

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(2, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(3, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(4, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(5, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 2), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(2, 2), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(3, 2), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(4, 2), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(5, 2), &collision) == true);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(1, 3), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(2, 3), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(3, 3), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(4, 3), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(5, 3), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6, 1), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6, 2), &collision) == false);

	/* brique 2 */
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6 , 3 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(7 , 3 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(8 , 3 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(9 , 3 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 3 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6 , 4 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(7 , 4 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(8 , 4 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(9 , 4 ), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 4 ), &collision) == true);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6 , 2 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(7 , 2 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(8 , 2 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(9 , 2 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 2 ), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(6 , 5 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(7 , 5 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(8 , 5 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(9 , 5 ), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 5 ), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(5, 3), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(5, 4), &collision) == false);

	/* raquette */
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 4, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 5, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 6, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 7, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 8, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 9, 7), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 7), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 4, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 5, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 6, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 7, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 8, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 9, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 8), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 4, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 5, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 6, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 7, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 8, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>( 9, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sballe, Vecteur<int>(10, 9), &collision) == false);
}

void Physique2DTest::testCollisionRaquette()
{
	Canevas canevas = Canevas();
	SpriteCanevasCurses scanevas = SpriteCanevasCurses(canevas);
	Physique2DFaibleRes phys = Physique2DFaibleRes();
	phys.canevas(&scanevas, 1, 1, 11,  21); /* espace de jeu = carré de 20x20 avec 10x10 utile */

	Raquette raquette = Raquette();
	SpriteRaquetteCurses sraquette = SpriteRaquetteCurses(phys, raquette);
	sraquette.nouvellePosition(Vecteur<double>(5,8));
	CPPUNIT_ASSERT(phys.ajouter(sraquette) == true);

	phys.dump(std::cout);

	Sprite *collision;

	/* limites ... */

	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 0, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 1, 0), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 1, 1), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 6, 1), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 7, 1), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 5, 7), &collision) == false);

	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 1, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 2, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 3, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 4, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 5, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 6, 8), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 7, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 8, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 9, 8), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>(10, 8), &collision) == true);


	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 1, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 2, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 3, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 4, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 5, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 6, 9), &collision) == false);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 7, 9), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 8, 9), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>( 9, 9), &collision) == true);
	CPPUNIT_ASSERT(phys.collision(sraquette, Vecteur<int>(10, 9), &collision) == true);

}

