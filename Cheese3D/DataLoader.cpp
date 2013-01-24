#include "DataLoader.h"

char* dataLoader::loadFileData(std::string filePath){
	using namespace std;

	ifstream fileStream;
	char* data = "";

	fileStream.open(filePath);
	if(fileStream){
		fileStream >> data;
	} else {
		data = "0";
	}
	fileStream.close();
	return data;
}

uint dataLoader::loadFile(std::string filePath){
	using namespace rapidxml;
	char* data = loadFileData(filePath);
	xml_document<> document;

	if(data != "0"){
		document.parse<0>(data);

	}
	return 1;
}

dataLoader::dataLoader(void){
	char* configData = loadFileData("config.xml");
	if(configData == "0"){
		
	}
}