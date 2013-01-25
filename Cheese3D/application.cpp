#include "Initialize.h"
#include "DataLoader.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "CheeseRenderer.h"
#include "ShadingBatch.h"
#include "Material.h"
#include "shaders.h"
#include "Vertices.h"
#include "Global.h"
#include "UpdateLoop.h"
#include <assert.h>

using namespace std;

int application (void);
cheeseRenderer renderer;


int main (void){

	int result = application();

	if(result != 0){
		return result; //TODO: Create code for showing a pop-up window if something bad has happened to the application.
	} else {
		return 0;
	}
}

int application( void ){
	bool running = GL_TRUE;

	if(true) {
		GLuint err = initialize();
		if(err != 0){
			glfwTerminate();
			return err;
		}
	}

	material defaultMaterial(vertexSource,fragmentSource);

	shadingBatch defaultBatch(normalVertex,&defaultMaterial);
	::renderer.addBatch(&defaultBatch);

	quad primitive (
		vertex(glm::vec3(-0.5,-0.5,0),glm::vec3(0,0,1)),
		vertex(glm::vec3(0.5,-0.5,0),glm::vec3(0,0,1)),
		vertex(glm::vec3(0.5,0.5,0),glm::vec3(0,0,1)),
		vertex(glm::vec3(-0.5,0.5,0),glm::vec3(0,0,1)),
		normalVertex
		);
	defaultBatch.addPrimitives(&primitive);

	GLuint loopErr = 0;
	while (running){
		loopErr = update(loopErr,&renderer);
		if(loopErr != 0 && loopErr != 1){
			break;
		} else if (loopErr == 1){
			loopErr = 0;
			break;
		}
	}


	glfwTerminate();
	return loopErr;
}