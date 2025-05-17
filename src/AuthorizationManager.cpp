#include "AuthorizationManager.h"

AuthorizationManager::AuthorizationManager(const String authorizedUIDs[], int uidCount)
    : authorizedUIDs(authorizedUIDs), uidCount(uidCount) {}

bool AuthorizationManager::isAuthorized(const String& uid) {
    for (int i = 0; i < uidCount; i++) {
        if (uid == authorizedUIDs[i]) {
            return true;
        }
    }
    return false;
}