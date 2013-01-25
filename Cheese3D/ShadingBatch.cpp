#include "ShadingBatch.h"

shadingBatch::shadingBatch(VertexType vertType,material*  mat){
	assert(mat != NULL);
	vertexType_ = vertType;
	material_ = mat;
	initBatch();
}

GLuint shadingBatch::renderBatch(void){
	GLuint err = 0;

	setupBatch();

	glDrawArrays(GL_TRIANGLES,0,vertices_.size());
	return err;
}

void shadingBatch::initBatch(void){
	glGenVertexArrays(1,&VAO_);
	glBindVertexArray(VAO_);

	glGenBuffers(1,&VBO_);
	glGenBuffers(1,&EBO_);

	setVertexAttributes();

	setVertexBuffer();
	updateVertexBuffer();

	setElementBuffer();
	updateElementBuffer();
}

void shadingBatch::setVertexBuffer(){
	glBindBuffer(GL_ARRAY_BUFFER,VBO_);
}

void shadingBatch::updateVertexBuffer(){
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices_.data() ), vertices_.data(), GL_STATIC_DRAW );
}

void shadingBatch::setElementBuffer(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO_);
}

void shadingBatch::updateElementBuffer(){
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO_ );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( elements_.data() ), elements_.data(), GL_STATIC_DRAW );
}

void shadingBatch::setVertexAttributes(){
	return;
	if(vertexType_ == simpleVertex){
		GLint posAttrib = glGetAttribLocation(material_->getShaderProgram(),"position");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,0,0);
	}
	if(vertexType_ == normalVertex){
		GLint posAttrib = glGetAttribLocation(material_->getShaderProgram(),"position");
		GLint normalAttrib = glGetAttribLocation(material_->getShaderProgram(),"normal");
		glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,0,(void*)(3 * sizeof(glm::vec3)));
		glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, GL_TRUE,3 * sizeof(glm::vec3),(void*)(3 * sizeof(glm::vec3)));
		glEnableVertexAttribArray(posAttrib);
		glEnableVertexAttribArray(normalAttrib);
	}
	if(vertexType_ == coloredVertex){
		GLint posAttrib = glGetAttribLocation(material_->getShaderProgram(),"position");
		GLint normalAttrib = glGetAttribLocation(material_->getShaderProgram(),"normal");
		GLint colorAttrib = glGetAttribLocation(material_->getShaderProgram(),"color");
		glEnableVertexAttribArray(posAttrib);
		glEnableVertexAttribArray(normalAttrib);
		glEnableVertexAttribArray(colorAttrib);
		glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,0,(void*)(7 * sizeof(glm::vec3)));
		glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, GL_TRUE,7 * sizeof(glm::vec3),(void*)(3 * sizeof(glm::vec3)));
		glVertexAttribPointer(colorAttrib, 4, GL_FLOAT, GL_FALSE,6 * sizeof(glm::vec3),(void*)(6 * sizeof(glm::vec3)));
	}
}

void shadingBatch::setupBatch(void){
	glUseProgram(material_->getShaderProgram());
	glBindVertexArray(VAO_);
}

void shadingBatch::addPrimitives(quad* primitive){
	assert(primitive != NULL);
	for(uint i = 0;i < 4;i++){
		vertex value = primitive->getVertices()[i];
		vertices_.push_back(value);
	}
	for(uint i = 0;i < 6;i++){
		GLuint value = primitive->getElements()[i];
		assert ( value != NULL);
		elements_.push_back(value);
	}
	updateVertexBuffer();
	updateElementBuffer();
}