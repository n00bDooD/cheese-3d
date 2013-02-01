#ifndef SHADINGBATCH_H
#define SHADINGBATCH_H

#include <vector>
#include <glm/glm.hpp>

#include "Primitive.h"
#include "Vertex.h"

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

#include "VertexDataFormat.h"
#include "Material.h"

class shadingBatch {
	friend class cheeseRenderer;
protected:
	std::vector<primitive*> primitives_;
	std::vector<vertex> vertices_;
	std::vector<GLuint> elements_;
	vertexAttribLayout dataFormat_;
	material batchMaterial_;
	GLuint VAO_;
	GLuint VBO_;
	GLuint EBO_;
public:
	~shadingBatch();
	GLuint updateBatch (void);
	void addPrimitive (primitive*);
	shadingBatch(const vertexAttribLayout, const material);
private:
	void updatePrimitives (void);
	void setVertexAttributes(void);
} ;

#endif