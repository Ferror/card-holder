#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "XMLCardHolder.h"

class Controller
{
    private:
        XMLCardHolder* holder;

    public:
        Controller(XMLCardHolder* holder);
        ~Controller();
        void createCard();
        void removeCard();
        void editCard();
        void import();
        void exportToXML();
        void search();
        void print();
};

#endif
