#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.h"

class material {
protected:
	shader shader_;
public:
	material (const shader&);
	~material();

	void compileShader();
} ;

#endif