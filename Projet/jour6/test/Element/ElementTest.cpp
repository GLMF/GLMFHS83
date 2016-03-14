
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
	Vecteur<int> v(0, 0);
	Element e(Vecteur<int>(1,2));

	CPPUNIT_ASSERT(e.recupererPosition() == Vecteur<int>(1,2));
}
