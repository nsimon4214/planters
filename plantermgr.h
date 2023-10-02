#ifndef PLANTERMGR_H
#define PLANTERMGR_H

#pragma once

using namespace std;

#include "boxtree.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

class PlanterMgr {
	private:
		BoxTree object;

	public:
		PlanterMgr();
		~PlanterMgr();
		void plant(int,char*);
		void harvest(char*, int, int);
		void prune(int);
};

#endif
