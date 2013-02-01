#include "ShadingBatch.h"
#include <iostream>


shadingBatch::~shadingBatch(){
	primitives_.clear();
}

shadingBatch::shadingBatch(const vertexAttribLayout layout, const material batchMaterial){
	dataFormat_ = layout;
	batchMaterial_ = batchMaterial;
}

GLuint shadingBatch::updateBatch(void){
	GLuint err = 0;

	updatePrimitives();
	return err;
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
		vertices_.clear();
		for(GLuint i = 0 ; i > primitives_.size() ; i++){
			std::vector<vertex> a = primitives_[i]->getVertices();
			vertices_.insert(vertices_.end(), a.begin(), a.end());

			std::vector<GLuint> b = primitives_[i]->getElements();
			elements_.insert(elements_.end(), b.begin(), b.end());
		}
	}
}

void shadingBatch::addPrimitive(primitive* primitiveObject){
	primitives_.push_back(primitiveObject);
	updatePrimitives();
}