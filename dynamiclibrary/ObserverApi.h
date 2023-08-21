#pragma once

#include <list>
#include <iostream>

#ifdef DYNAMICLIBRARY_EXPORTS
    #define DYNAMICLIBRARY_API __declspec(dllexport)
#else
    #define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

namespace ObserverApi
{
	class IObserver
	{
	    public:
		    virtual ~IObserver() {};
		    virtual void Update(const std::string& message_from_subject) = 0;
	};

	class ISubject
	{
	    public:
		    virtual ~ISubject() {};
		    virtual void Attach(IObserver* observer) = 0;
		    virtual void Detach(IObserver* observer) = 0;
		    virtual void Notify() = 0;
	};

    class Subject : public ISubject
    {
        public:

            virtual ~Subject();

            void Attach(IObserver* observer) override;

            void Detach(IObserver* observer) override;

            void Notify() override;

            void CreateMessage(std::string message = "Empty");

            void HowManyObserver();

            /**
             * Usually, the subscription logic is only a fraction of what a Subject can
             * really do. Subjects commonly hold some important business logic, that
             * triggers a notification method whenever something important is about to
             * happen (or after it).
             */
            void SomeBusinessLogic();

        private:
            std::list<IObserver*> list_observer_;
            std::string message_;
    };

    class Observer : public IObserver
    {
        public:
            Observer(int id_number, Subject& subject);

            virtual ~Observer();

            void Update(const std::string& message_from_subject);

            void RemoveMeFromTheList();

            void PrintInfo();

        private:
            std::string message_from_subject_;
            Subject& subject_;
            int _id_number = 0;
    };
}
