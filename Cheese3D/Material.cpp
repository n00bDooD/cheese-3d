#include "Material.h"

material::material(const char* vertexShader, const char* fragmentShader){
	assert(vertexShader != NULL);
	assert(fragmentShader != NULL);
	glShaderSource(fragmentShader_, 1,&fragmentShader,NULL);
	glShaderSource(vertexShader_, 1,&vertexShader,NULL);
}


void material::compileShaders(void){
	glCompileShader(vertexShader_);
	glCompileShader(fragmentShader_);

	shaderProgram_ = glCreateProgram();
	glAttachShader(shaderProgram_, vertexShader_);
	glAttachShader(shaderProgram_, fragmentShader_);
	glBindFragDataLocation(shaderProgram_,0,"outColor");

	glLinkProgram(shaderProgram_);
}

unsigned int material::getShaderProgram(){
	return shaderProgram_;
}