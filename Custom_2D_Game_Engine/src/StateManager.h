#pragma once
#include "State.h"
#include <vector>

namespace Engine {
	class StateManager
	{
	public:
		 StateManager();
		~StateManager();
	public:
		void SetWindow (sf::RenderWindow& window);

		void SetState          (State* state);
		void SetSecondaryState (State* state);
		void SetTertiaryState  (State* state);

		void Update() const;
		void Render() const;
	private:
		sf::RenderWindow* m_window;
		State*            m_state;
		State*            m_SecondaryState;
		State*            m_TertiaryState;
	};
}