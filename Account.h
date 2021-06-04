//Account.h
#ifndef ACCOUNT_H_EXISTS
#define ACCOUNT_H_EXISTS
#include <string>

class Account{
	protected:
		std::string username;
		int generateSalt();
		int salt;
		int banTime;
		bool banned;
	public:
		Account();
		Account(std::string uID);
		int getSalt();
		int getBanTime();
		std::string getUsername();
		bool isBanned();
};
#endif
