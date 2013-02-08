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
	for(GLuint i = 0 ; i < primitives_.size() ; i++){
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
		elements_.clear();
		unsigned int vertAmount = 0;
		for(GLuint i = 0 ; i <  primitives_.size() ; i++){
			std::vector<GLuint> b = primitives_[i]->getElements();

			for(unsigned int k = 0;k<b.size();k++){
				b[k] += vertAmount;
			}

			elements_.insert(elements_.end(), b.begin(), b.end());
			std::vector<vertex> a = primitives_[i]->getVertices();
			std::vector<float> ab;

			vertAmount += a.size();

			for(unsigned int j = 0;j < a.size();j++){
				std::vector<float> data = a[j].getData();
				ab.insert(ab.end(),data.begin(),data.end());
			}
			vertices_.insert(vertices_.end(), ab.begin(), ab.end());
		}

		glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * vertices_.size(), vertices_.data(), GL_STATIC_DRAW );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * elements_.size(), elements_.data(), GL_STATIC_DRAW );
	}
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