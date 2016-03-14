#pragma once

#include <array>

namespace cassebrique
{
	enum class ObstacleResultat { INTACT, DETRUIT };
	std::string ObstacleResultatVersString(ObstacleResultat r);

	class Obstacle {
		public:
			virtual ObstacleResultat collision() const = 0;
	};
};
