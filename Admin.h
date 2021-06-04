//Admin.h
#ifndef ADMIN_H_EXISTS
#define ADMIN_H_EXISTS
#include "Account.h"

class Admin: public Account{
	public:
		Admin();
		Admin(std::string uID);
};
#endif
