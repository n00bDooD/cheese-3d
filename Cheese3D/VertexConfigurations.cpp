#include "VertexConfigurations.h"
#include "Initialize.h"

vertexConfigurations::vertexConfigurations(){
	VAOs_ = std::vector<uint>(4,0);
	glGenVertexArrays(4,VAOs_.data());
}

void vertexConfigurations::addConfiguration(std::string name,uint VAOindex){
	names_.push_back(name);
	VAOs_.push_back(VAOindex);
}