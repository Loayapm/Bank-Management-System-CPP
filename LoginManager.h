#pragma once
#include "UsersManager.h"
#include "User.h"
class LoginManager
{
	static bool login(string username, string password)
	{
		User u=UsersManager::findUserWithUsernameAndPassword(username, password);

	}
	static void logout() {}
};

