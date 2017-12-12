#pragma once
#include "StateManager.h"
#include "ResourceManager.h"
#include "Interface.h"
#include "EntityManager.h"
#include "MapManager.h"
#include "Animation.h"
#include "RangeChecker.h"

#include "Definitions.h"

namespace Engine {
	struct data {
		StateManager*    state;
		ResourceManager* assets;
		EntityManager*   entity;
		MapManager*      map;
		Animation*       animation;
		RangeChecker     range;
	};
}
// Data structure for management classes.