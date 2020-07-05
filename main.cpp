#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{

    PhoneBook pb("Tanya");
    pb.addNewContact("John Wayne","9493234534","jwayne@uci.edu","32 Brook Way");
    pb.addNewContact("Tanya S.","9493122852");
    pb.addNewContact("Arish Imam","3058765432");
    pb.addNewContact("John Trudeau", "7865463227","trudeau@canada.com");
    pb.printBook();

    pb.addNewContact("JoJohn Rocks","5667543210");
    pb.updateContact("Tanya S.","9493122852","Tanya Sreenagesh","tsreenag@uci.edu");
    pb.addNewContact("Silas John","7853241122");
    pb.printBook();

    pb.findContact("John");
    std::cout << "Total number of contacts in your book = " << pb.numOfContacts() << std::endl;
    
    pb.findContact("Tamanna");
    return 0;
}

