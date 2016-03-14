
set (sources_composants
	Physique/Physique2D.cpp
	Physique/Physique2DFaibleRes.cpp
	Element/Element.cpp
	Element/Brique.cpp
	Interface/Obstacle.cpp
	Couleur/Couleur.cpp
)

add_library(composants STATIC ${sources_composants})	

