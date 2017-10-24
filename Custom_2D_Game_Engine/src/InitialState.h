#pragma once
#include "State.h"
#include "data.h"
#include "StateOne.h"

namespace Engine {
	class InitialState : public State
	{
	public:
		InitialState(data* data) : m_data(data) {  }
		~InitialState() {}
	public:
		void Init(sf::RenderWindow* window) { m_data->state->SetState(new StateOne(m_data)); }
	private:
		data* m_data;
	};
}