#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <vector>

class PhoneBook
{
public:
    // constructor
    PhoneBook(std::string name);

    //PhoneBook(const PhoneBook& other);
    //PhoneBook& operator=(const PhoneBook& other);
    //~PhoneBook(); 


    // member functions

    bool contains(const std::string& cName, const std::string& cNum);
    bool contains(const std::string& cName);

    void addNewContact(const std::string& fullName, const std::string& number, const std::string& email = "", const std::string& addy = "");

    void deleteContact(const std::string& fullName, const std::string& number);

    void updateContact(const std::string& fullName, const std::string& number, const std::string& newName, const std::string& email = "", const std::string& addy = "");

    void findContact(const std::string& cName);

    unsigned int numOfContacts();

    void printBook();

    void printSearchResults();


private:
    struct Contact
    {
        std::string fullName;
        std::string number;
        std::string email;
        std::string addy;
    };

    std::string ownerName;
    //int ownerID;

    unsigned int totalContacts;

    std::vector<Contact> book;
    std::vector<Contact> findResults;

};


#endif