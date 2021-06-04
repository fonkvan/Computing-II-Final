//Node.h
#include <string>
#include "Account.h"
#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class Node{
	private:
		std::string payload;
		Node *next;
	public:
		Node();
		Node(std::string payload, Node *next);
		std::string getPayload();
		Node* getNext();
		void setPayload(std::string payload);
		void setNext(Node *next);
};
#endif
