#pragma once

#include "pch.h"

namespace ObserverApi
{
    class Observer : public IObserver
    {

        public:
            Observer(int id_number, ISubject& subject);

            virtual ~Observer();

            void Update(const std::string& message_from_subject);

            void RemoveMeFromTheList();

        private:
            std::string message_from_subject_;
            ISubject& subject_;
            int _id_number = 0;

            void PrintInfo();
    };
}