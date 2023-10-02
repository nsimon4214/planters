#include "plantermgr.h"

PlanterMgr::PlanterMgr() {
	BoxTree object();
}

PlanterMgr::~PlanterMgr() {

}

void PlanterMgr::plant(int num, char* plantName) {
	Box aBox(num, plantName);
	object.insert(aBox);
	cout << "Planting " << plantName << " in box " << num << endl;
}

void PlanterMgr::harvest(char* plantName, int start, int stop) {
	cout << "Harvesting " << plantName << " plants from";
	cout << " boxes " << start << " to " << stop << ". \n";
	cout << "The following boxes will be harvested: ";
	BoxList harvestList = object.getRange(start, stop);
	harvestList.startIterating();
	while (harvestList.hasNextBox()) {
		Box aBox = harvestList.getNextBox();
		if (strcmp(aBox.getPlantName(), plantName) == 0) {
			cout << aBox.getNum() << " ";
		}
	}
	cout << endl;
}

void PlanterMgr::prune(int num) {
	object.remove(num);
	cout << "Pruning box number " << num << ".\n";
}
