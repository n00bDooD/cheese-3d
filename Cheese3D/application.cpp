#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Initialize.h"
#include "DataLoader.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "CheeseRenderer.h"
#include "ShadingBatch.h"
#include "Material.h"
#include "Primitive.h"
#include "Quad.h"
#include "Shader.h"
#include "Vertex.h"
#include "shaders.h"
#include "Global.h"
#include "UpdateLoop.h"
#include <assert.h>

using namespace std;

int application (void);


int main (void){

	int result;

	try{
		result = application();
	} catch (GLuint err){
		return err; //TODO: Create code for showing a pop-up window
	}
	return result;
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
		std::vector<primitive*> primitives;

		primitives.push_back(new quad());

		shader defaultShader(fragmentSource,vertexSource);
		material defaultMaterial(defaultShader);
		vertexDataFormat defaultDataFormat;

		vertexAttrib position("position",3,GL_FLOAT,false);
		vertexAttrib uv("texcoords",2,GL_FLOAT,false);
		vertexAttrib normal("normal",2,GL_FLOAT,true);
		vertexAttrib color("color",4,GL_FLOAT,false);

		defaultDataFormat.addAttribute( position );
		defaultDataFormat.addAttribute( uv );
		defaultDataFormat.addAttribute( normal );
		defaultDataFormat.addAttribute( color );

		shadingBatch batch(defaultDataFormat,defaultMaterial);

		batch.addPrimitive(primitives[0]); //TODO: Less magic numbers and more good programming please....

		cheeseRenderer renderer(batch);

		while (running){
			loopErr = update(loopErr,renderer);
			if(loopErr != NO_ERROR && loopErr != CLOSE_APPLICATION){
				break;
			} else if (loopErr == CLOSE_APPLICATION){
				loopErr = NO_ERROR;
				break;
			}
		}
		for(unsigned int i = 0;i < primitives.size();i++){
			delete primitives[i];
		}
		primitives.clear();
	}
	glfwTerminate();
	return loopErr;
}