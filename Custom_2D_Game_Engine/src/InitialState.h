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
		void Init        (sf::RenderWindow& window) override { m_data->state->SetState(new StateOne(m_data)); }
		void HandleInput (sf::RenderWindow& window) override {}
		void Update      (sf::RenderWindow& window) override {}
		void Render      (sf::RenderWindow& window) override {}
		void Destroy     (sf::RenderWindow& window) override {}
	private:
		data* m_data;
	};
}