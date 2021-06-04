//main.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "Node.h"
#include "Account.h"
#include "Admin.h"
#include "Hash.h"

int main(){

	Hash h = Hash();
	std::cout << h.hashFunction("dlay", 12345, "password") << std::endl;
	std::cout << h.hashFunction("ajharris", 42345, "password") << std::endl;
	std::cout << h.hashFunction("dlay", 12345, "Password") << std::endl;
	std::cout << h.hashFunction("dlay", 12345, "drowssap") << std::endl;
	std::cout << h.hashFunction("ajharris", 0x4f23ac, "GlitterCritter") << std::endl;
		
/*	Node a;
	Node b;
	b = Node("Node B", NULL);
	a = Node("Node A", &b);

	std::cout << a.getPayload() << std::endl;
	std::cout << a.getNext()->getPayload() << std::endl;
	
	std::srand(434);
	Account a = Account("userA");
	Account b = Account("userB");
	std::cout << a.getSalt() << std::endl;
	std::cout << b.getSalt() << std::endl;
	
	Admin g = Admin("Donovan Lay");
	std::cout << g.getUsername() << std::endl;
	*/
}
