#pragma once
#include "StateManager.h"
#include "ResourceManager.h"
#include "GUI.h"

namespace Engine {
	struct data {
		StateManager* machine;
		ResourceManager* assets;
		GUI* gui;
	};
}