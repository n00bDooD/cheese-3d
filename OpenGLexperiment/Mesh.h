#pragma once
#include <list>
#define GLEW_STATIC
#include <GL\glew.h>
#define GLFWDLL
#include <GL\glfw.h>
#include <GL\GLU.h>

class Mesh
{
protected:
	GLfloat* m_vertices;
	GLuint* m_elements;
public:
	GLfloat* GetVertices();
	GLuint* GetElements();
	void SetVertices(GLfloat* verts);
	void SetElements(GLuint* elems);
	Mesh(GLfloat* vertices,GLuint* elements);
	~Mesh(void);
};

