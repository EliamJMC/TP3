#pragma once
#include<string>

struct Data {
	std::string ville;
	unsigned int nbTest = 0;
};

struct Node {
	Data data;
	Node* next;
};

struct LinkedList {
	Node* back = nullptr;
};

bool lLEmpty(const LinkedList& linkedList);
size_t lLSize(const LinkedList& linkedList);

void lLPushBack(LinkedList& linkedList, Data data);
void lLPopBack(LinkedList& linkedList);
void lLClear(LinkedList& linkedList);

Node* lLSearchNodeByName(const LinkedList& linkedList, std::string nomVille);
Node* lLSearchHighestTest(const LinkedList& linkedList);
void lLUpdate(LinkedList& linkedList, Data data);