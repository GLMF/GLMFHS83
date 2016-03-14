
#include <Element/ElementTest.h>
#include <Element/Element.h>

using namespace cassebrique;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ElementTest );


void 
ElementTest::setUp()
{
}


void 
ElementTest::tearDown()
{
}

void ElementTest::testConstructor()
{
	Vecteur v(0, 0);
	Element e(Vecteur(1,2));

	CPPUNIT_ASSERT(e.recupererPosition() == Vecteur(1,2));
}
