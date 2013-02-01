#include "Primitive.h"
#include <stdlib.h>

using namespace glm;

primitive::primitive(){
	position_ = vec3();
	scale_ = vec3(1,1,1);
	rotation_ = quat();
	cached_ = false;
}
primitive::primitive(vec3 position){
	position_ = position;
	scale_ = vec3(1,1,1);
	rotation_ = quat();
	cached_ = false;
}
primitive::primitive(vec3 position,quat rotation){
	position_ = position;
	scale_ = vec3(1,1,1);
	rotation_ = rotation;
	cached_ = false;
}
primitive::primitive(vec3 position,quat rotation,vec3 scale){
	position_ = position;
	scale_ = scale;
	rotation_ = rotation;
	cached_ = false;
}

bool primitive::isCached(){
	return cached_;
}

mat4x4 primitive::getObjectMatrix() {
	mat4x4 result = mat4_cast(rotation_);
	result = scale(result,scale_);
	result = translate(result,position_);
	return result;
}