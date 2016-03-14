
#include <Element/BriqueTest.h>
#include <Element/Brique.h>
#include <Interface/Obstacle.h>

using namespace cassebrique;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BriqueTest );


void 
BriqueTest::setUp()
{
}


void 
BriqueTest::tearDown()
{
}

void BriqueTest::testConstructor()
{
	Vecteur v(0, 0);
	Brique b(Vecteur(1,2), Couleur::BLANC);
	CPPUNIT_ASSERT(b.recupererPosition() == Vecteur(1,2));
}

void BriqueTest::testCollision()
{
	/* test de la fonction virtuelle collision */
	Brique           normale(Vecteur(2,2), Couleur::BLANC);
	BriqueIncassable incassable(Vecteur(4,4));

	Brique  brique_incassable = incassable; /* copie non polymorphe */
	Brique &ref_incassable    = incassable; /* copie polymorphique (grace à la référence) */

	/* les collisions avec une brique normale la détruise*/
	CPPUNIT_ASSERT(normale.collision() == ObstacleResultat::DETRUIT);

	/* les collisions avec une brique incassable ne la détruise pas */
	CPPUNIT_ASSERT(incassable.collision()     == ObstacleResultat::INTACT);
	CPPUNIT_ASSERT(ref_incassable.collision() == ObstacleResultat::INTACT);

	/* le résultat n'est pas celui que l'on attend : il est obligatoire d'utiliser
         * des références pour la résolution dynamique de la fonction virtuelle */
	CPPUNIT_ASSERT(brique_incassable.collision() == ObstacleResultat::DETRUIT);

}
