#include "boxtree.h"

BoxTree::BoxTree() {
	root = nullptr;
}

BoxTree::~BoxTree() {
	RecursiveDestroy(root);
	root = nullptr;
}

void BoxTree::RecursiveDestroy(Node* node) {
	if (node) {
		RecursiveDestroy(node->left);
		RecursiveDestroy(node->right);
		delete node;
	}
}

void BoxTree::insert(Box aBox) {
	insert(root, aBox);
}

void BoxTree::insert(Node*& root, Box& aBox) {
	if (!root) {
		char init[] = {0};
		root = new Node(0,init);
		root->object = aBox;
	}
	else if (aBox.getNum() < root->object.getNum()) {
		insert(root->left, aBox);
	}
	else {
		insert(root->right, aBox);
	}
}

void BoxTree::remove(int num) {
	remove(root, num);
}

void BoxTree::remove(Node*& root, int num) {
	if (num == root->object.getNum()) {
		deleteNode(root);
	}
	else if (num < root->object.getNum()) {
		remove(root->left, num);
	}
	else {
		remove(root->right, num);
	}
}

void BoxTree::deleteNode(Node*& node) {
	Node* curr = nullptr;

	//The following will delete a leaf:
	if (!node->left && !node->right) {
		delete node;
		node = nullptr;
	}

	//The following will delete a node with no left child:
	else if (!node->left) {
		curr = node;
		node = node->right;
		curr->right = nullptr;
		delete curr;
	}

	//The folliwng will delete a node with no right child:
	else if (!node->right) {
		curr = node;
		node = node->left;
		curr->left = nullptr;
		delete curr;
	}

	//The following will delete anode with two children:
	else {
		//To find the inorder successor:
		Node * prev = nullptr;
		curr = node->right;
		while (curr->left) {
			prev = curr;
			curr = curr->left;
		}

		//transfer data from curr to node passed into function
		node->object = curr->object;

		//disconnect curr:
		if (!prev) {
			node->right = curr->right;
		}
		else {
			prev->left = curr->right;
		}

		//delete curr
		curr->right = nullptr;
		delete curr;
	}
}

BoxList BoxTree::getRange(const int start, const int stop) {
	BoxList aList;
	getRange(start, stop, root, aList);
	return aList;
}

void BoxTree::getRange(int start, int stop, Node* node, BoxList& aList) {
	if (node) {
		//best case scenario, it's a node we want:
		if ((node->object.getNum() >= start) && (node->object.getNum() <= stop)) {
			getRange(start, stop, node->left, aList);
			aList.insertAtTail(node->object);
			getRange(start, stop, node->right, aList);
		}
		//out of range in that it's too small:
		else if (node->object.getNum() < start) {
			if ((node->left != nullptr) && (node->right != nullptr)) {
				//if the node to the right is below or equal to the range,
				//then the left node and all it's children definietly will be.
				if (node->right->object.getNum() <= start) {
					getRange(start, stop, node->right, aList);
				}
				//If the node to the right is above or within the range but the
				//left is below or equal to the range, then still need to
				//traverse in both directions without adding to the list
				else if (node->right->object.getNum() > start) {
					getRange(start, stop, node->left, aList);
					getRange(start, stop, node->right, aList);
				}
			}
			else {
				getRange(start, stop, node->left, aList);
				getRange(start, stop, node->right, aList);
			}
		}
		else if ((node->object.getNum() > start)) {
			if ((node->left != nullptr) && (node->right != nullptr)) {
				if (node->left->object.getNum() >= start) {
					getRange(start, stop, node->left, aList);
				}
				else if (node->left->object.getNum() < start) {
					getRange(start, stop, node->left, aList);
					getRange(start, stop, node->right, aList);
				}
			}
			else {
				getRange(start, stop, node->left, aList);
				getRange(start, stop, node->right, aList);
			}
		}
	}
}
