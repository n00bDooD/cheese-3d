#include "CheeseRenderer.h"
#include <iostream>

GLuint cheeseRenderer::draw(void){
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	for(GLuint i = 0;i < batches_.size();i++){
		batches_[i]->updateBatch();
	}

	glfwSwapBuffers();
	return NO_ERROR;
}

cheeseRenderer::cheeseRenderer(shadingBatch* pbatch){
	addBatch(pbatch);

	initBatch(0);
}

void cheeseRenderer::addBatch(shadingBatch* pbatch){
	batches_.push_back(pbatch);
}

void cheeseRenderer::initBatch(GLuint index) {
	if(!batches_[index]->initiated_){
		glGenVertexArrays(1,&batches_[index]->VAO_);
		glBindVertexArray(batches_[index]->VAO_);

		glGenBuffers(1,&batches_[index]->VBO_);
		glBindBuffer(GL_ARRAY_BUFFER, batches_[index]->VBO_);

		glGenBuffers(1, &batches_[index]->EBO_);
		glBindBuffer(GL_ARRAY_BUFFER, batches_[index]->EBO_);

		batches_[index]->batchMaterial_.compileShader();

		batches_[index]->batchMaterial_.defineVertexAttributes(batches_[index]->dataFormat_);

		batches_[index]->batchMaterial_.linkVertexAttributes(batches_[index]->dataFormat_);

		batches_[index]->initiated_ = true;
	}
}