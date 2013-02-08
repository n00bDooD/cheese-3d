#include "Vertex.h"

using namespace glm;

#pragma region Constructors
vertex::vertex(){
	position_ = vec3();
	normal_ = lowp_ivec3(0,1,0);
	UV_ = lowp_uvec2();
	color_ = lowp_uvec4(1,1,1,1);
}
vertex::vertex(vec3 position){
	position_ = position;
	normal_ = lowp_ivec3(0,1,0);
	UV_ = lowp_uvec2();
	color_ = lowp_uvec4(1,1,1,1);
}
vertex::vertex(vec3 position,lowp_ivec3 normal){
	position_ = position;
	normal_ = normal;
	UV_ = lowp_uvec2();
	color_ = lowp_uvec4(1,1,1,1);
}
vertex::vertex(vec3 position,lowp_ivec3 normal,lowp_uvec2 UV){
	position_ = position;
	normal_ = normal;
	UV_ = UV;
	color_ = lowp_uvec4(1,1,1,1);
}
vertex::vertex(vec3 position,lowp_ivec3 normal,lowp_uvec4 color){
	position_ = position;
	normal_ = normal;
	UV_ = lowp_uvec2();
	color_ = color;
}
vertex::vertex(vec3 position,lowp_ivec3 normal,lowp_uvec2 UV,lowp_uvec4 color){
	position_ = position;
	normal_ = normal;
	UV_ = UV;
	color_ = color;
}
#pragma endregion

#pragma region Getters/setters
	glm::vec3 vertex::getPosition( void ) const{
		return position_;
	}
	glm::lowp_ivec3 vertex::getNormal( void ) const{
		return normal_;
	}
	glm::lowp_uvec2 vertex::getUV( void ) const{
		return UV_;
	}
	glm::lowp_uvec4 vertex::getColor( void ) const{
		return color_;
	}
	std::vector<glm::float_t> vertex::getData ( void ) const{
		std::vector<float_t> values;

		vec3 pos = getPosition();
		lowp_ivec3 normal = getNormal();
		lowp_uvec2 UV = getUV();
		lowp_uvec4 color = getColor();

		values.push_back(pos.x);
		values.push_back(pos.y);
		values.push_back(pos.z);
		values.push_back(normal.x);
		values.push_back(normal.y);
		values.push_back(normal.z);
		values.push_back(UV.x);
		values.push_back(UV.y);
		values.push_back(color.x);
		values.push_back(color.y);
		values.push_back(color.z);
		values.push_back(color.w);

		return values;
	}
#pragma endregion