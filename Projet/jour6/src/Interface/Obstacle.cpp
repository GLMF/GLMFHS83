#include <Interface/Obstacle.h>

namespace cassebrique {
	std::string ObstacleResultatVersString(ObstacleResultat r) {
		switch(r) {
			case ObstacleResultat::INTACT: return "INTACT";
			case ObstacleResultat::DETRUIT: return "DETRUIT";
		}
		return "ERREUR";
	}
}
