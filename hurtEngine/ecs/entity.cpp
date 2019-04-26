#include "entity.h"

Entity::Entity(string * tagIn) : tag(tagIn) {};

string * Entity::getTag() {
	return tag;
}

void Entity::attachAudio(Audio * audio) {
	this->audio = audio;
}

void Entity::attachCollideable(Collideable * collideable) {
	this->collideable = collideable;
}

void Entity::attachDirectionalLight(DirectionalLight * directionalLight) {
	this->directionalLight = directionalLight;
}

void Entity::attachGUI(GUI * gui) {
	this->gui = gui;
}

void Entity::attachKinematics(Kinematics * kinematics) {
	this->kinematics = kinematics;
}

void Entity::attachMaterial(Material * material) {
	this->material = material;
}

void Entity::attachMesh(Mesh * mesh) {
	this->mesh = mesh;
}

void Entity::attachMousePicker(MousePicker * mousePicker) {
	this->mousePicker = mousePicker;
}

void Entity::attachPointLight(PointLight * pointLight) {
	this->pointLight = pointLight;
}

void Entity::attachSkybox(Skybox * skybox) {
	this->skybox = skybox;
}

void Entity::attachTransform(Transform * transform) {
	this->transform = transform;
}

Audio * Entity::getAudio() {
	return audio;
}

Collideable * Entity::getCollideable() {
	return collideable;
}

DirectionalLight * Entity::getDirectionalLight() {
	return directionalLight;
}

GUI * Entity::getGUI() {
	return gui;
}

Kinematics * Entity::getKinematics() {
	return kinematics;
}

Material * Entity::getMaterial() {
	return material;
}

Mesh * Entity::getMesh() {
	return mesh;
}

MousePicker * Entity::getMousePicker() {
	return mousePicker;
}

PointLight * Entity::getPointLight() {
	return pointLight;
}

Skybox * Entity::getSkybox() {
	return skybox;
}

Transform * Entity::getTransform() {
	return transform;
}

Entity::~Entity() {
	delete tag;
}