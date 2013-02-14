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
	if(glIsProgram(shader_.getShader())){
		glUseProgram( shader_.getShader() );
		GLsizei stride = 0;
		GLsizei offset = 0;
		GLint attribute = 0;
		for(unsigned int i = 0;i < (uint)dataFormat.count();i++){
			vertexAttrib attributeStruct = dataFormat.getAttribute(i);
			for(unsigned int j = 0; j < (uint)dataFormat.count();j++){
				vertexAttrib otherAttributeStruct = dataFormat.getAttribute(j);
				stride += (i == j) ? 0 : (sizeof((otherAttributeStruct.type)) * otherAttributeStruct.size);
				offset += (i < j) ? 0 : (sizeof((otherAttributeStruct.type)) * otherAttributeStruct.size);
			}
			GLuint error = glGetError();
			attribute = glGetAttribLocation( shader_.getShader(), attributeStruct.name); //Somehow it can't find the second attribute, EVERY TIME
			error = glGetError();
			glEnableVertexAttribArray( attribute );
			error = glGetError();
			glVertexAttribPointer( attribute, attributeStruct.size, attributeStruct.type, attributeStruct.normalized, stride,(void*)offset);
		}
	}
}

void material::defineVertexAttributes(vertexDataFormat& dataFormat){
	for(unsigned int i = 0;i < (uint)dataFormat.count();i++){
		glBindAttribLocation(shader_.shader_,i,dataFormat.getAttribute(i).name);
	}
	glLinkProgram(shader_.shader_);
}