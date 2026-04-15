#pragma once
#include<string>

struct Data {
	std::string nom;
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