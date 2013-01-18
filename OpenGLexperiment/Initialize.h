#ifndef INITIALIZE_H
#define INITIALIZE_H

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

GLuint initialize (void);
GLuint initGlew (void);
GLuint initGlfw (void);
#endif