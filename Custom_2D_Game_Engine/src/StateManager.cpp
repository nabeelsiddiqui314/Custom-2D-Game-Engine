#include "stdafx.h"
#include "StateManager.h"

namespace Engine {
	StateManager::StateManager() {
		m_state = NULL;
		m_SecondaryState = NULL;
		m_TertiaryState = NULL;
	}

	void StateManager::SetWindow(sf::RenderWindow* window) {
		m_window = window;
	}

	void StateManager::SetState(State* state) {
		if (m_state != NULL) {
			m_state->Destroy(m_window);
		}
		delete m_state;
		m_state = state;
		if (m_state != NULL) {
			m_state->Init(m_window);
		}
	}

	void StateManager::SetSecondaryState(State* state) {
		if (m_SecondaryState != NULL) {
			m_SecondaryState->Destroy(m_window);
		}
		delete m_SecondaryState;
		m_SecondaryState = state;
		if (m_SecondaryState != NULL) {
			m_SecondaryState->Init(m_window);
		}
	}

	void StateManager::SetTertiaryState(State* state) {
		if (m_TertiaryState != NULL) {
			m_TertiaryState->Destroy(m_window);
		}
		delete m_TertiaryState;
		m_TertiaryState = state;
		if (m_TertiaryState != NULL) {
			m_TertiaryState->Init(m_window);
		}
	}

	void StateManager::Update() const {
		if (m_state != NULL) {
			m_state->HandleInput(m_window);
			m_state->Update(m_window);
		}
		if (m_SecondaryState != NULL) {
			m_SecondaryState->HandleInput(m_window);
			m_SecondaryState->Update(m_window);
		}
		if (m_TertiaryState != NULL) {
			m_TertiaryState->HandleInput(m_window);
			m_TertiaryState->Update(m_window);
		}
	}

	void StateManager::Render() const {
		if (m_state != NULL) {
			m_state->Render(m_window);
		}
		if (m_SecondaryState != NULL) {
			m_SecondaryState->Render(m_window);
		}
		if (m_TertiaryState != NULL) {
			m_TertiaryState->Render(m_window);
		}
	}

	StateManager::~StateManager() {
		if (m_state != NULL) {
			m_state->Destroy(m_window);
		}
		if (m_SecondaryState != NULL) {
			m_SecondaryState->Destroy(m_window);
		}
		if (m_TertiaryState != NULL) {
			m_TertiaryState->Destroy(m_window);
		}
	}
}