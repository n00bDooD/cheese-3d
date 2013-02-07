#include "Material.h"

material::material(const shader& shaderclass) : shader_(shaderclass){
}

material::~material(){
	shader_.deallocate();
}

void material::compileShader(){
	shader_.compileShader();
}

shader material::getShader() const{
	return shader_;
}

void material::linkVertexAttributes(vertexDataFormat& dataFormat){
	glUseProgram( shader_.getShader() );
	GLsizei stride = 0;
	GLsizei offset = 0;
	GLint attribute = 0;
	for(unsigned int i = 0;i < (uint)dataFormat.count();i++){
		for(unsigned int j = 0; j < (uint)dataFormat.count();j++){
			stride += (i==j) ? 0 : (sizeof((dataFormat.getAttribute(j).type)) *  dataFormat.getAttribute(j).size);
			offset += (i < j) ? 0 : (sizeof((dataFormat.getAttribute(j).type)) *  dataFormat.getAttribute(j).size);
		}
		attribute = glGetAttribLocation( shader_.getShader(), dataFormat.getAttribute(i).name);
		glEnableVertexAttribArray( attribute );
		glVertexAttribPointer( attribute, dataFormat.getAttribute(i).size, dataFormat.getAttribute(i).type, dataFormat.getAttribute(i).normalized, stride,(void*)offset);
	}
}