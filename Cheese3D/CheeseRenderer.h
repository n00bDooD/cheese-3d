#ifndef CHEESERENDERER_H
#define	CHEESERENDERER_H

#include "Material.h"
#include "ShadingBatch.h"
#include <stdlib.h>
#include <vector>
#include "Quad.h"

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

class cheeseRenderer {
private:
	std::vector<shadingBatch*> batches_;
	std::vector<material> materials_;
public:
	cheeseRenderer(void);
	void addBatch(shadingBatch*);
	GLuint draw(void);
} ;

#endif