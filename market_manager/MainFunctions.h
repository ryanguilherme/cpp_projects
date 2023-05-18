//
// Created by ryan on 18/05/23.
//
#include "Item.h"
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef MARKET_MANAGER_MAINFUNCTIONS_H
#define MARKET_MANAGER_MAINFUNCTIONS_H

void accountMenu( bool *logged, std::vector<Account> *accountList ) {
    int option;
    std::cout << "Choose an option: ";
    std::cin >> option;

    if ( option == 1 ) {
        bool registered = false;
        while (!registered) {
            std::string login;
            std::cout << "Login: ";
            std::cin >> login;
            bool loginExists = false;
            for (auto account : *accountList) {
                if ( account.getLogin() == login ) {
                    std::cout << "Login already exists" << std::endl;
                    loginExists = true;
                    break;
                }
            }
            if ( loginExists ) {
                loginExists = false;
                continue;
            }
            std::string password;
            std::cout << "Password: ";
            std::cin >> password;

            // add account to a vector of accounts
            system("clear");
            accountList->emplace_back(login, password);
            registered = true;
            std::cout << "Account registered successfully" << std::endl;

        }
    } else if ( option == 2 ) {
        std::string login;
        std::cout << "Login: ";
        std::cin >> login;
        for ( auto account : *accountList ) {
            if ( account.getLogin() == login ) {
                std::string password;
                std::cout << "Password: ";
                std::cin >> password;
                if ( account.getPassword() == password ) {
                    system("clear");
                    std::cout << "Login successfully" << std::endl;
                    *logged = true;
                    break;
                } else {
                    system("clear");
                    std::cout << "Incorrect password" << std::endl;
                    break;
                }
            }
            system("clear");
            std::cout << "Invalid login" << std::endl;
            break;
        }
    } else if ( option == 0 ) {
        std::cout << std::endl << "Thank you for using Market Manager" << std::endl << "Exiting..." << std::endl;
        exit(0);
    } else {
        std::cout << std::endl << "error: Invalid option!" << std::endl;
    }
}

void addItem( std::vector<Item> *itemList ) {
    std::string itemName;
    std::cout << "Item Name: ";
    std::cin >> itemName;
    bool validItem = true;
    for ( auto item : *itemList) {
        if ( item.getName() == itemName ) {
            validItem = false;
            std::cout << "Item already exists" << std::endl;
            break;
        }
    }
    if ( validItem ) {
        double itemPrice, itemWeight;
        std::cout << "Price: ";
        std::cin >> itemPrice;
        std::cout << "Weight: ";
        std::cin >> itemWeight;
        // add new item to items vector
        itemList->emplace_back( itemName, itemPrice, itemWeight );
        std::cout << "Item successfully added" << std::endl;
    }
}

void removeItem( std::vector<Item> *itemList ) {
    if ( itemList->empty() ) {
        std::cout << "No item to remove!" << std::endl;
    } else {
        int itemIndex = 0;
        std::cout << "\n"
                     "+----------------------------------+\n"
                     "|               ITEM               |\n"
                     "+----------------------------------+\n"
                     "";
        // list items
        for (auto item: *itemList) {
            std::cout << "| " << itemIndex << "." << item.getName();
            for ( int i = 0; i < (35 - (item.getName().size()) - 2 - std::to_string(itemIndex).size() - 1); i++){
                std::cout << " ";
            }
            std::cout << "|" << std::endl;
            itemIndex++;
        }
        std::cout << "+----------------------------------+" << std::endl;
        std::cout << "| Type a item number to remove: ";
        int itemIndexToRemove;
        std::cin >> itemIndexToRemove;

        // check if the item index is valid, if is, remove
        if ( itemIndexToRemove >= 0 && itemIndexToRemove < itemList->size() ) {
            itemList->erase( itemList->begin() + itemIndexToRemove );
            std::cout << "Item successfully removed" << std::endl;
        } else {
            std::cout << "error: Invalid item number" << std::endl;
        }
    }
}


// option 3
void listItems( const std::vector<Item>& itemList ) {
    if ( itemList.empty() ) {
        std::cout << "No item to list" << std::endl;
    } else {
        std::cout << "\n"
                "+----------------------------------+---------+----------+\n"
                "|               ITEM               |  PRICE  |  WEIGHT  |\n"
                "+----------------------------------+---------+----------+\n"
                "";
        for ( auto item : itemList ) {
            std::cout << "| " << item.getName();
            for ( int i = 0; i < (35 - item.getName().size() - 2); i ++ ) {
                std::cout << " ";
            }
            std::cout << "| ";
            std::cout << std::fixed << std::setprecision(2) << item.getPrice();
            for (int i = 0; i < (10 - std::to_string(item.getPrice()).size() + 2); i++) {
                std::cout << " ";
            }
            std::cout << "| ";
            std::cout << std::fixed << std::setprecision(2) << item.getWeight();
            for ( int i = 0; i < (11 - std::to_string(item.getWeight()).size() + 2); i++ ) {
                std::cout << " ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "+----------------------------------+---------+----------+" << std::endl;
    }
}

#endif //MARKET_MANAGER_MAINFUNCTIONS_H
