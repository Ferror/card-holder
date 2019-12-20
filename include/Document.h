#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../vendor/tinyxml2/tinyxml2.h"

class Document
{
    public:
        Document(tinyxml2::XMLDocument document);
        ~Document() = default;
};

#endif
