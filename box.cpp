#include "box.h"

Box::Box(int num, char* name) {
	boxNum = num;
	plant = new char[strlen(name) + 1];
	strcpy(plant,name);
}

Box::~Box() {
	boxNum = 0;
	delete [] plant;
	plant = nullptr;
}

Box::Box(const Box& origObject) {
	boxNum = origObject.boxNum;
	plant = new char[strlen(origObject.plant) + 1];
	strcpy(plant,origObject.plant);
}

const Box& Box::operator= (const Box& origObject) {
	this->~Box();
	boxNum = origObject.boxNum;
	plant = new char[strlen(origObject.plant) + 1];
	strcpy(plant,origObject.plant);
	return *this;
}

char * Box::getPlantName() const {
	return plant;
}

int Box::getNum() const {
	return boxNum;
}

void Box::setNum(int num) {
	boxNum = num;
}

void Box::setPlantName(const char* name) {
	if (plant) {
		delete plant;
		plant = nullptr;
	}
	plant = new char[strlen(name) + 1];
	strcpy(plant,name);
}
