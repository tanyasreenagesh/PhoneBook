#ifndef PHONEBOOK_OPTIONS
#define PHONEBOOK_OPTIONS

#include "PhoneBook.hpp"

void add(PhoneBook& pb);

void deleteC(PhoneBook& pb);

void update(PhoneBook& pb);

void find(PhoneBook pb);

void print(PhoneBook pb);

void check(PhoneBook pb);

void viewOwner(PhoneBook& pb);

void changeOwner(PhoneBook& pb);

void processCommand(const std::string& c, PhoneBook& pb);

std::string promptUser();

#endif