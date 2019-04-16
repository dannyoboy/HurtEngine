#include "entity.h"

Entity::Entity(string * tagIn) : tag(tagIn) {};

string * Entity::getTag() {
	return tag;
}

void Entity::attachAudio(Audio * audio) {
	// TODO
}

void Entity::attachCollideable(Collideable * collideable) {
	// TODO
}

void Entity::attachDirectionalLight(DirectionalLight * directionalLight) {
	// TODO
}

void Entity::attachGUI(GUI * gui) {
	// TODO
}

void Entity::attachKinematics(Kinematics * kinematics) {
	// TODO
}

void Entity::attachMaterial(Material * material) {
	// TODO
}

void Entity::attachMesh(Mesh * mesh) {
	// TODO
}

void Entity::attachMousePicker(MousePicker * mousePicker) {
	// TODO
}

void Entity::attachPointLight(PointLight * pointLight) {
	// TODO
}

void Entity::attachSkybox(Skybox * skybox) {
	// TODO
}

void Entity::attachTransform(Transform * transform) {
	// TODO
}

Entity::~Entity() {
	// TODO
	delete tag;
}