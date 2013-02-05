#include "Quad.h"

using namespace glm;

quad::quad() : primitive(){
}
quad::quad(vec3 position) : primitive(position){
}
quad::quad(vec3 position, quat rotation) : primitive (position,rotation){
}
quad::quad(vec3 position, quat rotation, vec3 scale) : primitive(position,rotation,scale){
}
quad::quad(std::vector<vertex> vertices) : primitive(){
	if(vertices.size() < 4){
		return;
	}
	for(unsigned int i;i < NUMBER_OF_VERTICES_IN_A_QUAD;i++){
		vertices_[i] = vertices[i];
	}
}
quad::quad(std::vector<vertex> vertices,vec3 position) : primitive(position){
	if(vertices.size() < 4){
		return;
	}
	for(unsigned int i;i < NUMBER_OF_VERTICES_IN_A_QUAD;i++){
		vertices_[i] = vertices[i];
	}
}
quad::quad(std::vector<vertex> vertices, vec3 position, quat rotation) : primitive (position,rotation){
	if(vertices.size() < 4){
		return;
	}
	for(unsigned int i;i < NUMBER_OF_VERTICES_IN_A_QUAD;i++){
		vertices_[i] = vertices[i];
	}
}
quad::quad(std::vector<vertex> vertices,vec3 position, quat rotation, vec3 scale) : primitive(position,rotation,scale){
	if(vertices.size() < 4){
		return;
	}
	for(unsigned int i;i < NUMBER_OF_VERTICES_IN_A_QUAD;i++){
		vertices_[i] = vertices[i];
	}
}

std::vector<vertex> quad::getVertices(){
	using namespace std;
	vector<vertex> result;

	for(unsigned int i = 0;i < NUMBER_OF_VERTICES_IN_A_QUAD;i++){
		result.push_back(vertices_[i]);
	}

	return result;
}
std::vector<unsigned int> quad::getElements(){
	using namespace std;
	vector<unsigned int> result;
	unsigned int elements[] = {0,2,3,0,1,2};

	for(unsigned int i = 0;i < NUMBER_OF_VERTICES_IN_A_TRIANGLE * 2;i++){
		result.push_back(elements[i]);
	}

	return result;
}