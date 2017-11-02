#pragma once
#include "StateManager.h"
#include "ResourceManager.h"
#include "GUI.h"
#include "EntityManager.h"
#include "MapManager.h"
#include "Animation.h"
#include "Definitions.h"

namespace Engine {
	struct data {
		StateManager* state;
		ResourceManager* assets;
		GUI* gui;
		EntityManager* entity;
		MapManager* map;
		Animation* animation;
	};
}
// Data structure for management classes.