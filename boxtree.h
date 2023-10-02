#ifndef BOXTREE_H
#define BOXTREE_H

#pragma once

#include "box.h"
#include "boxlist.h"

using namespace std;

class BoxTree{
	private:
		struct Node {
			Box object;
			Node * left;
			Node * right;
			Node(int boxNum, char* plant) : object(boxNum, plant) {
				left = nullptr;
				right = nullptr;
			}
		};
		Node * root;
		void insert(Node*& root, Box& aBox);
		void RecursiveDestroy(Node*);
		void remove(Node*& root, int num);
		void deleteNode(Node*& node);
		void getRange(int, int, Node*, BoxList&);

	public:
		BoxTree();
		~BoxTree();

		BoxTree(const BoxTree& aTree) = delete;
		const BoxTree& operator= (const BoxTree& aTree) = delete;
		void insert(Box aBox);
		void remove(int);
		BoxList getRange(const int, const int);
		void newLeaf(Node *, Box);
};

#endif
