
#include <cppunit/extensions/HelperMacros.h>

class Physique2DTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( Physique2DTest );
  CPPUNIT_TEST( testCollisionLimites );
  CPPUNIT_TEST( testCollisionBalle );
  CPPUNIT_TEST( testCollisionRaquette );
  CPPUNIT_TEST_SUITE_END();

public: 
  void setUp();
  void tearDown();
 
  void testConstructor();
  void testCollisionLimites();
  void testCollisionBalle();
  void testCollisionRaquette();
};
