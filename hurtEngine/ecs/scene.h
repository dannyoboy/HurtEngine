#pragma once

#include <string>
#include <list>
#include "entity.h"

using namespace std;

class Scene {
public:
	inline Scene(string * nameIn) : name(nameIn) {}
	void addEntity(Entity * entity);
	list<Entity *> * getEntities(string * tag);
	list<Entity *> * getEntities();
	bool removeEntity(Entity * entity);
	int removeEntities(string * tag);
	void clear();
	string * getName();
	~Scene();

	// Engine-only methods
	void entityOnGameStart();
	void entityOnGameStop();
	void entityOnSceneLoad();
	void entityOnSceneClose();
	void entityOnUpdate();
	void entityOnLateUpdate();
private:
	string * name;
	list<Entity *> * entities = new list<Entity *>;
	// TODO: camera field and getter, make public?
};