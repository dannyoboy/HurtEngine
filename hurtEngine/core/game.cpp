#include "game.h"

static Game * gameInstance = nullptr;

// Public

Game * Game::instance() {
	if (gameInstance == nullptr) {
		gameInstance = new Game();
	}

	return gameInstance;
}

void Game::init(int width, int height, string * title, Vec3 * clearColor) {
	initContext();
	window = createWindow(width, height, title);
	checkGLAD();
	initConfig(clearColor);
	windowSize = new Vec2((float)width, (float)height);
	aspectRatio = (float)width / height;
	hurt::hurtMeshesInit();
	hurt::initInput(window, windowSize);
	entityShader = new Shader(&string("hurtEngine/shaders/entityVertex.glsl"), &string("hurtEngine/shaders/entityFragment.glsl"));
	bsphereShader = new Shader(&string("hurtEngine/shaders/bsphereVertex.glsl"), &string("hurtEngine/shaders/bsphereFragment.glsl"));
	skyboxShader = new Shader(&string("hurtEngine/shaders/skyboxVertex.glsl"), &string("hurtEngine/shaders/skyboxFragment.glsl"));
	guiImageShader = new Shader(&string("hurtEngine/shaders/guiImageVertex.glsl"), &string("hurtEngine/shaders/guiImageFragment.glsl"));
	debug = new hurt::Debug();
	initialized = true;
}

void Game::start() {
	if (currScene == nullptr) {
		cerr << "No current scene set" << endl;
		exit(-1);
	}

	runOnGameStart();
	Time::instance()->markDelta();
	gameLoop(window);
	runOnGameStop();
	delete this;
}

void Game::resizeWindow(int width, int height) {
	glfwSetWindowSize(window, width, height);
}

void Game::setClearColor(Vec3 * clearColor) {
	glClearColor(clearColor->x, clearColor->y, clearColor->z, 1.0f);
}

bool Game::addScene(Scene * scene) {
	for (list<Scene *>::iterator iter = scenes->begin(); iter != scenes->end(); ++iter) {
		if (*(*iter)->getName() == *scene->getName()) {
			return false;
		}
	}

	scenes->push_back(scene);

	if (currScene == nullptr) {
		setCurrentScene(scene->getName());
	}

	return true;
}

Scene * Game::getScene(string * name) {
	for (list<Scene *>::iterator iter = scenes->begin(); iter != scenes->end(); ++iter) {
		Scene * scene = *iter;
		
		if (*scene->getName() == *name) {
			return scene;
		}
	}

	return nullptr;
}

bool Game::setCurrentScene(string * name) {
	for (list<Scene *>::iterator iter = scenes->begin(); iter != scenes->end(); ++iter) {
		Scene * scene = *iter;

		if (*scene->getName() == *name) {
			if (currScene != nullptr) {
				currScene->entityOnSceneClose();
			}

			currScene = scene;
			
			entityShader->use();
			currScene->loadProjectionMatrix(entityShader);
			bsphereShader->use();
			currScene->loadProjectionMatrix(bsphereShader);
			skyboxShader->use();
			currScene->loadProjectionMatrix(skyboxShader);

			currScene->entityOnSceneLoad();
			return true;
		}
	}

	return false;
}

void Game::setDebugToolsEnabled(bool enabled) {
	debug->enabled(enabled);
}

Vec2 * Game::getWindowSize() {
	return windowSize;
}

float Game::getAspectRatio() {
	return aspectRatio;
}

bool Game::isInitialized() {
	return initialized;
}

void Game::close(int status) {
	if (status) {
		cerr << "Game terminated early" << endl;
		exit(-1);
	}
	else {
		closed = true;
	}
}

// Private

void Game::initContext() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

GLFWwindow * Game::createWindow(int width, int height, string * title) {
	GLFWwindow* newWindow = glfwCreateWindow(width, height, title->c_str(), NULL, NULL);

	if (newWindow == NULL) {
		cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(newWindow);
	glfwSetFramebufferSizeCallback(newWindow, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	return newWindow;
}

void Game::checkGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		exit(-1);
	}
}

void Game::initConfig(Vec3 * clearColor) {
	setClearColor(clearColor);
	glEnable(GL_DEPTH_TEST);
	stbi_set_flip_vertically_on_load(true);
}

void Game::gameLoop(GLFWwindow * window) {
	while (!(glfwWindowShouldClose(window) || closed)) {
		Time::instance()->markDelta();
		frameTime += Time::instance()->getDelta();

		if (frameTime >= TIME_SYNC) {
			frameTime -= TIME_SYNC;

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			hurt::updateInput(window);
			debug->update();
			updateCurrentScene();
			renderCurrentScene();
			glfwSwapBuffers(window);
		}
	}
}

void Game::updateCurrentScene() {
	currScene->getCamera()->updateLocked(windowSize);
	currScene->updateComponents();
	currScene->entityOnUpdate();
	currScene->entityOnLateUpdate();
}

void Game::renderCurrentScene() {
	entityShader->use();
	currScene->loadView(entityShader);
	currScene->loadLights(entityShader);
	currScene->renderEntities(entityShader);

	Mat4 * view = currScene->getCamera()->viewMatrix();

	if (debug->getShowBspheres()) {
		bsphereShader->use();
		bsphereShader->loadMat4(&string("view"), view);
		currScene->renderBspheres(bsphereShader, debug);
	}

	skyboxShader->use();
	skyboxShader->loadMat4(&string("view"), view);
	currScene->renderSkyboxes(skyboxShader);

	guiImageShader->use();
	currScene->renderGUIs(guiImageShader);

	delete view;
}

void Game::runOnGameStart() {
	for (list<Scene *>::iterator iter = scenes->begin(); iter != scenes->end(); ++iter) {
		(*iter)->entityOnGameStart();
	}
}

void Game::runOnGameStop() {
	for (list<Scene *>::iterator iter = scenes->begin(); iter != scenes->end(); ++iter) {
		(*iter)->entityOnGameStop();
	}
}

Game::~Game() {
	delete scenes;
	hurt::hurtMeshesDestroy();
	delete entityShader;
	delete bsphereShader;
	delete skyboxShader;
	delete guiImageShader;
	delete Time::instance();
	delete debug;
	delete windowSize;
	glfwTerminate();
}