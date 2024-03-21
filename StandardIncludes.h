#ifndef STANDARD_INCLUDES_H 
#define STANDARD_INCLUDES 

#define GLM_ENABLE_EXPERIMENTAL

// Include standard headers
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// Widows specific includes and defines
#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); glfwTerminate(); } 
#endif

// Openg GL/Helper headers
#include "../External/glew-2.1.0/include/GL/glew.h"  // Include GLEW
#include "../External/glfw-3.3.4/include/GLFW/glfw3.h" // Include GLFW
#include "../External/glm/glm/glm.hpp" // Include GLM
#include "../External/glm/glm/ext.hpp" // OpenGL experimental to_string
#include "../External/glm/glm/gtc/matrix_transform.hpp" //transformation file //view-projection

#include "Resolution.h"
#include "Singleton.h"

using namespace std;

#endif // STANDARD_INCLUDES_H
