#ifndef GLOBAL_H
#define GLOBAL_H

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

#include <assert.h>

typedef GLuint uint;

//Exeptions

#define NO_ERROR 0
#define CLOSE_APPLICATION 1
#define GLFW_INIT_FAIL 1000
#define GLEW_INIT_FAIL 1001
#define OPEN_WINDOW_FAIL 1002
#define VERTEX_SHADER_COMPILE_FAIL 1003
#define FRAGMENT_SHADER_COMPILE_FAIL 1004
#define	VERTEX_ATTRIBUTE_NOT_FOUND 1005

#endif