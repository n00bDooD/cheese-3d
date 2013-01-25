#ifndef QUAD_H
#define QUAD_H

#include "Vertices.h"
#include <vector>

class quad {
protected:
	vertex vertices_[4];
	VertexType vertexType_;
public:
	quad(vertex,vertex,vertex,vertex,VertexType);
	glm::uint* getElements();
	std::vector<glm::mediump_float> getRawVertexData();
	glm::vec3 getNormal();
	vertex* getVertices();
} ;

#endif