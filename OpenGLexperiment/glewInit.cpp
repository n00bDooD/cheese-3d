#include "glewInit.h"

GLuint InitGlew (void) {
	if(!glewInit()){
		return 1001;
	}
	return 0;
}