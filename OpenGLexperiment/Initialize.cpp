#include "Initialize.h"

GLuint initialize (void){
	GLuint error = 0;
	
	error = initGlew();

	if(error != 0){
		return error;
	}
	error = initGlfw();

	if(error != 0){
		return error;
	}
	return (GLuint)0;
}

GLuint initGlew (void) {
	if(!glewInit()){
		return (GLuint)1001;
	}
	return (GLuint)0;
}

GLuint initGlfw (void) {
	if(!glfwInit()){
		return (GLuint)1000;
	}
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR,3); //Define the major OpenGL version to use
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR,2); //Define the minor OpenGL version to use
	return (GLuint)0;
}