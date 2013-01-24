#include "Material.h"

material::material(char* vertexShader, char* fragmentShader){
	vertexShader_ = vertexShader;
	fragmentShader_ = fragmentShader;
}

char* material::getFragmentShader(void){
	return fragmentShader_;
}

char* material::getVertexShader(void){
	return vertexShader_;
}