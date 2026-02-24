#pragma once
#include <iostream>
using namespace std;
class Log
{
private:
	string dateTime;
	string fullName;
	string username;
	string permissions;

public:

	Log(string dt,string fn,string un,string p): dateTime(dt),fullName(fn),username(un),permissions(p) {}

	//setters
	void setDateTime(string dt)
	{
		dateTime = dt;
	}
	void setFullName(string fn)
	{
		fullName = fn;
	}
	void setUserName(string un)
	{
		username = un;
	}
	void setPeremissions(string p)
	{
		permissions = p;
	}

	string getDateTime() const
	{
		return dateTime;
	}
	string getFullName() const
	{
		return fullName;
	}
	string getUserName() const
	{
		return username;
	}
	string getPermissions() const
	{
		return permissions;
	}

};

