#pragma once

#include <string>

using namespace std;

// TODO: finish this component

class Audio {
public:
	void play();
	~Audio();
private:
	Audio(string * file); // TODO: change to public
};