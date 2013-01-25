#include "Vertices.h"

vertex::vertex (glm::vec3 position,glm::vec3 normal) : simpleVertex(position){
	normal_ = glm::normalize(normal);
}

vertex::vertex() : simpleVertex(glm::vec3()){
	normal_ = glm::vec3(0,0,1);
}

coloredVertex::coloredVertex(glm::vec3 position,glm::vec3 normal) : vertex(position,normal){
	color_ = glm::vec4((glm::mediump_float)1,(glm::mediump_float)1,(glm::mediump_float)1,(glm::mediump_float)1);
}

coloredVertex::coloredVertex() : vertex(glm::vec3(),glm::vec3(0,0,1)){
	color_ = glm::vec4((glm::mediump_float)1,(glm::mediump_float)1,(glm::mediump_float)1,(glm::mediump_float)1);
}

coloredVertex::coloredVertex(glm::vec3 position,glm::vec3 normal, glm::vec4 color) : vertex(position,normal){
	color_ = color;
}

simpleVertex::simpleVertex(){
	position_ = glm::vec3();
}
simpleVertex::simpleVertex(glm::vec3 position){
	position_ = position;
}

std::vector<glm::mediump_float> simpleVertex::getData(){
	glm::mediump_float arr[3] = {position_.x,position_.y,position_.z};
	std::vector<glm::mediump_float> vect (arr,arr + 3);
	return vect;
}
std::vector<glm::mediump_float> vertex::getData(){
	glm::mediump_float arr[6] = {position_.x,position_.y,position_.z,normal_.x,normal_.y,normal_.z};
	std::vector<glm::mediump_float> vect (arr,arr + 6);
	return vect;
}
std::vector<glm::mediump_float> coloredVertex::getData(){
	glm::mediump_float arr[10] = {position_.x,position_.y,position_.z,normal_.x,normal_.y,normal_.z,color_.x,color_.y,color_.z,color_.w};
	std::vector<glm::mediump_float> vect (arr,arr + 10);
	return vect;
}