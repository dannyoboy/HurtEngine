#include "scene.h"

// Public

void Scene::addEntity(Entity * entity) {
	entity->onAdd();
	entities->push_back(entity);
}

list<Entity *> * Scene::getEntities(string * tag) {
	list<Entity *> * tagged = new list<Entity *>();

	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Entity * entity = *iter;

		if (entity->getTag() == tag) {
			tagged->push_back(entity);
		}
	}

	return tagged;
}

list<Entity *> * Scene::getEntities() {
	return entities;
}

bool Scene::removeEntity(Entity * entity) {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Entity * current = *iter;

		if (current == entity) {
			current->onRemove();
			entities->remove(current);
			return true;
		}
	}

	return false;
}

int Scene::removeEntities(string * tag) {
	int count = 0;

	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		if ((*iter)->getTag() == tag) {
			entities->erase(iter);
			count++;
		}
	}

	return count;
}

void Scene::clear() {
	entities->clear();
}

string * Scene::getName() {
	return name;
}

Scene::~Scene() {
	delete entities;
}

// Engine-only methods

void Scene::entityOnSceneLoad() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++entities) {
		(*iter)->onSceneLoad();
	}
}

void Scene::entityOnSceneClose() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++entities) {
		(*iter)->onSceneClose();
	}
}

void Scene::entityOnUpdate() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++entities) {
		(*iter)->onUpdate();
	}
}

void Scene::entityOnLateUpdate() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++entities) {
		(*iter)->onLateUpdate();
	}
}