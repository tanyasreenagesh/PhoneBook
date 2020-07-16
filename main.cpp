#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "PhoneBookOptions.hpp"

int main()
{
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

