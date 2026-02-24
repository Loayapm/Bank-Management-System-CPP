#pragma once //Permissions manager, here where all the logic happens, no cout here.
#include "Permissions.h"
#include "User.h"
#include "clsInputValidation.h"
#include <iostream>

class PermissionsManager
{
public:
	//has, grant, revoke
	static bool hasPermission(User  &u, Permissions p)
	{
		uint32_t userPermissions = u.getPermissions();
		uint32_t permission = static_cast<uint32_t>(p);
		bool isAccepted = ((userPermissions & permission) != 0);
		return isAccepted;
	}
	static bool hasFullAccess(User &u)
	{
		uint32_t userPermission = u.getPermissions();
		return (userPermission == (static_cast<uint32_t>(Permissions::Full)));
	}
	

	static bool grantPermission(User & u, Permissions p)
	{
		uint32_t userPermissions = u.getPermissions();
		uint32_t newPermissionToAdd = static_cast<uint32_t>(p);
		uint32_t newUserPermissions = userPermissions | newPermissionToAdd;
		if (userPermissions == newUserPermissions)
		{
			return false; // permission already granted
		}
		u.setPersmissions(newUserPermissions);
		
		return true;
	}

	static bool revokePermission(User& u, Permissions p)
	{
		uint32_t userPermissions = u.getPermissions();
		uint32_t newPermissionToRevoke = static_cast<uint32_t>(p);
		uint32_t newUserPermissions = userPermissions & (~newPermissionToRevoke);
		if (userPermissions == newUserPermissions)
		{
			return false; // permission already revoked
		}
		u.setPersmissions(newUserPermissions);
		
		return true;
	}
	static bool clearPermissions(User & u)
	{
		uint32_t currentPermissions = u.getPermissions();
		if (currentPermissions == 0)
		{
			return false;
		}
		u.setPersmissions(0);
		
		return true;
	}

};

