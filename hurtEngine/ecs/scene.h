#pragma once

#include <string>
#include <list>
#include "entity.h"

using namespace std;

class Scene {
public:
	Scene(string * name);
	bool addEntity(Entity * entity);
	list<Entity *> * getEntities(string * tag);
	bool removeEntity(Entity * entity);
	int removeEntities(string * tag);
	void clear();
	string * getName();
	~Scene();
private:
	string * name;
	list<Entity *> * entities;
	// TODO: camera field and getter
};