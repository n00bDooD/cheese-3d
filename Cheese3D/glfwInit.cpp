#include "glfwInit.h"

GLuint InitGlfw (void) {
	if(!glfwInit()){
		return (GLuint)1000;
	}
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR,3); //Define the major OpenGL version to use
	//glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR,2); //Define the minor OpenGL version to use
	return (GLuint)0;
}