#pragma once
#include <iostream>
using namespace std;
class TransferLog
{
private:
	string dateTime;
	string sourceAcc;
	string destAcc;
	double TAmount;
	double sourceRAmount;
	double destRAmount;
	string user;

public:
	TransferLog(string dt, string sa, string da, double ta, double sra, double dra, string u): dateTime(dt),sourceAcc(sa),destAcc(da),TAmount(ta),sourceRAmount(sra),destRAmount(dra),user(u) {}
	//setters
	void setDateTime(string dt)
	{
		dateTime = dt;
	}
	void setSourceAcc(string sa)
	{
		sourceAcc = sa;
	}
	void setDestAcc(string da)
	{
		destAcc = da;
	}
	void setTAmount(double ta)
	{
		TAmount = ta;
	}
	void setSoureRAmount(double sra)
	{
		sourceRAmount = sra;
	}
	void setDestRAmount(double dra)
	{
		destRAmount = dra;
	}
	void setUser(string u)
	{
		user = u;
	}

	//getters
	string getDateTime() const
	{
		return dateTime;
	}
	string getSourceAcc() const
	{
		return sourceAcc;
	}
	string getDestAcc() const
	{
		return destAcc;
	} 
	double getTAmount() const
	{
		return TAmount;
	}
	double getSourceRAmount() const
	{
		return sourceRAmount;
	}
	double getDestRAmount() const
	{
		return destRAmount;
	}
	string getUser() const
	{
		return user;
	}
};

