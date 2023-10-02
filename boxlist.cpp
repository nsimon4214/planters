#include "boxlist.h"

BoxList::BoxList() {
	head = nullptr;
	tail = nullptr;
	mCurrent = nullptr;
}

BoxList::~BoxList() {
	Node * curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
	curr = nullptr;
	head = nullptr;
	tail = nullptr;
	mCurrent = nullptr;
}

//copy constructor
BoxList::BoxList(const BoxList& aList) {
	copyListNodes(aList);
}

//assigment operator
const BoxList& BoxList::operator= (const BoxList& aLinkedList) {
	if (this != &aLinkedList) {
		this->~BoxList();
		copyListNodes(aLinkedList);
	}
	return *this;
}

//creates deep copy
void BoxList::copyListNodes(const BoxList& aList) {
	char init[] = {0};
	Node* origChainPtr = aList.head;

	if (origChainPtr == nullptr) {
		head = nullptr;
		tail = nullptr;
	}

	else {
		head = new Node(0,init);
		head->object = origChainPtr->object;
		head->prev = nullptr;
		head->next = nullptr;
		tail = head;

		Node* prevListNode = head;
		Node* newListNode;
		origChainPtr = origChainPtr->next;
		while(origChainPtr != nullptr) {
			newListNode = new Node(0,init);
			newListNode->object = origChainPtr->object;
			newListNode->prev = prevListNode;
			prevListNode->next = newListNode;
			prevListNode = newListNode;
			tail = newListNode;
			origChainPtr = origChainPtr->next;
		}
	}
}

void BoxList::insertAtTail(Box aBox) {
	char init[] = {0};
	Node * newNode = nullptr;
	newNode = new Node(0,init);
	newNode->object = aBox;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head != nullptr) {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
}

void BoxList::startIterating() {
	mCurrent = head;
}

Box BoxList::getNextBox() {
	Box aBox(mCurrent->object);
	mCurrent = mCurrent->next;
	return aBox;
}

bool BoxList::hasNextBox() {
	bool flag = true;
	if (mCurrent == nullptr) {
		flag = false;
	}
	return flag;
}
