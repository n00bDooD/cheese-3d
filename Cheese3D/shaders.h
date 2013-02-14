#ifndef SHADERS_H
#define SHADERS_H
#include <string>

char* vertexSource =
	"#version 150\n"
	"in vec3 position;"
	"in vec2 texcoords;"
	"in vec3 normal;"
	"in vec4 color;"
	"out vec4 Color;"
	"void main() {"
	"	gl_Position = vec4(position, 1.0);"
	"	Color = color;"
	"}";

char* fragmentSource =
	"#version 150\n"
	"in vec4 Color;"
	"out vec4 outColor;"
	"void main() {"
	"	outColor = Color;"
	"}";
#endif