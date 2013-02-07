#ifndef CHEESERENDERER_H
#define	CHEESERENDERER_H

#include "ShadingBatch.h"
#include <stdlib.h>
#include <vector>

#define GLEW_STATIC
#include <GL\glew.h>

#define GLFWDLL
#include <GL\glfw.h>

class cheeseRenderer {
private:
	std::vector<shadingBatch*> batches_;
	void initBatch (GLuint);
public:
	cheeseRenderer(shadingBatch*);
	void addBatch(shadingBatch*);
	GLuint draw(void);
} ;

#endif