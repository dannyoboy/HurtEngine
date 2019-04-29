// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"
#include "levelConstruct.h"

constexpr int WIDTH = 1400;
constexpr int HEIGHT = WIDTH;

constexpr float CAM_DISTANCE = 50;
constexpr float FOV = 60;

int main() {
	// Init game here
	Game * game = Game::instance();
	game->init(WIDTH, HEIGHT, &string("Game of Drones"), &Vec3(0.57f, 0.77f, 71));
	game->setDebugToolsEnabled(true);

	// Construct scenes here
	Camera * camera = new Camera(new Vec3(0, CAM_DISTANCE, 0), new Vec3(0, -1, 0), new Vec3(0, 0, 1), FOV, WIDTH, HEIGHT, 0.01f, 1000);
	string sceneName("main");
	Scene * scene = new Scene(&sceneName, camera);
	constructLevel(scene, FOV, CAM_DISTANCE);
	game->addScene(scene);

	Camera * gameOverCamera = new Camera(new Vec3(0, CAM_DISTANCE, 0), new Vec3(0, -1, 0), new Vec3(0, 0, 1), FOV, WIDTH, HEIGHT, 0.01f, 1000);
	string gameOverSceneName("gameOver");
	Scene * gameOverScene = new Scene(&gameOverSceneName, gameOverCamera);
	constructGameOver(gameOverScene, FOV, CAM_DISTANCE);
	game->addScene(gameOverScene);

	// Start game here
	game->start();
	
	// Delete components here
	endLevel(scene);
	freeLevelComponents();

	return 0;
}