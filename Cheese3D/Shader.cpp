#include "Shader.h"

shader::shader(const char* fragmentSource,const char* vertexSource) {
	fragmentSource_ = fragmentSource;
	vertexSource_ = vertexSource;
	compiled_ = false;
}

void shader::compileShader(){
	vertexShader_ = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader_,1 , &vertexSource_, NULL);
	glCompileShader(vertexShader_);
	
	fragmentShader_ = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader_,1 , &fragmentSource_, NULL);
	glCompileShader(fragmentShader_);

	shader_ = glCreateProgram();
	glAttachShader(shader_,vertexShader_);
	glAttachShader(shader_,fragmentShader_);

	glLinkProgram(shader_);

	delete[] fragmentSource_;
	delete[] vertexSource_;

	compiled_ = true;
}

bool shader::isCompiled() const{
	return compiled_;
}