# HurtEngine
A hobby project of Chris Hurt. This 3D C++ engine features a basic render engine, physics engine, input manager, and entity-component system.

## Blender Export Instructions
* Select File->Export->Wavefront (.obj)
* Set "Forward" to "Z Forward"
* Make sure only the following are selected:
  * Apply Modifiers *(optional)*
  * Write Normals
  * Include UVs *(optional)*
  * Triangulate Faces
  * Objects as OBJ Objects
* Export to project "res/" folder

## Image Format
* 32-bit PNG
* Square
* 2<sup>n</sup> side length
* All alpha values set to 0 or 1

## VS17 Setup
TODO

## API

### Components
#### Collideable
Collideable(Transform * transformIn, Vec3 * offsetIn, float radiusIn);  
Vec3 * collisionWith(Collideable * collideable);  
Vec3 * worldCenter();  
void setColor(Vec3 * colorIn);  
void setPicked(float pickedIn);  
float getRadius();
#### DirectionalLight
DirectionalLight(Vec3 * colorIn, float intensityIn, Vec3 * directionIn);  
Vec3 * getColor();  
	void setColor(Vec3 * colorIn);  
	float getIntensity();  
	void setIntensity(float intensityIn);  
	Vec3 * getDirection();  
	void setDirection(Vec3 * directionIn);
 #### Kinematics
 Kinematics(Transform * transformIn, Vec3 * velIn, Vec3 * angVelIn, Vec3 * accIn, Vec3 * angAccIn);  
 Vec3 * getVel();  
	void setVel(Vec3 * velIn);  
	Vec3 * getAngVel();  
	void setAngVel(Vec3 * angVelIn);  
	Vec3 * getAcc();  
	void setAcc(Vec3 * accIn);  
	Vec3 * getAngAcc();  
	void setAngAcc(Vec3 * angAccIn);
 #### Material
 Material(Vec3 * colorIn, float ambientIn, float diffuseIn, float specularIn, int shininessIn);  
	Material(string * diffuseMapFile, float ambientIn, float diffuseIn, float specularIn, int shininessIn);  
	Material(string * diffuseMapFile, string * lightMapFile, int shininessIn);
 #### Mesh
 Mesh(string * objFile);
 #### MousePicker
 MousePicker(Collideable * collideableIn, bool enabledIn);  
 bool isSelected();  
	bool isEnabled();  
	void setEnabled(bool enabledIn);
 #### PointLight
 PointLight(Vec3 * colorIn, float intensityIn, Vec3 * attenuationIn, Vec3 * positionIn, float rangeIn);  
 Vec3 * getColor();  
	void setColor(Vec3 * colorIn);  
	float getIntensity();  
	void setIntensity(float intensityIn);  
	Vec3 * getAttenuation();  
	void setAttenuation(Vec3 * attenuationIn);  
	Vec3 * getPosition();  
	void setPosition(Vec3 * positionIn);  
	float getRange();  
	void setRange(float rangeIn);
 #### Skybox
 Skybox(string textures[], Vec3 * rotIn); // Texture order: R, L, U, D, F, B  
 Vec3 * getRotation();  
	void setRotation(Vec3 * rotIn);
 #### Transform
 Transform(Vec3 * posIn, Vec3 * rotIn, Vec3 * scaleIn);  
 Vec3 * applyRotationTo(Vec3 * offset);  
	Vec3 * getPos();  
	void setPos(Vec3 * posIn);  
	Vec3 * getRot();  
	void setRot(Vec3 * rotIn);  
	Vec3 * getScale();  
	void setScale(Vec3 * scaleIn);

### Core
#### Game
static Game * instance();  
	void init(int width, int height, string * title, Vec3 * clearColor);  
	void start();  
	void setClearColor(Vec3 * clearColor);  
	bool addScene(Scene * scene);  
	Scene * getScene(string * name);  
	bool setCurrentScene(string * name);  
	void setDebugToolsEnabled(bool enabled);  
	Vec2 * getWindowSize();  
	float getAspectRatio();  
	bool isInitialized();  
	void close(int status);

### ECS
#### Entity
Entity(string * tagIn);  
	string * getTag();  
	void attachCollideable(Collideable * collideable);  
	void attachDirectionalLight(DirectionalLight * directionalLight);  
	void attachKinematics(Kinematics * kinematics);  
	void attachMaterial(Material * material);  
	void attachMesh(Mesh * mesh);  
	void attachMousePicker(MousePicker * mousePicker);  
	void attachPointLight(PointLight * pointLight);  
	void attachSkybox(Skybox * skybox);  
	void attachTransform(Transform * transform);  
	Collideable * getCollideable();  
	DirectionalLight * getDirectionalLight();  
	Kinematics * getKinematics();  
	Material * getMaterial();  
	Mesh * getMesh();  
	MousePicker * getMousePicker();  
	PointLight * getPointLight();  
	Skybox * getSkybox();  
	Transform * getTransform();  
	bool isActive();  
	void setActive(bool activeIn);  
	virtual void onGameStart() {};  
	virtual void onGameStop() {};  
	virtual void onSceneLoad() {};  
	virtual void onSceneClose() {};  
	virtual void onAdd() {};  
	virtual void onRemove() {};  
	virtual void onUpdate() {};  
	virtual void onLateUpdate() {};
