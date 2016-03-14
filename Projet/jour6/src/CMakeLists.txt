
set (sources_composants
	Physique/Physique2D.cpp
	Physique/Physique2DFaibleRes.cpp
	Element/Element.cpp
	Element/Brique.cpp
	Interface/Obstacle.cpp
	Ecran/EcranCurses.cpp
	Ecran/SpriteCurses.cpp
	Couleur/Couleur.cpp
	Jeu.cpp
)

add_library(composants STATIC ${sources_composants})	

# application
add_executable(cassebrique main.cpp)
target_link_libraries(cassebrique composants ncurses)

