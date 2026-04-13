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
	return count;
}
