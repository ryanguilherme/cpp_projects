//
// Created by ryan on 16/05/23.
//
#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:

    std::string login;
    std::string password;

public:

    Account(std::string login, std::string password);
    std::string getLogin();
    std::string getPassword();
    bool changePassword(std::string password, std::string newPassword);

};

#endif //ACCOUNT_H
