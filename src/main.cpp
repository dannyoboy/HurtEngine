// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"
#include "controller.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = WIDTH;

int main() {
	// Init game here
	Game * game = Game::instance();
	game->init(WIDTH, HEIGHT, &string("Dank game"), &Vec3(0.7f, 0.7f, 1));
	game->setDebugToolsEnabled(true);

	// Construct scenes here
	Camera * camera = new Camera(new Vec3(0, 0, 0), new Vec3(0, 0, 1), new Vec3(0, 1, 0), 70, WIDTH, HEIGHT, 0.001f, 1000);
	string sceneName("mainScene");
	Scene * scene = new Scene(&sceneName, camera);

	string tag("myEntity");
	Entity * entity = new Entity(&tag);
	Transform * transform = new Transform(new Vec3(0, 0, 5), new Vec3(0, 0, 0), new Vec3(1, 1, 1));
	Mesh * mesh = HURT_SPHERE;
	Material * material = new Material(new Vec3(0, 0, 1), 0.2f, 0.4f, 0.7f, 8);
	PointLight * pointLight = new PointLight(new Vec3(1, 1, 1), 1, new Vec3(0.02f, 0.02f, 0.02f), new Vec3(0, 0, 0), 100);
	Kinematics * kinematics = new Kinematics(transform, new Vec3(1, 0, 0), new Vec3(30, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 1, 0), 2);
	MousePicker * mousePicker = new MousePicker(collideable, true);
	entity->attachTransform(transform);
	entity->attachMesh(mesh);
	entity->attachMaterial(material);
	entity->attachPointLight(pointLight);
	entity->attachKinematics(kinematics);
	entity->attachCollideable(collideable);
	entity->attachMousePicker(mousePicker);
	scene->addEntity(entity);

	string tag2("cameraController");
	Controller * controller = new Controller(&tag2);
	scene->addEntity(controller);

	game->addScene(scene);

	// Start game here
	game->start();

	// Delete components here
	delete transform;
	delete material;
	delete pointLight;
	delete kinematics;
	delete collideable;
	delete mousePicker;

	return 0;
}