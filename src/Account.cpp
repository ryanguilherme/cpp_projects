//
// Created by ryan on 18/07/23.
//

#include "../lib/Account.h"

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
