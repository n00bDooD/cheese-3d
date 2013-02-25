#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "Global.h"
#include <iostream>
#include "Debug.h"

#define GLEW_STATIC
#include <GL\glew.h>

#include <GL\glfw.h>

unsigned int initialize (void);
unsigned int initGlew (void);
unsigned int initGlfw (void);
#endif