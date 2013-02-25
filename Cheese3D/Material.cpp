#include "Material.h"

material::material(const shader& r_shaderclass) : shader_(r_shaderclass){
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

void material::linkVertexAttributes(vertexDataFormat& r_dataFormat){
	if(glIsProgram(shader_.getShader())){
		glUseProgram( shader_.getShader() );
		GLsizei stride = 0;
		GLsizei offset = 0;
		GLint attribute = 0;
		for(unsigned int i = 0;i < (uint)r_dataFormat.count();i++){
			vertexAttrib attributeStruct = r_dataFormat.getAttribute(i);
			for(unsigned int j = 0; j < (uint)r_dataFormat.count();j++){
				vertexAttrib otherAttributeStruct = r_dataFormat.getAttribute(j);
				stride += (i == j) ? 0 : (sizeof((otherAttributeStruct.type)) * otherAttributeStruct.size);
				offset += (i < j) ? 0 : (sizeof((otherAttributeStruct.type)) * otherAttributeStruct.size);
			}
			CheckOpenGL();
			attribute = glGetAttribLocation( shader_.getShader(), attributeStruct.name); //Somehow it can't find the second attribute, EVERY TIME
			CheckOpenGL();
			if(attribute != -1){
				glEnableVertexAttribArray( attribute );
				CheckOpenGL();
				glVertexAttribPointer( attribute, attributeStruct.size, attributeStruct.type, attributeStruct.normalized, stride,(void*)offset);
			}
		}
	}
}

void material::defineVertexAttributes(vertexDataFormat& r_dataFormat){
	for(unsigned int i = 0;i < (uint)r_dataFormat.count();i++){
		glBindAttribLocation(shader_.shader_,i,r_dataFormat.getAttribute(i).name);
	}
	glLinkProgram(shader_.shader_);
}