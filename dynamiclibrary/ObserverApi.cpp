#include "pch.h"

namespace ObserverApi
{
    Subject::~Subject()
    {
        std::cout << "Goodbye, I was the Subject.\n";
    }

    void Subject::Attach(IObserver* observer)
    {
        list_observer_.push_back(observer);
    }

    void Subject::Detach(IObserver* observer)
    {
        list_observer_.remove(observer);
    }

    void Subject::Notify()
    {
        std::list<IObserver*>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) 
        {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void Subject::CreateMessage(std::string message)
    {
        this->message_ = message;
        Notify();
    }

    void Subject::HowManyObserver()
    {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

    void Subject::SomeBusinessLogic()
    {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

    Observer::Observer(int id_number, Subject& subject) : subject_(subject)
    {
        this->subject_.Attach(this);
        this->_id_number = id_number;
        std::cout << "Hi, I'm the Observer \"" << this->_id_number << "\".\n";
    }

    Observer::~Observer()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->_id_number << "\".\n";
    }

    void Observer::Update(const std::string& message_from_subject)
    {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void Observer::RemoveMeFromTheList()
    {
        subject_.Detach(this);
        std::cout << "Observer \"" << _id_number << "\" removed from the list.\n";
    }

    void Observer::PrintInfo()
    {
        std::cout << "Observer \"" << this->_id_number << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }
}