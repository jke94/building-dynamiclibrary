#pragma once

// API interface delivered to the clients.
#include "IDynamicLibraryApi.h"


// TODO: Remove to include logic in 'IDynamicLibrary.h'
#include "ObserverApi.h"

// Functions definition.
typedef IOperation* (*OPERATION)(void);

typedef ObserverApi::Subject* (*SUBJECT)();
typedef ObserverApi::Observer* (*OBSERVER)(int id, ObserverApi::Subject& subject);
typedef void (*CREATE_MESSAGE)(ObserverApi::Subject& subject, std::string message);
typedef void (*REMOVEME_FROM_THE_LIST)(ObserverApi::Observer& observer);