#include "VertexDataFormat.h"

vertexAttrib::vertexAttrib()  : name(""), size(0), type(GL_INT), normalized(false){
}
vertexAttrib::vertexAttrib(const vertexAttrib& other) : name(other.name), size(other.size), type(other.type), normalized(other.normalized){
}
vertexAttrib::vertexAttrib(char* name,GLint size,GLenum type,GLboolean normalized) : name(name), size(size), type(type), normalized(normalized){
}

void vertexDataFormat::addAttribute(vertexAttrib& attrib){
	vertexAttributes_.push_back(attrib);
}
void vertexDataFormat::deleteAttribute(char* name){
	GLuint index = -1;
	for(unsigned int i = 0; i < vertexAttributes_.size();i++){
		if(name == vertexAttributes_[i].name){
			index = i;
		}
	}
	if(index == -1){
		throw VERTEX_ATTRIBUTE_NOT_FOUND;
	}
	vertexAttributes_.erase(vertexAttributes_.begin() + index);
}

vertexAttrib& vertexDataFormat::getAttribute(char* name){
	for(unsigned int i = 0; i < vertexAttributes_.size();i++){
		if(name == vertexAttributes_[i].name){
			return vertexAttributes_[i];
		}
	}
	throw VERTEX_ATTRIBUTE_NOT_FOUND;
}
vertexAttrib& vertexDataFormat::getAttribute(unsigned int index){
	return vertexAttributes_[index];
}
int vertexDataFormat::count() const{
	return vertexAttributes_.size();
}