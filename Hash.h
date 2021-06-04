//Hash.h
#ifndef HASH_H_EXISTS
#define HASH_H_EXISTS

#include <iostream>
#include <sstream>

class Hash{
	private:
		int seed;
		unsigned long long h0;
		unsigned long long h1;
		unsigned long long h2;
		unsigned long long h3;
		unsigned long long h4;
	public:
		Hash();
		void getInitStates();
		std::string hashFunction(std::string uID, int salt, std::string pswdStr);
};
#endif
