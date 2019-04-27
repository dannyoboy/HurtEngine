# HurtEngine
A hobby project of Chris Hurt. This 3D C++ engine features a basic render engine, physics engine, input manager, and entity-component system.

## Blender Export Instructions
* Select File->Export->Wavefront (.obj)
* Set "Forward" to "Z Forward"
* Make sure the following are selected:
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
