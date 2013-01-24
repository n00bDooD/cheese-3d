#ifndef VERTICES_H
#define VERTICES_H

#include <glm/glm.hpp>
#include <vector>

enum VertexType {simpleVertex = 3,normalVertex = 6,coloredVertex = 10};

class simpleVertex {
protected:
	glm::vec3 position_;
public:
	simpleVertex(void);
	simpleVertex(glm::vec3);
	~simpleVertex(void);
	std::vector<glm::mediump_float> getData();
} ;

class vertex : protected simpleVertex {
protected:
	glm::vec3 normal_;
public:
	vertex (glm::vec3,glm::vec3);
	vertex(void);
	~vertex(void);
	std::vector<glm::mediump_float> getData();
} ;

class coloredVertex : protected vertex {
protected:
	glm::vec4 color_;
public:
	coloredVertex(void);
	coloredVertex(glm::vec3,glm::vec3,glm::vec4);
	coloredVertex(glm::vec3,glm::vec3);
	~coloredVertex(void);
	std::vector<glm::mediump_float> getData();
} ;


#endif