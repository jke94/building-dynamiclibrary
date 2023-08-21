#include "pch.h"

DYNAMICLIBRARY_API ObserverApi::Subject* Create_subject()
{
	return new ObserverApi::Subject();
}

DYNAMICLIBRARY_API ObserverApi::Observer* Create_observer(int id, ObserverApi::Subject& subject)
{
	return new ObserverApi::Observer(id, subject);
}

DYNAMICLIBRARY_API void Create_message(ObserverApi::Subject& subject, std::string message)
{
	subject.CreateMessage(message);
}

DYNAMICLIBRARY_API void Removeme_from_the_list(ObserverApi::Observer& observer)
{
	observer.RemoveMeFromTheList();
}