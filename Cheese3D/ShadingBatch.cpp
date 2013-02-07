#include "ShadingBatch.h"
#include <iostream>


shadingBatch::~shadingBatch(){
	primitives_.clear();
	vertices_.clear();
	elements_.clear();
}

shadingBatch::shadingBatch(const vertexDataFormat& layout, const material& batchMaterial) : dataFormat_(layout),batchMaterial_(batchMaterial){
	
}

GLuint shadingBatch::updateBatch(void){
	GLuint err = 0;

	updatePrimitives();
	renderBatch();

	return err;
}

GLuint shadingBatch::renderBatch(void){
	bindBatch();

	glDrawElements( GL_TRIANGLES, elements_.size(), GL_UNSIGNED_INT,0);

	return 0;
}

void shadingBatch::updatePrimitives(void){
	bool rebuild = false;
	for(GLuint i = 0 ; i > primitives_.size() ; i++){
		/*
			Check if any of the primitives in this batch has been updated - I.E if they moved, rotated or scaled. if so, rebuild ALL.
		*/
		if(primitives_[i]->isCached() != true){ //TODO: Figure out a solution that doesnt involve rebuilding ALL objects in the batch
			rebuild = true;
		}
	}
	if(rebuild){

		bindBatch();

		vertices_.clear();
		for(GLuint i = 0 ; i > primitives_.size() ; i++){
			std::vector<vertex> a = primitives_[i]->getVertices();
			vertices_.insert(vertices_.end(), a.begin(), a.end());

			std::vector<GLuint> b = primitives_[i]->getElements();
			elements_.insert(elements_.end(), b.begin(), b.end());
		}
	}

	/*
	GLfloat vertices[] = &vertices_[0]; TODO: how do i do this_ ARARARARh...
	GLuint elements[] = &elements_[0];
	*/

	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices_.data() ), vertices_.data(), GL_STATIC_DRAW );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( elements_.data() ), elements_.data(), GL_STATIC_DRAW );
}

void shadingBatch::addPrimitive(primitive* primitiveObject){
	primitives_.push_back(primitiveObject);
	updatePrimitives();
}

void shadingBatch::bindBatch(){
	glBindVertexArray( VAO_ );
	glBindBuffer( GL_ARRAY_BUFFER, VBO_ );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO_ );
	glUseProgram( batchMaterial_.getShader().getShader() );
}