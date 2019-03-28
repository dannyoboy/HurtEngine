#pragma once

#include <string>
#include "hurtEngine/components/audio.h"
#include "hurtEngine/components/collideable.h"
#include "hurtEngine/components/gui.h"
#include "hurtEngine/components/kinematics.h"
#include "hurtEngine/components/light.h"
#include "hurtEngine/components/material.h"
#include "hurtEngine/components/mesh.h"
#include "hurtEngine/components/mousePicker.h"
#include "hurtEngine/components/skybox.h"
#include "hurtEngine/components/transform.h"

using namespace std;

class Entity {
public:
	Entity(string * tagIn);

	void attachAudio(Audio * audio);
	void attachCollideable(Collideable * collideable);
	void attachGUI(GUI * gui);
	void attachKinematics(Kinematics * kinematics);
	void attachLight(Light * light);
	void attachMaterial(Material * material);
	void attachMesh(Mesh * mesh);
	void attachMousePicker(MousePicker * mousePicker);
	void attachSkybox(Skybox * skybox);
	void attachTransform(Transform * transform);

	void onSceneLoad() {};
	void onSceneClose() {};
	void onAdd() {};
	void onRemove() {};
	void onUpdate() {};
	void onLateUpdate() {};

	~Entity();
private:
	string * tag;
	Audio * audio = nullptr;
	Collideable * collideable = nullptr;
	GUI * gui = nullptr;
	Kinematics * kinematics = nullptr;
	Light * light = nullptr;
	Material * material = nullptr;
	Mesh * mesh = nullptr;
	MousePicker * mousePicker = nullptr;
	Skybox * skybox = nullptr;
	Transform * transform = nullptr;
};