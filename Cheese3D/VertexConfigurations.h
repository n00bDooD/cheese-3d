#ifndef VERTEXCONFIGURATIONS_H
#define VERTEXCONFIGURATIONS_H

#include <stdlib.h>
#include <string>
#include <vector>
#include "Global.h"

class vertexConfigurations {
protected:
	std::vector<std::string> names_;
	std::vector<uint> VAOs_;
public:
	vertexConfigurations(void);
	void addConfiguration(std::string,uint);
} ;

#endif