#ifndef VERTEX_H
#define VERTEX_H

#include <glm\glm.hpp>

class vertex {
protected:
	glm::vec3 position_;
	glm::lowp_ivec3 normal_;
	glm::lowp_uvec2 UV_;
	glm::lowp_uvec4 color_;
public:
#pragma region Constructors
	vertex();
	vertex(glm::vec3);
	vertex(glm::vec3 position,glm::lowp_ivec3 normal);
	vertex(glm::vec3 position,glm::lowp_ivec3 normal,glm::lowp_uvec2 UV);
	vertex(glm::vec3 position,glm::lowp_ivec3 normal,glm::lowp_uvec4 color);
	vertex(glm::vec3 position,glm::lowp_ivec3 normal,glm::lowp_uvec2 UV,glm::lowp_uvec4 color);
#pragma endregion

#pragma region Getters
	glm::vec3 getPosition( void ) const;
	glm::lowp_ivec3 getNormal( void ) const;
	glm::lowp_uvec2 getUV( void ) const;
	glm::lowp_uvec4 getColor( void ) const;
#pragma endregion
} ;

#endif