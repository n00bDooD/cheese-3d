#ifndef DATAVALUE_H
#define DATAVALUE_H

#include <stdlib.h>
#include <string>
#include "Global.h"

class dataValue {
	std::string name_;
	GLuint index_;
public:
	dataValue(std::string,uint);
	uint getIndex(void);
	std::string getName(void);
} ;

#endif