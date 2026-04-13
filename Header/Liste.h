#pragma once
#include<string>

struct Ville {
	std::string nom;
	unsigned int nbTest = 0;
};

struct Node {
	Node* next;
	Ville ville;
};

struct LinkedList {
	Node* back = nullptr;
};

bool lLEmpty(const LinkedList& linkedList);
size_t lLSize(const LinkedList& linkedList);
void lLPushBack(LinkedList& linkedList);