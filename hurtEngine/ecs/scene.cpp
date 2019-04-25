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

		if (*entity->getTag() == *tag) {
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
		if (*(*iter)->getTag() == *tag) {
			entities->erase(iter);
			count++;
		}
	}

	return count;
}

void Scene::clear() {
	entities->clear();
}

void Scene::loadLights(Shader * entityShader) {
	int directionalLightIndex = 0;
	int pointLightIndex = 0;

	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Entity * entity = *iter;
		DirectionalLight * directionalLight = entity->getDirectionalLight();
		PointLight * pointLight = entity->getPointLight();

		if (directionalLight != nullptr) {
			directionalLight->load(entityShader, directionalLightIndex);
			directionalLightIndex++;
		}

		if (pointLight != nullptr) {
			pointLight->load(entityShader, pointLightIndex);
			pointLightIndex++;
		}
	}

	entityShader->loadInt(&string("numDirectionalLights"), directionalLightIndex);
	entityShader->loadInt(&string("numPointLights"), pointLightIndex);
}

void Scene::renderEntities(Shader * entityShader) {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Entity * entity = *iter;
		Transform * transform = entity->getTransform();
		Mesh * mesh = entity->getMesh();
		Material * material = entity->getMaterial();

		if (transform != nullptr && mesh != nullptr && material != nullptr) {
			Mat4 * transformationMatrix = transform->transformationMatrix();
			entityShader->loadMat4(&string("transform"), transformationMatrix);
			delete transformationMatrix;

			mesh->bind();
			material->loadAndBind(entityShader);

			glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
		}
	}
}

void Scene::renderBspheres(Shader * bsphereShader, hurt::Debug * debug) {
	if (!debug->getWireframeMode()) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Collideable * collideable = (*iter)->getCollideable();

		if (collideable != nullptr) {
			// TODO: bind custom sphere mesh
			collideable->load(bsphereShader);
			// TODO: render sphere
		}
	}

	if (!debug->getWireframeMode()) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Scene::loadProjectionMatrix(Shader * entityShader) {
	entityShader->loadMat4(&string("projection"), camera->projectionMatrix());
}

void Scene::loadView(Shader * entityShader) {
	Mat4 * view = camera->viewMatrix();
	entityShader->loadMat4(&string("view"), view);
	entityShader->loadVec3(&string("camLoc"), camera->getPos());
	delete view;
}

string * Scene::getName() {
	return name;
}

Camera * Scene::getCamera() {
	return camera;
}

Scene::~Scene() {
	delete entities;
}

// Engine-only methods

void Scene::updatePhysics() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		Entity * entity = *iter;
		Kinematics * kinematics = entity->getKinematics();
		Collideable * collideable = entity->getCollideable();

		if (kinematics != nullptr) {
			kinematics->update();
		}

		if (collideable != nullptr) {
			collideable->setColor(HURT_BSPHERE_DEFAULT);
		}
	}
}

void Scene::entityOnGameStart() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onGameStart();
	}
}

void Scene::entityOnGameStop() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onGameStop();
	}
}

void Scene::entityOnSceneLoad() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onSceneLoad();
	}
}

void Scene::entityOnSceneClose() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onSceneClose();
	}
}

void Scene::entityOnUpdate() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onUpdate();
	}
}

void Scene::entityOnLateUpdate() {
	for (list<Entity *>::iterator iter = entities->begin(); iter != entities->end(); ++iter) {
		(*iter)->onLateUpdate();
	}
}