#include "../Header/Liste.h"

bool lLEmpty(const LinkedList& linkedList) { return linkedList.back == nullptr; }

size_t lLSize(const LinkedList& linkedList) {
	if (lLEmpty(linkedList)) return 0;
	Node* actual = linkedList.back;
	size_t count = 0;
	for (Node* current = linkedList.back; current != nullptr; current = current->next)
		++count;
	return count;
}

void lLPushBack(LinkedList& linkedList, Data data) {
	Node* newNode = new Node{data, nullptr };
	newNode->next = linkedList.back;
	linkedList.back = newNode;
}

void lLPopBack(LinkedList& linkedList) {
	if (linkedList.back == nullptr) return;

	Node* temp = linkedList.back;
	linkedList.back = linkedList.back->next;

	delete temp;
}

void lLClear(LinkedList& linkedList) {
	while(linkedList.back) {
		lLPopBack(linkedList);
	}
} 

Node* lLSearchNodeByName(const LinkedList& linkedList, std::string nomVille) {
	Node* actual = linkedList.back;

	while (actual != nullptr) {
		if (actual->data.ville == nomVille) 
			return actual;
		
		actual = actual->next;
	}

	return nullptr;
}
Node* lLSearchHighestTest(const LinkedList& linkedList) {
	if (lLEmpty(linkedList)) return nullptr;
	Node* actual = linkedList.back->next;
	Node* highest = linkedList.back;

	while (actual != nullptr) {
		if (actual->data.nbTest > highest->data.nbTest)
			highest = actual;
		actual = actual->next;
	}

	return highest;
}

void lLUpdate(LinkedList& linkedList, Data data) {
	Node* ville = lLSearchNodeByName(linkedList, data.ville);

	if (ville == nullptr)
		lLPushBack(linkedList, data);
	else
		ville->data.nbTest += data.nbTest;
}