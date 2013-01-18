#include "CheeseRenderer.h"

cheeseRenderer::cheeseRenderer(void){

}

cheeseRenderer::~cheeseRenderer(void){
	delete primitives_;
}

void cheeseRenderer::addPrimitives(quad* arr){
	primitives_.insert(primitives_.size, arr,arr + sizeof(arr) / sizeof(quad));
}

bool cheeseRenderer::draw(void){

}