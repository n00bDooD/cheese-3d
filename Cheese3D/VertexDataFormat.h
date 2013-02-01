#ifndef VERTEXDATAFORMAT_H
#define VERTEXDATAFORMAT_H

#define GLFWDLL
#include <GL\glfw.h>

struct vertexAttribLayout {
	GLuint index;
	GLint size;
	GLenum type;
	GLboolean normalized;
	GLsizei stride;
	GLuint* VAO_;
} ;

#endif