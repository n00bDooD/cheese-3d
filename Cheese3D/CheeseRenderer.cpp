#include "CheeseRenderer.h"
#include <iostream>

GLuint cheeseRenderer::draw(void){
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	for(GLuint i = 0;i < batches_.size();i++){
		batches_[i].updateBatch();



	}

	glfwSwapBuffers();
	return 0;
}

cheeseRenderer::cheeseRenderer(shadingBatch batch){
	addBatch(batch);

	initBatch(0);
}

void cheeseRenderer::addBatch(shadingBatch batch){
	batches_.push_back(batch);
}

void cheeseRenderer::initBatch(GLuint index) {
	glGenVertexArrays(1,&batches_[index].VAO_);
	glBindVertexArray(batches_[index].VAO_);

	glGenBuffers(1,&batches_[index].VBO_);
	glBindBuffer(GL_ARRAY_BUFFER, batches_[index].VBO_);

	glGenBuffers(1, &batches_[index].EBO_);
	glBindBuffer(GL_ARRAY_BUFFER, batches_[index].EBO_);

	//batches[index].material.compile(); TODO: Implement

	//batches[index].definwVertexLayout(); TODO: Implement
}