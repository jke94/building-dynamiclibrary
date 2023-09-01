#pragma once

// API interface delivered to the clients.
#include "IDynamicLibraryApi.h"

// Functions definition.
typedef IOperation* (*OPERATION)(void);

typedef ISubject* (*SUBJECT)();
typedef IObserver* (*OBSERVER)(int id, ISubject& subject);
typedef void (*CREATE_MESSAGE)(ISubject& subject, std::string message);
typedef void (*REMOVEME_FROM_THE_LIST)(IObserver& observer);