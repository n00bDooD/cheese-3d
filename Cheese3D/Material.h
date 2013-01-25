#ifndef MATERIAL_H
#define MATERIAL_H

#include "Global.h"

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

class material {
protected:
	GLuint fragmentShader_;
	GLuint vertexShader_;
	unsigned int shaderProgram_;
	void compileShaders(void);
public:
	material(const char*,const  char*);
	unsigned int getShaderProgram(void);
} ;

#endif