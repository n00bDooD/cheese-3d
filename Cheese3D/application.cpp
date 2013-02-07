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
		std::vector<shadingBatch> batches;

		primitives.push_back(new quad());

		shader* defaultShader = new shader(fragmentSource,vertexSource);
		material* defaultMaterial = new material(*defaultShader);
		vertexDataFormat* defaultDataFormat = new vertexDataFormat();

		vertexAttrib* position = new vertexAttrib("position",3,GL_FLOAT,false);
		vertexAttrib* uv = new vertexAttrib("UV",2,GL_FLOAT,false);
		vertexAttrib* normal = new vertexAttrib("normal",2,GL_FLOAT,true);
		vertexAttrib* color = new vertexAttrib("color",4,GL_FLOAT,false);

		defaultDataFormat->addAttribute( *position );
		defaultDataFormat->addAttribute( *uv );
		defaultDataFormat->addAttribute( *normal );
		defaultDataFormat->addAttribute( *color );

		shadingBatch* batch = new shadingBatch(*defaultDataFormat,*defaultMaterial);

		batch->addPrimitive(primitives[0]); //TODO: Less magic numbers and more good programming please....

		cheeseRenderer renderer(batch);

		delete batch;
		delete defaultMaterial;
		delete defaultDataFormat;
		delete defaultShader;
		delete position;
		delete uv;
		delete normal;
		delete color;


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