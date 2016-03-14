
#include <cppunit/extensions/HelperMacros.h>

class BriqueTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( BriqueTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCollision );
  CPPUNIT_TEST_SUITE_END();

public: 
  void setUp();
  void tearDown();
 
  void testConstructor();
  void testCollision();
};
