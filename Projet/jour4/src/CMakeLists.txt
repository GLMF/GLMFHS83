
set (sources_composants
	Element/Element.cpp
	Element/Brique.cpp
	Interface/Obstacle.cpp
	Couleur/Couleur.cpp
	Vecteur/Vecteur.cpp
)

add_library(composants STATIC ${sources_composants})	

