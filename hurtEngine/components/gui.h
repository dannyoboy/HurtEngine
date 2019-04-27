#pragma once

#include <list>
#include "hurtEngine/gui/guiImage.h"
#include "hurtEngine/gui/guiButton.h"

// TODO: fix/finish this component

// TODO: add GUIText components

class GUI {
public:
	void update();
	void render(Shader * guiImageShader);
	void attachImage(GUIImage * image);
	bool attachButton(GUIButton * button);
	GUIButton * getButton(string * id);
	~GUI();
private:
	inline GUI() {} // TODO: change to public
	list<GUIImage *> * images = new list<GUIImage *>();
	list<GUIButton *> * buttons = new list<GUIButton *>();
};