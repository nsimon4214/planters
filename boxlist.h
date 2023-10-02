#ifndef BOXLIST_H
#define BOXLIST_H

#pragma once

#include "box.h"

using namespace std;

class BoxList {
	private:
		struct Node {
			Box object;
			Node * next;
			Node * prev;
			Node(int boxNum, char* plant) : object(boxNum, plant) {
				next = nullptr;
				prev = nullptr;
			}
		};
		Node * mCurrent;
		Node * head;
		Node * tail;
	
	public:
		BoxList();
		~BoxList();

		//copy constructor and assignment operator overload
		BoxList(const BoxList& aList);
		const BoxList& operator= (const BoxList& aList);

		void copyListNodes(const BoxList& aList);
		void insertAtTail(Box aBox);
		void startIterating();
		Box getNextBox();
		bool hasNextBox();
};

#endif
