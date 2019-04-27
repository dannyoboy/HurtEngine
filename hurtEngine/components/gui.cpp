#include "gui.h"

void GUI::update() {
	for (list<GUIButton *>::iterator iter = buttons->begin(); iter != buttons->end(); ++iter) {
		(*iter)->update();
	}
}

void GUI::render(Shader * guiImageShader) {
	for (list<GUIButton *>::iterator iter = buttons->begin(); iter != buttons->end(); ++iter) {
		(*iter)->loadAndRender(guiImageShader);
	}

	for (list<GUIImage *>::iterator iter = images->begin(); iter != images->end(); ++iter) {
		(*iter)->loadAndRender(guiImageShader);
	}
}

void GUI::attachImage(GUIImage * image) {
	images->push_back(image);
}

bool GUI::attachButton(GUIButton * button) {
	for (list<GUIButton *>::iterator iter = buttons->begin(); iter != buttons->end(); ++iter) {
		if (*button->getID() == *(*iter)->getID()) {
			return false;
		}
	}

	buttons->push_back(button);
	return true;
}

GUIButton * GUI::getButton(string * id) {
	for(list<GUIButton *>::iterator iter = buttons->begin(); iter != buttons->end(); ++iter) {
		GUIButton * button = *iter;

		if (*id == *button->getID()) {
			return button;
		}
	}

	return nullptr;
}

GUI::~GUI() {
	delete images;
	delete buttons;
}