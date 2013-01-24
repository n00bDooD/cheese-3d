#include "DataValue.h"

dataValue::dataValue(std::string name,uint index){
	name_ = name;
	index_ = index;
}

uint dataValue::getIndex(){
	return index_;
}

std::string dataValue::getName(){
	return name_;
}

