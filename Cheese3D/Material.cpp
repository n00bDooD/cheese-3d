#include "Material.h"

material::material(const shader* shaderclass){
	shader_ = *shaderclass;
}

void material::compileShader(){
	shader_.compileShader();
}