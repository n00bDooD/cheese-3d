#ifndef SHADERS_H
#define SHADERS_H
#include <string>

char* vertexSource =
	"#version 150\n"
	"in vec3 position;"
	"in vec3 color;"
	"out vec3 Color;"
	"void main() {"
	"	gl_Position = vec4(position, 1.0);"
	"	Color = color;"
	"}";

char* fragmentSource =
	"#version 150\n"
	"in vec3 Color;"
	"out vec4 outColor;"
	"void main() {"
	"	outColor = vec4(Color,1.0);"
	"}";
#endif