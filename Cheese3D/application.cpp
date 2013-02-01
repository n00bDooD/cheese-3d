#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Initialize.h"
#include "DataLoader.h"
#include <iostream>
#include <cstring>
#include <string>
#include "CheeseRenderer.h"
#include "ShadingBatch.h"
#include "Material.h"
#include "Shader.h"
#include "Vertex.h"
#include "shaders.h"
#include "Global.h"
#include "UpdateLoop.h"
#include <assert.h>

using namespace std;

int application (void);


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


	GLuint loopErr = 0;
	{
		shader* defaultShader = new shader(fragmentSource,vertexSource);
		material* defaultMaterial = new material(defaultShader);
		vertexAttribLayout* defaultVertexData = new vertexAttribLayout();
		shadingBatch* batch = new shadingBatch(*defaultVertexData,*defaultMaterial);
		cheeseRenderer renderer(*batch);

		delete batch;
		delete defaultVertexData;
		
		while (running){
			loopErr = update(loopErr,&renderer);
			if(loopErr != 0 && loopErr != 1){
				break;
			} else if (loopErr == 1){
				loopErr = 0;
				break;
			}
		}
	}
	glfwTerminate();
	return loopErr;
}