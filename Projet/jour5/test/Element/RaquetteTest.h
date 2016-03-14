
#include <cppunit/extensions/HelperMacros.h>

class RaquetteTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( RaquetteTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCollision );
  CPPUNIT_TEST_SUITE_END();

public: 
  void setUp();
  void tearDown();
 
  void testConstructor();
  void testCollision();
};
