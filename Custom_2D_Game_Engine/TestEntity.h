#pragma once
#include "Entity.h"
#include "data.h"

class TestEntity : public Engine::Entity
{
public:
	TestEntity(Engine::data* data);
	~TestEntity();
public:
	bool Update();
private:
	Engine::data* m_data;
};

