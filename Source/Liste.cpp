#include "../Header/Liste.h"

bool lLEmpty(const LinkedList& linkedList) { return linkedList.back == nullptr; }

size_t lLSize(const LinkedList& linkedList) {
	if (lLEmpty(linkedList)) return 0;
	Node* actual = linkedList.back;
	size_t count = 0;
	while (actual->next != nullptr) {
		actual = actual->next;
		count++;
	}
	delete actual;
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
	while(lLSize(linkedList) != 0) {
		lLPopBack(linkedList);
	}
} 

Node* lLSearchNode(const LinkedList& linkedList, std::string nomVille) {
	Node* actual = linkedList.back;

	while (actual != nullptr) {
		if (actual->data.nom == nomVille) 
			return actual;
		
		actual = actual->next;
	}

	delete actual;
	return nullptr;
}

void lLUpdate(LinkedList& linkedList, Data data) {
	Node* ville = lLSearchNode(linkedList, data.nom);

	if (ville == nullptr) {

		lLPushBack(linkedList, data);

		delete ville;
		return;
	}

	ville->data.nbTest += data.nbTest;
}