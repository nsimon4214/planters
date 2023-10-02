#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#pragma once

using namespace std;

class Box {
	private:
		int boxNum;
		char* plant;

	public:
		Box(int, char[]);
		~Box();

		//copy constructor and assignment operator overload
		Box(const Box& aBox);
		const Box& operator= (const Box& aBox);

		//accessor functions
		char * getPlantName() const;
		int getNum() const;

		//mutator functions
		void setPlantName(const char[]);
		void setNum(int);
};

#endif
