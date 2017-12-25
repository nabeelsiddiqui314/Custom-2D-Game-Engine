#include "stdafx.h"
#include "PushButtonManager.h"

namespace Engine {
	PushButtonManager::PushButtonManager(const Type& type) : m_type(type)
	{

	}


	void PushButtonManager::Add(std::string name, const sf::Vector2f& size, const sf::Vector2f& pos, const std::string filepath, const sf::IntRect& crop,
		const sf::IntRect& hovered, const sf::IntRect& clicked) {
		m_pb.Init(size, pos, filepath, crop, hovered, clicked, m_type);

		std::unordered_map <std::string, PushButton>::const_iterator found = m_buttonGroup.find(name);
		while (found != m_buttonGroup.end()) {
			name += "0";
			found = m_buttonGroup.find(name);
		}
		m_buttonGroup.insert(std::make_pair(name, m_pb));
	}

	void PushButtonManager::Update(sf::RenderWindow& window) {
		if (m_type == SELECT) {
			for (auto& iterator : m_buttonGroup) {
				iterator.second.CropWidget(window);
				if (iterator.second.IsClicked()) {
					m_clickedWidget = &iterator.second;
				}
				if (m_clickedWidget != nullptr) {
					for (auto& unclickedIterator : m_buttonGroup) {
						if (&unclickedIterator.second != m_clickedWidget) unclickedIterator.second.Deselect();
					}
				}
				window.draw(iterator.second);
			}
		}

		else if (m_type == INFINITE) {
			for (auto& iterator : m_buttonGroup) {
				iterator.second.CropWidget(window);
				window.draw(iterator.second);
			}
		}
	}

	void PushButtonManager::DeselectAll() {
		for (auto& all : m_buttonGroup) {
			all.second.Deselect();
		}
	}

	const PushButton& PushButtonManager::Get(const std::string name) const {
		std::unordered_map <std::string, PushButton>::const_iterator found = m_buttonGroup.find(name);
		if (found == m_buttonGroup.end()) {
			PushButton temp;
			return temp;
		}
		else
			return found->second;
	}


	PushButtonManager::~PushButtonManager()
	{
		m_buttonGroup.clear();
	}
}