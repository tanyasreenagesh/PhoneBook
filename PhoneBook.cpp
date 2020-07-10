#include "PhoneBook.hpp"
#include <iostream>


unsigned int INITIAL_CAP = 10;

PhoneBook::PhoneBook(std::string name)
    : ownerName{name}, totalContacts{0}
{
}

bool PhoneBook::contains(const std::string& cName, const std::string& cNum)
{
    for (unsigned int i = 0; i < book.size(); i++)
    {
        if (book[i].fullName == cName && book[i].number == cNum)
            return true;
    }
    return false;
}

bool PhoneBook::contains(const std::string& cName)
{
    for (unsigned int i = 0; i < book.size(); i++)
    {
        if (book[i].fullName == cName)
            return true;
    }
    return false;
}

void PhoneBook::addNewContact(const std::string& fullName, const std::string& number, const std::string& email, const std::string& addy)
{
    if (contains(fullName, number))
    {
        std::string ans;
        std::cout << "This contact is already in the book. Would you like to update their information instead? (Y/N): " << std::endl;
        std::cin >> ans;
        if (ans == "Y")
            updateContact(fullName, number, email, addy);
    }
    else
    {
        book.push_back({fullName,number,email,addy});
        totalContacts++;
    }
}

void PhoneBook::deleteContact(const std::string& fullName, const std::string& number)
{
    if(!contains(fullName,number))
        std::cout << "This contact does not exist in your phone book." << std::endl;
    else
    {
        for(unsigned int i = 0; i < book.size(); i++)
        {
            if (book[i].fullName == fullName && book[i].number == number)
            {
                book.erase(book.begin()+i); //might have to -1
            }
        }
        totalContacts--;
    }
    
}

void PhoneBook::updateContact(const std::string& fullName, const std::string& number, const std::string& newName, const std::string& newNumber, const std::string& email, const std::string& addy)
{
    if(!contains(fullName,number))
    {
        std::string ans;
        std::cout << "This contact does not exist in your phone book. Would you like to add contact? (Y/N): " << std::endl;
        std::cin >> ans;
        if (ans == "Y")
            addNewContact(newName, number, email, addy);
    }
    else
    {
        for(unsigned int i = 0; i < book.size(); i++)
        {
            if (book[i].fullName == fullName && book[i].number == number)
            {
                book[i] = {newName,newNumber,email,addy};
            }
        }
    }
}

void PhoneBook::findContact(const std::string& cName)
{
    findResults.clear();
    for(unsigned int i = 0; i < book.size(); i++)
    {
        size_t found = book[i].fullName.find(cName);
        if (found != std::string::npos)
        {
            findResults.push_back(book[i]);
        }
        
    }
    if (findResults.empty())
        std::cout << "No such contacts exist in your phone book." << std::endl;
    else
        printSearchResults();
}

std::string PhoneBook::getOwner()
{
    return ownerName;
}

void PhoneBook::setOwner(const std::string& newName)
{
    ownerName = newName;
}

unsigned int PhoneBook::numOfContacts()
{
    return totalContacts;
}

void PhoneBook::printBook()
{
    std::cout << "NAME" << std::string(16, ' ') << "NUMBER" << std::string(14, ' ') << "EMAIL" << std::string(15, ' ') << "ADDRESS" << std::endl;
    for(unsigned int i = 0; i < book.size(); i++)
    {
        std::cout << book[i].fullName << std::string(20-book[i].fullName.length(), ' ') << book[i].number << std::string(20-book[i].number.length(), ' ') << book[i].email << std::string(20-book[i].email.length(), ' ') << book[i].addy << std::endl;
    }
}

void PhoneBook::printSearchResults()
{
    std::cout << "We found the following contacts with similar names: " << std::endl;
    for(unsigned int i = 0; i < findResults.size(); i++)
    {
        std::cout << i+1 << ". " << findResults[i].fullName << std::endl;
    }
}