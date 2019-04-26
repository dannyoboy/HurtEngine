#pragma once

#include <string>
#include <list>
#include "hurtEngine/ecs/entity.h"
#include "hurtEngine/rendering/camera.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/utils/debug.h"
#include "hurtEngine/utils/meshes.h"

using namespace std;

class Scene {
public:
	inline Scene(string * nameIn, Camera * cameraIn) : name(nameIn), camera(cameraIn) {}
	void addEntity(Entity * entity);
	list<Entity *> * getEntities(string * tag);
	list<Entity *> * getEntities();
	bool removeEntity(Entity * entity);
	int removeEntities(string * tag);
	void clear();
	void loadLights(Shader * entityShader);
	void renderEntities(Shader * entityShader);
	void renderBspheres(Shader * bsphereShader, hurt::Debug * debug);
	void renderSkyboxes(Shader * skyboxShader);
	void loadProjectionMatrix(Shader * entityShader);
	void loadView(Shader * entityShader);
	string * getName();
	Camera * getCamera();
	~Scene();

	// Engine-only methods
	void updatePhysics();
	void entityOnGameStart();
	void entityOnGameStop();
	void entityOnSceneLoad();
	void entityOnSceneClose();
	void entityOnUpdate();
	void entityOnLateUpdate();
private:
	string * name;
	Camera * camera;
	list<Entity *> * entities = new list<Entity *>();
};