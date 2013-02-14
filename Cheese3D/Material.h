#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.h"
#include "VertexDataFormat.h"

class material {
protected:
	shader shader_;
public:
	material (const shader&);
	~material();

	shader getShader() const;
	void compileShader();
	void defineVertexAttributes(vertexDataFormat&);
	void linkVertexAttributes(vertexDataFormat&);
} ;

#endif