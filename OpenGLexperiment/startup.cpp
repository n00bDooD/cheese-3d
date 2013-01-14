#include "glewInit.h"
#include "glfwInit.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
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

	InitGlfw();

	if(!glfwOpenWindow(300,300,0,0,0,0,0,0,GLFW_WINDOW )){
		glfwTerminate();
		return 1002;
	}
	glfwSetWindowTitle ("Cheese 3D");

	InitGlew();


	while (running){
		glClearColor(0.2f,0.2f,0.2f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if(glGetError() != 0){
			cout << "Error while looping: " << glGetError() << '\n';
		}

		glfwSwapBuffers();
		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	}

	glfwTerminate();
	return 0;
}