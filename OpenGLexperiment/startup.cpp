#include "Initialize.h"
#include "DataLoader.h"
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
	const GLuint sizeX = 300;
	const GLuint sizeY = 300;
	const char* title = "Cheese 3D";
	bool running = GL_TRUE;

	{
		GLuint err = initialize();
		if(err != 0){
			return err;
		}
	}

	if(!glfwOpenWindow(sizeX,sizeY,0,0,0,0,0,0,GLFW_WINDOW )){
		glfwTerminate();
		return (GLuint)1002;
	}
	glfwSetWindowTitle (title);

	//readFile("Example.xml");

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