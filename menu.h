//menu.h

#ifndef MENU_H_EXISTS
#define MENU_H_EXISTS

#include <iostream>
#include "Hash.h"
#include "Account.h"
#include "Admin.h"
#include "Node.h"

class Menu{

	private:
		Node LLAccounts;
		Hash hobj;
	public:
		Menu();
		void createAccount();
		void banUser(std::string uID, int length);
		void unbanUser(std::string uID);
		void deleteUser(std::string uID);
		void adminMenu();
		bool isUnique(std::string uID);
};
#endif
