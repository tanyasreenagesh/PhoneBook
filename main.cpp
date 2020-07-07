#include <iostream>
#include <string>
#include "PhoneBook.hpp"


void add(PhoneBook pb)
{
    std::string fullName, number, email, address;
    std::cout << "Who would you like to add to the PhoneBook?" << std::endl;
    std::cout << "Full Name: ";
    std::cin.ignore();
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number);
    std::cout << "Email:     ";
    std::getline(std::cin,email);
    std::cout << "Address:   ";
    std::getline(std::cin,address);

    pb.addNewContact(fullName, number, email, address);
    std::cout << fullName << " has been added to your PhoneBook." << std::endl;
}

void deleteC(PhoneBook pb)
{
    std::string fullName, number;
    std::cout << "Who would you like to delete from the PhoneBook?" << std::endl;
    std::cout << "Full Name: ";
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number);

    pb.deleteContact(fullName, number);
    std::cout << fullName << " has been deleted from your PhoneBook." << std::endl;
}

void update(PhoneBook pb)
{
    std::string fullName, number, newName, newNumber, newEmail, newAddress;
    std::cout << "Which contact would you like to update?" << std::endl;
    std::cout << "Full Name: ";
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number);

    std::cout << "Please enter the updated information." << std::endl;
    std::cout << "Full Name: ";
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number); 
    std::cout << "Email:     ";
    std::getline(std::cin,newEmail);
    std::cout << "Address:   ";
    std::getline(std::cin,newAddress);   

    pb.updateContact(fullName, number, newName, newNumber, newEmail, newAddress);
    std::cout << fullName << "'s information has been updated in your PhoneBook." << std::endl;
}

void find(PhoneBook pb)
{
    std::string name;
    std::cout << "Enter name of the contact you would like to look up: ";
    std::getline(std::cin,name);

    pb.findContact(name);
}

void print(PhoneBook pb)
{
    std::cout << "Here is your complete PhoneBook." << std::endl;
    pb.printBook();
    std::cout << std::endl;
}

void check(PhoneBook pb)
{
    std::cout << "You currently have " << pb.numOfContacts() << " contacts in your PhoneBook." << std::endl;
}

void processCommand(const std::string& c, PhoneBook pb)
{
    if(c == "A")
    {
        add(pb);
    }
    else if(c == "D")
    {
        deleteC(pb);
    }
    else if(c == "U")
    {
        update(pb);
    }
    else if(c == "F")
    {
        find(pb);
    }
    else if(c == "P")
    {
        print(pb);
    }
    else if(c == "C")
    {
        check(pb);
    }
    else
    {
        std::cout << "Please enter a valid option." << std::endl;
    }
    
}

std::string promptUser()
{
    std::string option;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "A : Add a new contact?" << std::endl;
    std::cout << "D : Delete a contact?" << std::endl;
    std::cout << "U : Update a contact?" << std::endl;
    std::cout << "F : Find a contact?" << std::endl;
    std::cout << "P : Print your PhoneBook?" << std::endl;
    std::cout << "C : Check how many contacts are stored?" << std::endl;
    std::cout << "Q : Exit the PhoneBook?" << std::endl;

    std::cout << "Enter your option: ";
    std::cin >> option;

    return option;
}


int main()
{
    /*
    PhoneBook pb("Tanya");
    pb.addNewContact("John Wayne","9493234534","jwayne@uci.edu","32 Brook Way");
    pb.addNewContact("Tanya S.","9493102952");
    pb.addNewContact("Arish Imam","3058765432");
    pb.addNewContact("John Trudeau", "7865463227","trudeau@canada.com");
    pb.printBook();

    pb.addNewContact("JoJohn Rocks","5667543210");
    pb.updateContact("Tanya S.","9493102952","Tanya Sreenagesh","tsreenag@uci.edu");
    pb.addNewContact("Silas John","7853241122");
    pb.printBook();

    pb.findContact("John");
    std::cout << "Total number of contacts in your book = " << pb.numOfContacts() << std::endl;
    
    pb.findContact("Tamanna");

    pb.deleteContact("Tamanna", "7896543232");
    pb.deleteContact("John Wayne", "9493234534");

    pb.printBook();
    std::cout << "Total number of contacts in your book = " << pb.numOfContacts() << std::endl;
    */

    // Why is the class object getting refreshed every time?
    // Find a solution.

    PhoneBook pb("Owner");

    std::string option;
    option = promptUser();

    
    while(option != "Q")
    {
        processCommand(option, pb);

        option = promptUser();
    }

    std::cout << "Your PhoneBook is now closed." << std::endl;
    return 0;
}

