//
// Created by ryan on 18/05/23.
//
#include "Item.h"
#include "Stock.h"
#include "Account.h"
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef MARKET_MANAGER_MAINFUNCTIONS_H
#define MARKET_MANAGER_MAINFUNCTIONS_H

void loginMenu();
void menu();
void accountMenu(bool *logged, std::vector<Account> *accountList);
void stockMenu();
void addItem(std::vector<Item> *itemList);
void removeItem(std::vector<Item> *itemList);
void listItems(const std::vector<Item>& itemList);
void showStock(Stock *stock);

#endif //MARKET_MANAGER_MAINFUNCTIONS_H
