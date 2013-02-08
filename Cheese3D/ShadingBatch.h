#ifndef SHADINGBATCH_H
#define SHADINGBATCH_H

#include <vector>
#include <glm/glm.hpp>

#include "Material.h"
#include "Primitive.h"
#include "Vertex.h"

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

#include "VertexDataFormat.h"

class shadingBatch {
	friend class cheeseRenderer;
protected:
	std::vector<primitive*> primitives_;
	std::vector<float> vertices_;
	std::vector<GLuint> elements_;
	vertexDataFormat dataFormat_;
	material batchMaterial_;
	GLuint VAO_;
	GLuint VBO_;
	GLuint EBO_;
public:
	~shadingBatch();
	GLuint updateBatch (void);
	GLuint renderBatch(void);
	void addPrimitive (primitive*);
	shadingBatch(const vertexDataFormat&, const material&);
private:
	void updatePrimitives (void);
	void bindBatch();
} ;

#endif