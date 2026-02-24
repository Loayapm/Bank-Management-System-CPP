#pragma once
#include <stdint.h>
enum class Permissions: uint32_t
{
	None=0,
	ListClients=1<<0,
	AddNewClient=1<<1,
	DeleteClient=1<<2,
	UpdateClient=1<<3,
	FindClient=1<<4,
	Transactions=1<<5,
	ManageUsers=1<<6,
	ShowLogs=1<<7,
	Full = 0xFFFFFFFF
};

