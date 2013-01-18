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
	~quad(void);
	glm::uint* getElements();
	std::vector<glm::mediump_float> getVertices();
	glm::vec3 getNormal();
} ;

#endif