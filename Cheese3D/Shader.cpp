#include "Shader.h"

shader::shader(const char* fragmentSource,const char* vertexSource) {
	fragmentSource_ = fragmentSource;
	vertexSource_ = vertexSource;
	compiled_ = false;
}

void shader::deallocate(){
	glDeleteShader(fragmentShader_);
	glDeleteShader(vertexShader_);
	glDeleteProgram(shader_);
	glDetachShader(shader_,vertexShader_);
	glDetachShader(shader_,fragmentShader_);
}

GLuint shader::getShader() const{
	return shader_;
}

void shader::compileShader(){
	CheckOpenGL();
	GLint status = 0;
	vertexShader_ = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader_,1 , &vertexSource_, NULL);
	glCompileShader(vertexShader_);

	glGetShaderiv( vertexShader_, GL_COMPILE_STATUS, &status );
	if(status == 0){
		char buffer[512];
		glGetShaderInfoLog( vertexShader_, 512, NULL, buffer ); 
		std::cout << buffer;
		throw VERTEX_SHADER_COMPILE_FAIL;
	}
	
	fragmentShader_ = glCreateShader(GL_FRAGMENT_SHADER); //WHY ERROR HERE !?
	glShaderSource(fragmentShader_,1 , &fragmentSource_, NULL);
	glCompileShader(fragmentShader_);

	glGetShaderiv( fragmentShader_, GL_COMPILE_STATUS, &status );
	if(status == 0){
		char buffer[512];
		glGetShaderInfoLog( vertexShader_, 512, NULL, buffer ); 
		std::cout << buffer;

		throw FRAGMENT_SHADER_COMPILE_FAIL;
	}

	shader_ = glCreateProgram();
	glAttachShader(shader_,vertexShader_);
	glAttachShader(shader_,fragmentShader_);

	glBindFragDataLocation( shader_, 0, "outColor" );

	glLinkProgram(shader_);

	fragmentSource_ = "";
	vertexSource_ = "";

	if(status == 1){
		status = 0;
	}

	CheckOpenGL();

	if(status != 0){
		deallocate();
	} else {
		compiled_ = true;
	}
}

bool shader::isCompiled() const{
	return compiled_;
}