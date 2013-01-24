#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Global.h"
#include "DataValue.h"

#include <rapidxml.hpp>

class dataLoader {
protected:
	std::vector<dataValue> values_;
	char* loadFileData(std::string);
	uint saveFileData(char*);
public:
	dataLoader(void);
	uint loadFile(std::string);
	uint saveConfigFile(void);
} ;

#endif