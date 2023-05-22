//
// Created by ryan on 21/05/23.
//
#include <iostream>
#include "Stock.h"
#include "Account.h"
#include "Item.h"
#include "lib/json.hpp"

#ifndef MARKET_MANAGER_SAVEDATA_H
#define MARKET_MANAGER_SAVEDATA_H
using json = nlohmann::json;

void saveData( const std::vector<Item>& itemList, const std::vector<Account>& accountList, const Stock& stock ) {
    json j;
    j["items"] = json::array();
    j["accounts"] = json::array();
    j["stock"] = stock.toJson();

    for ( const auto& item : itemList ) {
        j["items"].push_back(item.toJson());
    }

    for ( const auto& account : accountList ) {
        j["accounts"].push_back(account.toJson());
    }

    // store data
    std::ofstream file("data.json");
    file << j.dump(4);
    file.close();

}

void loadData( std::vector<Item>& itemList, std::vector<Account>& accountList, Stock& stock ) {
    json j;

    std::ifstream file("data.json");
    if (file.is_open()) {
        file >> j;
        file.close();
    }

    for ( const auto& itemJson : j["items"] ) {
        itemList.push_back(Item::fromJson(itemJson));
    }

    for ( const auto& accountJson : j["accounts"] ) {
        accountList.push_back(Account::fromJson(accountJson));
    }

    stock = Stock::fromJson(j["stock"]);

}

#endif //MARKET_MANAGER_SAVEDATA_H
