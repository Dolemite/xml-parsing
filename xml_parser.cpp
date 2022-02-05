#include <iostream>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
using namespace std;
using namespace xercesc;

int main() {

   try {
      XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
      // Do your failure processing here
      return 1;
   }
   cout << "Hello, world of Xerces parsing!" << endl;

   XercesDOMParser* parser = new XercesDOMParser();
   const char* xmlFile = "books.xml";

   try {
      parser->parse(xmlFile);
      const DOMDocument* document = parser->getDocument();
      DOMElement* catalog = document->getDocumentElement();
      DOMElement* book = catalog->getFirstElementChild();
      while(book) {
         DOMElement* bookChild = book->getFirstElementChild();
         while(bookChild) {
            const XMLCh* key = bookChild->getNodeName();
            XMLCh* titleKey = XMLString::transcode("title");
            if (XMLString::equals(key, titleKey)) {
               if (bookChild->getFirstChild() != NULL) {
                  char* value = XMLString::transcode(bookChild->getFirstChild()->getNodeValue());
                  string bookTitle = value;
                  cout << bookTitle << endl;
                  XMLString::release(&value);
               }
            }
            XMLString::release(&titleKey);
            bookChild = bookChild->getNextElementSibling();
         }
         book = book->getNextElementSibling();
      }
   }
   catch (const XMLException& toCatch) {
      char* message = XMLString::transcode(toCatch.getMessage());
      cout << "Exception message is: \n"
           << message << "\n";
      XMLString::release(&message);
      return -1;
   }
   catch (const DOMException& toCatch) {
      char* message = XMLString::transcode(toCatch.msg);
      cout << "Exception message is: \n"
           << message << "\n";
      XMLString::release(&message);
      return -1;
   }
   catch (...) {
      cout << "Unexpected Exception \n";
      return -1;
   }

   delete parser;
   XMLPlatformUtils::Terminate();
   return (EXIT_SUCCESS);
}
