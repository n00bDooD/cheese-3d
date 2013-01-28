#include "CheeseRenderer.h"
#include <iostream>

GLuint cheeseRenderer::draw(void){
	glClearColor(0.2f,0.2f,0.2f,01.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	for(GLuint i = 0;i < batches_.size();i++){
		batches_[i]->renderBatch();
	}

	glfwSwapBuffers();
	return 0;
}

cheeseRenderer::cheeseRenderer(void){
}

void cheeseRenderer::addBatch(shadingBatch* batch){
	assert(batch != NULL);
	batches_.push_back(batch);
}