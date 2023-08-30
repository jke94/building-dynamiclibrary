#include "pch.h"

#include <iostream>

namespace ObserverApi
{
    Observer::Observer(int id_number, ISubject& subject) : subject_(subject)
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