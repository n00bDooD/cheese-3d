#ifndef QUAD_H
#define QUAD_H
#define NUMBER_OF_VERTICES_IN_A_QUAD 4
#define NUMBER_OF_VERTICES_IN_A_TRIANGLE 3


#include "Primitive.h"
#include "Vertex.h"
#include <vector>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtc\matrix_transform.hpp>

class quad : public primitive {
private:
	vertex vertices_[NUMBER_OF_VERTICES_IN_A_QUAD];
public:
	quad();
	quad(glm::vec3);
	quad(glm::vec3,glm::quat);
	quad(glm::vec3,glm::quat,glm::vec3);
	quad(std::vector<vertex>);
	quad(std::vector<vertex>,glm::vec3);
	quad(std::vector<vertex>,glm::vec3,glm::quat);
	quad(std::vector<vertex>,glm::vec3,glm::quat,glm::vec3);

	void setSize(float, float);

	std::vector<vertex> getVertices();
	std::vector<unsigned int> getElements();
} ;

#endif