#pragma once
#include "StateManager.h"
#include "ResourceManager.h"
#include "GUI.h"
#include "EntityManager.h"

namespace Engine {
	struct data {
		StateManager* state;
		ResourceManager* assets;
		GUI* gui;
		EntityManager* entity;
	};
}