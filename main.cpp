#include <iostream>
#include <string>
#include "PhoneBook.hpp"


void add(PhoneBook& pb)
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
    std::cout << "\n" << fullName << " has been added to your PhoneBook." << std::endl;
}

void deleteC(PhoneBook& pb)
{
    std::string fullName, number;
    std::cout << "Who would you like to delete from the PhoneBook?" << std::endl;
    std::cout << "Full Name: ";
    std::cin.ignore();
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number);

    pb.deleteContact(fullName, number);
    std::cout << "\n" << fullName << " has been deleted from your PhoneBook." << std::endl;
}

void update(PhoneBook& pb)
{
    std::string fullName, number, newName, newNumber, newEmail, newAddress;
    std::cout << "Which contact would you like to update?" << std::endl;
    std::cout << "Full Name: ";
    std::cin.ignore();
    std::getline(std::cin,fullName);
    std::cout << "Number:    ";
    std::getline(std::cin,number);

    std::cout << "Please enter the updated information." << std::endl;
    std::cout << "Full Name: ";
    std::getline(std::cin,newName);
    std::cout << "Number:    ";
    std::getline(std::cin,newNumber); 
    std::cout << "Email:     ";
    std::getline(std::cin,newEmail);
    std::cout << "Address:   ";
    std::getline(std::cin,newAddress);   

    pb.updateContact(fullName, number, newName, newNumber, newEmail, newAddress);
    std::cout << "\n" << fullName << "'s information has been updated in your PhoneBook." << std::endl;
}

void find(PhoneBook pb)
{
    std::string name;
    std::cout << "Enter name of the contact you would like to look up: ";
    std::cin.ignore();
    std::getline(std::cin,name);
    std::cout << "\n";
    pb.findContact(name);
}

void print(PhoneBook pb)
{
    std::cout << "Here is your complete PhoneBook.\n" << std::endl;
    pb.printBook();
    std::cout << std::endl << std::endl;
}

void check(PhoneBook pb)
{
    int num = pb.numOfContacts();
    if(num == 1)
        std::cout << "You have 1 contact in your PhoneBook." << std::endl;
    else
    {
        std::cout << "You have " << num << " contacts in your PhoneBook." << std::endl;

    }
}

void viewOwner(PhoneBook& pb)
{
    std::cout << "Name of the PhoneBook owner: " << pb.getOwner() << std::endl;
}

void changeOwner(PhoneBook& pb)
{
    std::string newName, ans;
    std::string oldName = pb.getOwner();
    std::cout << "Enter the new owner name: ";
    std::cin.ignore();
    std::getline(std::cin,newName);

    std::cout << "Are you sure you would like to change owner name "
    "from " << oldName << " to " << newName << "? (Y/N)" << std::endl; 
    std::cin >> ans;

    if(ans == "Y")
    {
        pb.setOwner(newName);
        std::cout << "\nOwner name has been changed successfully." << std::endl;
    }      
}

void processCommand(const std::string& c, PhoneBook& pb)
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
    else if(c == "V")
    {
        viewOwner(pb);
    }
    else if(c == "O")
    {
        changeOwner(pb);
    }
    else
    {
        std::cout << "Please enter a valid option." << std::endl;
    }
    
}

std::string promptUser()
{
    std::string option;

    std::cout << "\nMENU" << std::endl;
    std::cout << "  A : Add a new contact" << std::endl;
    std::cout << "  D : Delete a contact" << std::endl;
    std::cout << "  U : Update a contact" << std::endl;
    std::cout << "  F : Find a contact" << std::endl;
    std::cout << "  P : Print your PhoneBook" << std::endl;
    std::cout << "  C : Check how many contacts are stored" << std::endl;
    std::cout << "  V : View owner name" << std::endl;
    std::cout << "  O : Change owner's name" << std::endl;
    std::cout << "  Q : Exit the PhoneBook" << std::endl;

    std::cout << "\nEnter your option: ";
    std::cin >> option;
    std::cout << std::endl;

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

    std::string owner;
    std::cout << "Enter name of PhoneBook owner: ";
    std::getline(std::cin,owner);

    PhoneBook pb(owner);
    

    std::string option;
    option = promptUser();

    
    while(option != "Q")
    {
        processCommand(option, pb);

        option = promptUser();
    }

    std::cout << "Your PhoneBook is now closed.\n" << std::endl;
    return 0;
}

