// Author:  Keith A. Shomper
// Date:    2/13/20
// Purpose: To implement a simple, sorted linked-list of positive integers

#include "LLSortedPosInt.h"

// The linked-list is constructed of Node elements
struct Node {
	int   key;
	Node* next;
};

// the following function is not a member function, it is a convenience
// function which exists to make the implementation of the LLSortedPosInt
// class more concise

// createNode() allocates a Node and initializes it with the
// given parameter values to simplify the initilization of a Node
static NodePtr createNode(int key, NodePtr p) {
	// allocate a new Node for storing the given key value
	NodePtr n = new Node;

	// store the key value and the next pointer
	n->key = key;
	n->next = p;

	// return the new Node to the caller
	return n;
}

// Student implementation of LLSortedPosInt begins here

// Constructors
LLSortedPosInt::LLSortedPosInt() {
	this->head = createNode(HEAD_OF_LIST, nullptr);
}

LLSortedPosInt::LLSortedPosInt(int key) : LLSortedPosInt() {
	// add the single element key, as long as it is positive
	if (key > 0) {
		this->insert(key);
	}
}

LLSortedPosInt::LLSortedPosInt(int* keys, int n) : LLSortedPosInt() {

	for (int i = 0; i < n; i++) {
		if (keys[i] > 0) {
			this->insert(keys[i]);
		}
	}
}

LLSortedPosInt::LLSortedPosInt(const LLSortedPosInt& l) : LLSortedPosInt() {
	// create a deep copy of the input list l

	if (l.head == nullptr || l.head->next == nullptr) {
		return;
	}

	NodePtr currentNode = l.head->next;
	while (currentNode != nullptr) {
		this->insert(currentNode->key);
		currentNode = currentNode->next;
	}
}

// Destructor
LLSortedPosInt::~LLSortedPosInt() {
	NodePtr toDelete = this->head;
	while (this->head != nullptr) {
		toDelete = this->head;
		this->head = this->head->next;
		delete toDelete;
	}
}

// Assignment Operator
LLSortedPosInt& LLSortedPosInt::operator=
(const LLSortedPosInt& l) {
	// handle self assignment
	if (this == &l) {
		return *this;
	}

	// free old elements of the list before the new elements from l are assigned
	this->~LLSortedPosInt();

	// if necessary, rebuild the sentinal
	if (this->head == nullptr || this->head->key != -1) {
		this->head = createNode(HEAD_OF_LIST, nullptr);
	}

	// build the list as a deep copy of l
	NodePtr currentNode = l.head->next;
	while (currentNode != nullptr) {
		this->insert(currentNode->key);
		currentNode = currentNode->next;
	}

	// return *this
	return *this;
}

// Print Operator (a non-member function)
ostream& operator<<  (ostream& out, const LLSortedPosInt& l) {
	// an empty list will be printed as <>
	// a singleton list (a list having one key value k) will be
	//     printed as <k>
	// a list having multiple keys such as 2, 5, 7 will be printed
	//     as <2, 5, 7>

	// print the left angle bracket
	std::cout << "<";

	// print the keys in the list l
	NodePtr currentNode = l.head->next;
	if (currentNode != nullptr) {
		std::cout << currentNode->key;
		currentNode = currentNode->next;
		while (currentNode != nullptr) {
			std::cout << ", " << currentNode->key;
			currentNode = currentNode->next;
		}
	}

	// print the right angle bracket
	std::cout << ">";

	return out;
}

// Boolean Functions
bool LLSortedPosInt::isEmpty() const {
	// return true if only the sentinal is in the list; return false otherwise
	if (this->head == nullptr || this->head->next == nullptr) {
		return true;
	}
	return false;
}

bool LLSortedPosInt::containsElement(int key) const {
	// return true if key is in the list; return false otherwise
	NodePtr currentNode = this->head;
	while (currentNode != nullptr) {
		if (currentNode->key == key) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

// Other Operator Member Functions
bool LLSortedPosInt::operator==(const LLSortedPosInt& l) const {
	// compare the Nodes in *this with the Nodes in l
	// if all Node key values in *this match the cooresponding
	//  Node key values in l, then the lists are equivalent
	NodePtr currentNode = this->head->next;
	NodePtr currentExternalNode = l.head->next;
	while (currentNode != nullptr && currentExternalNode != nullptr) {
		if (currentNode->key != currentExternalNode->key) {
			return false;
		}
		currentNode = currentNode->next;
		currentExternalNode = currentExternalNode->next;
	}
	if (currentNode == nullptr && currentExternalNode == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool LLSortedPosInt::operator!=(const LLSortedPosInt& l) const {
	// do the opposite of operator==
	return !(*this == l);
}

// Other Operator Functions (non-member functions)
LLSortedPosInt  operator+ (const LLSortedPosInt& l1,
	const LLSortedPosInt& l2) {
	// create a copy of l1 and add each element of l2 to it in 
	// the correct (sorted ascending) order, allow duplicates
	LLSortedPosInt sum = l1;
	NodePtr currentNode = l2.head->next;
	while (currentNode != nullptr) {
		sum.insert(currentNode->key);
		currentNode = currentNode->next;
	}
	return sum;
}

LLSortedPosInt  operator- (const LLSortedPosInt& l1,
	const LLSortedPosInt& l2) {
	// copy l1 and remove all of l2 from l1, taking care to 
	// reclaim any storage -- do not to remove the sentinal Node
	LLSortedPosInt diff = l1;
	NodePtr currentNode = l2.head;
	while (currentNode != nullptr) {
		diff.remove(currentNode->key);
		currentNode = currentNode->next;
	}
	return diff;
}

// The following helper functions are provide to assist you in
// building the class--these helper functions are useful in
// several places among the functions you will write--take time
// to learn what they do

// insert() inserts an element in the linked list in sorted order
void LLSortedPosInt::insert(int key) {

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// walk the list, searching until the given key value is exceeded
	while (npc != NULL && npc->key <= key) {
		npp = npc;
		npc = npc->next;
	}

	// insert the new value into the list
	npp->next = createNode(key, npc);
}

// remove() removes an element from the list (if it is present)
void LLSortedPosInt::remove(int key) {

	// negative values should not be stored in the list
	if (key <= 0) {
		return;
	}

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// search the list until the end (if necessary)
	while (npc != NULL) {

		// if the key value is found, then splice this Node from the list and
		// reclaim its storage
		if (npc->key == key) {
			npp->next = npc->next;
			delete npc;
			break;
		}

		// walk the pointers to the next Node
		npp = npc;
		npc = npc->next;
	}
}