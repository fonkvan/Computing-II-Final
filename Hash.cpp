//Hash.cpp
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Hash.h"

Hash::Hash(){
	seed = 24469;
	std::srand(seed);
	h0 = std::rand()%65635;
	h1 = std::rand()%65635;
	h2 = std::rand()%65635;
	h3 = std::rand()%65635;
	h4 = std::rand()%65635;
}

std::string Hash::hashFunction(std::string username, int salt, std::string pswdStr){
	unsigned long long use = 0;
	unsigned long long pwd = 0;
	for(int i = 0; i < (int)username.length(); i++){
		use = use + ((int)username[i] *(i + 1));
	}
	for(int i = 0; i < (int)pswdStr.length(); i++){
		pwd = pwd + ((int)pswdStr[i] * (i + 1));
	}
	pwd = salt + pwd + use;
	//following the SHA-1 Algorithm in a attempt to implent and understand the algorithm
	unsigned long long a = h0;
	unsigned long long b = h1;
	unsigned long long c = h2;
	unsigned long long d = h3;
	unsigned long long e = h4;
	unsigned long long f = 0;
	unsigned long long temp = 0;
	unsigned int k = 0;
	for(int i = 0; i < 80; i++){
		if(0 <= i && i <= 19){
			//in the SHA-1 algorithm we loop 80 times. for i in certain ranges we have a function f(i; B,C,D) and K(i) which are assigned values
			//or calculated based on the ith value. 
			k = 0x5a827999;
			//here we are performing bitwise operation (and (&), or (|), xor (^), not (~)) 
			f = (b&c)|((~b)&d);
		}
		else if(20 <= i && i <= 39){
			k = 0x6ed9eba1;
			f = b^c^d;
		}
		else if(40 <= i && i <= 59){
			k = 0x5a827999;
			f = (b&c)|(b&d)|(c&d);
		}
		else if(60 <= i && i <= 79){
			k = 0xca62c1d6;
			f = b^c^d;
		}
		//every loop we're gonna change our states
		temp = (a<<5) + f + e + k;
		e = d;
		d = c;
		c = (b<<30);
		b = a;
		a = temp;
		}

	unsigned long long H0 = h0 + a;
	unsigned long long H1 = h1 + b;
	unsigned long long H2 = h2 + c;
	unsigned long long H3 = h3 + d;
	unsigned long long H4 = h4 + e;

	std::stringstream ss;
	pwd = pwd + ((H0 <<32)|(H1<<16)|(H2<<8)|(H3<<4)|H4);
	ss << std::hex << pwd;
	std::string hashedPwd = "";
	ss >> hashedPwd;
	return "0x" + hashedPwd;
}
	
void Hash::getInitStates(){
	std::cout << "h0: 0x" << std::hex << h0 << std::endl;
	std::cout << "h1: 0x" << std::hex << h1 << std::endl;
	std::cout << "h2: 0x" << std::hex << h2 << std::endl;
	std::cout << "h3: 0x" << std::hex << h3 << std::endl;
	std::cout << "h4: 0x" << std::hex << h4 << std::endl;
}
