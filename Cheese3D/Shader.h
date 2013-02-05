#ifndef SHADER_H
#define SHADER_H

#include <stdlib.h>
#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

class shader {
	friend class material;
protected:
	GLuint shader_;
	GLuint fragmentShader_;
	GLuint vertexShader_;

	bool compiled_;
	const char* fragmentSource_;
	const char* vertexSource_;
	void deallocate();
public:
	shader(const char*,const char*);
	void compileShader();
	bool isCompiled() const;
} ;

#endif