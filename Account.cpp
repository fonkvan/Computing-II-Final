#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Account.h"

Account::Account(){
	Account::username = "";
	Account::salt = 0;
	Account::banned = false;
	Account::banTime = 0;
}

Account::Account(std::string uID){
	Account::username = uID;
	Account::salt = generateSalt();
	Account::banned = false;
	Account::banTime = 0;
}

int Account::generateSalt(){
	int s = 0;
	int r = 0;
	for(int i = 0; i < 16; i++){
		if(std::rand()%2 != 0){
			r = 1;
		}
		else{
			r = 0;
		}
		s = s + (r * std::pow(2,i));
	}
	return s;
}

int Account::getSalt(){
	return salt;
}

int Account::getBanTime(){
	return banTime;
}

std::string Account::getUsername(){
	return username;
}

bool Account::isBanned(){
	return banned;
}
