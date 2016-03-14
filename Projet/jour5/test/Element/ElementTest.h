
#include <cppunit/extensions/HelperMacros.h>

class ElementTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( ElementTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();

public: 
  void setUp();
  void tearDown();
 
  void testConstructor();
};
