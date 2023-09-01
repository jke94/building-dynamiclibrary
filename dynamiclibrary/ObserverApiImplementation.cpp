#include "pch.h"

#ifdef DYNAMICLIBRARY_EXPORTS

#ifdef __linux__ 

#define DYNAMICLIBRARY_API

#elif _WIN32

#define DYNAMICLIBRARY_API __declspec(dllexport)

#else

#define DYNAMICLIBRARY_API __declspec(dllimport)

#endif

#else

#endif

extern "C" DYNAMICLIBRARY_API ISubject* Create_subject()
{
	return new ObserverApi::Subject();
}

extern "C" DYNAMICLIBRARY_API IObserver* Create_observer(int id, ISubject& subject)
{
	return new ObserverApi::Observer(id, subject);
}

extern "C" DYNAMICLIBRARY_API void Create_message(ISubject& subject, std::string message)
{
	subject.CreateMessage(message);
}

extern "C" DYNAMICLIBRARY_API void Removeme_from_the_list(IObserver& observer)
{
	observer.RemoveMeFromTheList();
}