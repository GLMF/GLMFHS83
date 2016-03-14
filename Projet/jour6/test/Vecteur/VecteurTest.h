
#include <cppunit/extensions/HelperMacros.h>

class VecteurTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( VecteurTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testEgalite );
  CPPUNIT_TEST( testDifferent );
  CPPUNIT_TEST( testSomme );
  CPPUNIT_TEST( testSoustraction );
  CPPUNIT_TEST_SUITE_END();

public: 
  void setUp();
  void tearDown();
 
  void testConstructor();
  void testSomme();
  void testSoustraction();
  void testEgalite();
  void testDifferent();
};
