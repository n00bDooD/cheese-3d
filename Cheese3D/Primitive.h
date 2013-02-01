#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <vector>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtc\matrix_transform.hpp>

class primitive {
	glm::vec3 position_;
	glm::vec3 scale_;
	glm::quat rotation_;
	bool cached_;
public:
	primitive();
	primitive(glm::vec3);
	primitive(glm::vec3,glm::quat);
	primitive(glm::vec3,glm::quat,glm::vec3);

	virtual std::vector<vertex> getVertices() = 0;
	virtual std::vector<unsigned int> getElements() = 0;
	bool isCached(void);
	glm::mat4x4 getObjectMatrix(void);
} ;

#endif