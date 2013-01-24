#include "UpdateLoop.h"

uint update(uint loopErr,cheeseRenderer* renderer){
	loopErr = renderer->draw();
	if(loopErr != 0){
		return loopErr;
	}
	if(glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED)){
		return 1;
	}
	return 0;
}