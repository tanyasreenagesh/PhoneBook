#include "PhoneBookOptions.hpp"
#include <iostream>

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

    if(ans == "Y" || ans == "y")
    {
        pb.setOwner(newName);
        std::cout << "\nOwner name has been changed successfully." << std::endl;
    }      
}

void processCommand(const std::string& c, PhoneBook& pb)
{
    if(c == "A" || c == "a")
    {
        add(pb);
    }
    else if(c == "D" || c == "d")
    {
        deleteC(pb);
    }
    else if(c == "U" || c == "u")
    {
        update(pb);
    }
    else if(c == "F" || c == "f")
    {
        find(pb);
    }
    else if(c == "P" || c == "p")
    {
        print(pb);
    }
    else if(c == "C" || c == "c")
    {
        check(pb);
    }
    else if(c == "V" || c == "v")
    {
        viewOwner(pb);
    }
    else if(c == "O" || c == "o")
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

    std::cout << "\n------------------- MENU -------------------" << std::endl;
    std::cout << "  A : Add a new contact" << std::endl;
    std::cout << "  D : Delete a contact" << std::endl;
    std::cout << "  U : Update a contact" << std::endl;
    std::cout << "  F : Find a contact" << std::endl;
    std::cout << "  P : Print your PhoneBook" << std::endl;
    std::cout << "  C : Check how many contacts are stored" << std::endl;
    std::cout << "  V : View owner name" << std::endl;
    std::cout << "  O : Change owner's name" << std::endl;
    std::cout << "  Q : Exit the PhoneBook" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    std::cout << "\nEnter your option: ";
    std::cin >> option;
    std::cout << std::endl;

    return option;
}