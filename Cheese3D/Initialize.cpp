#include "Initialize.h"



const GLuint sizeX = 300;
const GLuint sizeY = 300;
const char* title = "Cheese 3D";

unsigned int initialize (void){
	GLuint error = 0;

	error = initGlfw();
	if(error != 0){
		return error;
	}

	if(!glfwOpenWindow(sizeX,sizeY,0,0,0,0,0,0,GLFW_WINDOW)){
		return (GLuint)1002;
	}
	glfwSetWindowTitle (title);

	error = glGetError();
	if(error != 0){
		return error;
	}

	error = initGlew();
	if(error != 0){
		return error;
	}

	error = glGetError();
	if(error != 0){
		return error;
	}

	return (GLuint)0;
}

unsigned int initGlew (void) {
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if(err != 0){
		std::cout << glewGetErrorString(err) << '\n';
		return (GLuint)1001;
	}
	return (GLuint)0;
}

unsigned int initGlfw (void) {
	if(!glfwInit()){
		return (GLuint)1000;
	}
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR,3); //Define the major OpenGL version to use
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR,3); //Define the minor OpenGL version to use

	return (GLuint)0;

}