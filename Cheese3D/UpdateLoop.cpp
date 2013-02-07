#include "UpdateLoop.h"

uint update(uint loopErr,cheeseRenderer& renderer){
	if(glGetError() != NO_ERROR){
		return glGetError();
	}
	loopErr = renderer.draw();
	if(loopErr != NO_ERROR){
		return loopErr;
	}
	if(glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED)){
		return CLOSE_APPLICATION;
	}
	return NO_ERROR;
}