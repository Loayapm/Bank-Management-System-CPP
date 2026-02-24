#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
//	const int Id;
	string Fname;
	string Lname;
	string PhoneNumber;
	string Email;
public:
	//setters
	void setFname(string fname)
	{
		Fname = fname;
	}
	void setLname(string lname)
	{
		Lname = lname;
	}
	void setPhoneNumber(string phoneNumber)
	{
		PhoneNumber = phoneNumber;
	}
	void setEmail(string email)
	{
		Email = email;
	}
public:
	//constructor
	Person(string fname, string lname, string phoneNumber, string email) : Fname(fname), Lname(lname), PhoneNumber(phoneNumber), Email(email)
	{
	
	}
	//getters
	
	string getFname() const
	{
		return Fname;
	}
	string getLname() const
	{
		return Lname;
	}
	string getPhoneNumber() const
	{
		return PhoneNumber;
	}
	string getEmail() const
	{
		return Email;
	}

	string getFullName() const
	{
		return Fname + " " + Lname;
	}
	

};

