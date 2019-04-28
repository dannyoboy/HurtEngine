// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"
#include "levelConstruct.h"
#include "enemy.h"

constexpr int WIDTH = 1400;
constexpr int HEIGHT = WIDTH;

constexpr int CAM_DISTANCE = 50;
constexpr int FOV = 60;

int main() {
	// Init game here
	Game * game = Game::instance();
	game->init(WIDTH, HEIGHT, &string("Dank game"), &Vec3(0.57f, 0.77f, 71));
	game->setDebugToolsEnabled(true);

	// Construct scenes here
	Camera * camera = new Camera(new Vec3(0, CAM_DISTANCE, 0), new Vec3(0, -1, 0), new Vec3(0, 0, 1), FOV, WIDTH, HEIGHT, 0.001f, 1000);
	string sceneName("main");
	Scene * scene = new Scene(&sceneName, camera);

	constructLevel(scene, CAM_DISTANCE, FOV);
	game->addScene(scene);

	

	// Start game here
	game->start();
	

	// Delete components here
	endLevel(scene);
	freeLevelComponents();

	return 0;
}