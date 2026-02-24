#pragma once
#include "User.h"
#include "Logger.h"  

class Session
{
private :
	static User CurrentUser;
	static bool isLoggedIn;
public:
	static void Login(const User & u)
	{
		CurrentUser = u;
		isLoggedIn = true;
		Logger::logUser(u);
		Logger::loadLogsToVector();
		
	}
	static void Logout()
	{
		isLoggedIn = false;
		CurrentUser = User::returnEmptyUser(); //empty the object
		CurrentUser.setMode(User::enUserMode::EmtpyMode);
	}

	//getter
	static User returnCurrentUser() 
	{
		return CurrentUser;
	}
	static bool returnLoginState()
	{
		return isLoggedIn;
	}
};

