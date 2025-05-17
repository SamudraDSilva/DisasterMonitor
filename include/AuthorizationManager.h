#ifndef AUTHORIZATION_MANAGER_H
#define AUTHORIZATION_MANAGER_H

#include <Arduino.h>

class AuthorizationManager {
public:
    AuthorizationManager(const String authorizedUIDs[], int uidCount);
    bool isAuthorized(const String& uid);

private:
    const String* authorizedUIDs;
    int uidCount;
};

#endif