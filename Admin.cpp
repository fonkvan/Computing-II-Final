//Admin.cpp
#include <string>
#include "Admin.h"

Admin::Admin(){}
Admin::Admin(std::string uID){
	username = uID;
	salt = generateSalt();
	banned = false;
	banTime = 0;
}
