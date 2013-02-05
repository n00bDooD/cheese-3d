#include "Material.h"

material::material(const shader& shaderclass) : shader_(shaderclass){
}

material::~material(){
	shader_.deallocate();
}

void material::compileShader(){
	shader_.compileShader();
}