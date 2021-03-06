#pragma once

// Dependencies
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

// Standard libraries
#include <iostream>
#include <math.h>

////////////////////////////
// Hurt Engine files
////////////////////////////

// Components
#include "hurtEngine/components/audio.h"
#include "hurtEngine/components/collideable.h"
#include "hurtEngine/components/directionalLight.h"
#include "hurtEngine/components/gui.h"
#include "hurtEngine/components/kinematics.h"
#include "hurtEngine/components/material.h"
#include "hurtEngine/components/mesh.h"
#include "hurtEngine/components/mousePicker.h"
#include "hurtEngine/components/pointLight.h"
#include "hurtEngine/components/skybox.h"
#include "hurtEngine/components/transform.h"

// Core
#include "hurtEngine/core/game.h"

// ECS
#include "hurtEngine/ecs/entity.h"
#include "hurtEngine/ecs/scene.h"

// GUI
#include "hurtEngine/gui/guiButton.h"
#include "hurtEngine/gui/guiImage.h"
#include "hurtEngine/gui/guiQuad.h"

// Input
#include "hurtEngine/input/buttons.h"
#include "hurtEngine/input/cursor.h"
#include "hurtEngine/input/inputManager.h"
#include "hurtEngine/input/keys.h"

// Math
#include "hurtEngine/math/mat4.h"
#include "hurtEngine/math/quaternion.h"
#include "hurtEngine/math/trig.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/math/vec4.h"

// Rendering
#include "hurtEngine/rendering/camera.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/rendering/texture.h"

// Utils
#include "hurtEngine/utils/debug.h"
#include "hurtEngine/utils/meshes.h"
#include "hurtEngine/utils/time.h"