#### Scene
inline Scene(string * nameIn, Camera * cameraIn);  
	void addEntity(Entity * entity);  
	list<Entity *> * getEntities(string * tag);  
	list<Entity *> * getEntities();  
	bool removeEntity(Entity * entity);  
	int removeEntities(string * tag);  
	void clear();  
	string * getName();  
	Camera * getCamera();

### Input
#### Buttons
bool hurtButtonPressed(int button);  
bool hurtButtonDown(int button);  
bool hurtButtonReleased(int button);
#### Cursor
Vec2 * hurtGetCursorPos();  
void hurtSetCursorPos(Vec2 * pos);  
void hurtSetCursorVisible(bool visible);
#### Keys
bool hurtKeyPressed(int key);  
bool hurtKeyDown(int key);  
bool hurtKeyReleased(int key);

### Math
#### Mat4
Mat4(float * valsIn);  
	float getVal(int row, int col);  
	float * getVals();  
	Mat4 * add(Mat4 * mat);  
	Mat4 * sub(Mat4 * mat);  
	Mat4 * mul(Mat4 * mat);  
	Mat4 * mul(float val);  
	Vec4 * mul(Vec4 * vec);  
	Mat4 * transpose();  
	Mat4 * inverse();
#### Quaternion
float x, y, z, w;  
	Quaternion(float xIn, float yIn, float zIn, float wIn);  
	Quaternion * conjugated();  
	Quaternion * mul(float vecX, float vecY, float vecZ);  
	Quaternion * mul(Quaternion * quat);
#### Trig
constexpr float HURT_PI = 3.14159265f;  
float hurtDegToRad(float deg);  
float hurtRadToDeg(float rad);
#### Vec2
float x, y;  
	inline Vec2(float xIn, float yIn);  
	Vec2 * add(Vec2 * vec);  
	Vec2 * sub(Vec2 * vec);  
	Vec2 * mul(float val);  
	Vec2 * pieceMul(Vec2 * vec);  
	float dot(Vec2 * vec);  
	Vec2 * normalized();  
	float length();  
	float angleBetween(Vec2 * vec);
#### Vec3
float x, y, z;  
	inline Vec3(float xIn, float yIn, float zIn);  
	Vec3 * add(Vec3 * vec);  
	Vec3 * sub(Vec3 * vec);  
	Vec3 * mul(float val);  
	Vec3 * pieceMul(Vec3 * vec);  
	float dot(Vec3 * vec);  
	Vec3 * normalized();  
	float length();  
	float angleBetween(Vec3 * vec);  
	Vec3 * cross(Vec3 * vec);  
	void rotate(Vec3 * axis, float theta);
#### Vec4
float x, y, z, w;  
	inline Vec4(float xIn, float yIn, float zIn, float wIn);  
	Vec4 * add(Vec4 * vec);  
	Vec4 * sub(Vec4 * vec);  
	Vec4 * mul(float val);  
	Vec4 * pieceMul(Vec4 * vec);  
	float dot(Vec4 * vec);  
	Vec4 * normalized();  
	float length();  
	float angleBetween(Vec4 * vec);

### Rendering
#### Camera
Camera(Vec3 * posIn, Vec3 * forwardIn, Vec3 * upIn, float fov, int windowWidth, int windowHeight, float zNear, float zFar);  
	void moveRight(float delta);  
	void moveUp(float delta);  
	void moveForward(float delta);  
	void moveY(float delta);  
	void moveRightXZ(float delta);  
	void moveForwardXZ(float delta);  
	void turnHorizontal(float delta);  
	void turnVertical(float delta);  
	bool isLocked();  
	void setLocked(bool locked);  
	float getTurnSpeed();  
	void setTurnSpeed(float speed);  
	Vec3 * getPos();  
	void setPos(Vec3 * posIn);  
	Vec3 * getForward();  
	Vec3 * getUp();

### Utils
#### Meshes
extern Mesh * HURT_CUBE;  
extern Mesh * HURT_PLANE;  
extern Mesh * HURT_SPHERE;  
extern Mesh * HURT_QUAD;
#### Time
static Time * instance();  
	float getDelta();
