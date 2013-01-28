#include "Material.h"
#include <iostream>

material::material(const char* vertexShader, const char* fragmentShader){
	assert(vertexShader != NULL);
	assert(fragmentShader != NULL);
	fragmentShader_ = glCreateShader(GL_FRAGMENT_SHADER);
	vertexShader_ = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(fragmentShader_, 1,&fragmentShader,NULL);
	glShaderSource(vertexShader_, 1,&vertexShader,NULL);
	compiled_ = false;
}


void material::compileShaders(void){
	GLint status;
	char buffer[512];

	glCompileShader(vertexShader_);
	glGetShaderiv( vertexShader_, GL_COMPILE_STATUS, &status );
	if(status != GL_TRUE){
		glGetShaderInfoLog(vertexShader_,512,NULL,buffer);
		std::cout << buffer;
	}


	glCompileShader(fragmentShader_);
	glGetShaderiv( vertexShader_, GL_COMPILE_STATUS, &status );
	if(status != GL_TRUE){
		glGetShaderInfoLog(fragmentShader_,512,NULL,buffer);
		std::cout << buffer;
	}


	shaderProgram_ = glCreateProgram();
	glAttachShader(shaderProgram_, vertexShader_);
	glAttachShader(shaderProgram_, fragmentShader_);
	glBindFragDataLocation(shaderProgram_,0,"outColor");

	glLinkProgram(shaderProgram_);
	compiled_ = true;
}

unsigned int material::getShaderProgram(){
	if(!compiled_){
		compileShaders();
	}
	return shaderProgram_;
}