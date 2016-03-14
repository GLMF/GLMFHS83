
#include <Element/RaquetteTest.h>
#include <Element/Raquette.h>
#include <Element/Brique.h>
#include <Interface/Obstacle.h>

using namespace cassebrique;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RaquetteTest );


void 
RaquetteTest::setUp()
{
}


void 
RaquetteTest::tearDown()
{
}

void RaquetteTest::testConstructor()
{
	Raquette r(Vecteur<int>(1,2));
	CPPUNIT_ASSERT(r.recupererPosition() == Vecteur<int>(1,2));
}

void RaquetteTest::testCollision()
{
	/* test de la fonction virtuelle collision */
	Brique             brique(Vecteur<int>(1,1), Couleur::BLANC);
	Raquette           raquette(Vecteur<int>(2,2));

}
