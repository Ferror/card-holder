#ifndef XML_DOCUMENT_H
#define XML_DOCUMENT_H

#include "../vendor/tinyxml2/include/tinyxml2.h"
#include "Document.h"
#include "CardFactory.h"

class XMLDocument : public Document
{
    private:
        const char* fileName;
        CardFactory* factory;

    public:
        XMLDocument(const char* filename, CardFactory* factory);
        ~XMLDocument();
        std::vector<Card*> getCards() override;
};

#endif
