#ifndef SHADINGBATCH_H
#define SHADINGBATCH_H

#include "Material.h"
#include "Vertices.h"
#include <vector>
#include "Quad.h"
#include <glm/glm.hpp>

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

class shadingBatch {
protected:
	std::vector<vertex> vertices_;
	std::vector<GLuint> elements_;
	VertexType vertexType_;
	material* material_;
	GLuint VAO_;
	GLuint VBO_;
	GLuint EBO_;
public:
	shadingBatch(VertexType,material*);
	GLuint renderBatch (void);
	void addPrimitives (quad*);
private:
	void initBatch(void);
	void setupBatch (void);
	void setVertexBuffer(void);
	void updateVertexBuffer(void);
	void setElementBuffer(void);
	void updateElementBuffer(void);
	void setVertexAttributes(void);
} ;

#endif