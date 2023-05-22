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

Account::Account(std::string login, std::string password) {

    this->login = login;
    this->password = password;

}

std::string Account::getLogin() {

    return this->login;

}

std::string Account::getPassword() {

    return this->password;

}

bool Account::changePassword(std::string password, std::string newPassword) {

    if (password == this->password) {
        this->password = std::move(newPassword);
        return true;
    }

    return false;

}

#endif //ACCOUNT_H
