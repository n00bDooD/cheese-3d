#include "glewInit.h"

GLuint InitGlew (void) {
	if(!glewInit()){
		return (GLuint)1001;
	}
	return (GLuint)0;
}