
set(sources_test
	Vecteur/VecteurTest.cpp
	Element/ElementTest.cpp
	Element/BriqueTest.cpp
	Element/RaquetteTest.cpp
	main.cpp
)

add_executable(cassebriquetest ${sources_test})
target_link_libraries (cassebriquetest composants cppunit dl)

add_test(cassebriquetest cassebriquetest)
