#include "Quad.h"
#include"glm\glm.hpp"
#include "Vertices.h"

quad::quad(vertex topLeft,vertex topRight,vertex bottomRight,vertex bottomLeft,VertexType vertexType){
	vertexType_ = vertexType;
}

glm::uint* quad::getElements(){
	glm::uint arr[6] = {(glm::uint)0,(glm::uint)1,(glm::uint)2,(glm::uint)0,(glm::uint)2,(glm::uint)3};
	return arr;
}

std::vector<glm::mediump_float> quad::getRawVertexData(){
	const glm::lowp_uint vertCount = 4;
	const glm::lowp_uint vertType = vertexType_;

	std::vector<glm::mediump_float> arr;
	for(glm::lowp_uint i = 0;i < vertCount;i++){
		for(glm::lowp_uint j = 0;j < vertexType_;j++){
			arr.push_back(vertices_[i].getData()[j]);
		}
	}
	return arr;
}

vertex* quad::getVertices(){
	return vertices_;
}