#include "ShadingBatch.h"

shadingBatch::shadingBatch(VertexType vertType,material*  mat){
	vertexType_ = vertType;
	material_ = mat;
	initBatch();
}

GLuint shadingBatch::renderBatch(void){
	GLuint err = 0;

	err = setupBatch();
	if(err != 0){
		return err;
	}


	return err;
}

GLuint shadingBatch::setupBatch(void){
	glBindBuffer(GL_ARRAY_BUFFER,VBO_);
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices_.data() ), vertices_.data(), GL_STATIC_DRAW );
	return 1;
}

void shadingBatch::initBatch(void){
	glGenVertexArrays(1,&VAO_);
	glGenBuffers(1,&VBO_);
}