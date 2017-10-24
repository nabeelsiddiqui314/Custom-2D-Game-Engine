#pragma once
#include "StateManager.h"
#include "ResourceManager.h"
#include "GUI.h"
#include "EntityManager.h"
#include "MapManager.h"

namespace Engine {
	struct data {
		StateManager* state;
		ResourceManager* assets;
		GUI* gui;
		EntityManager* entity;
		MapManager* map;
	};
}
// Data structure for management classes.