//
// Created by ryan on 16/05/23.
//
#include "Item.h"
#include <map>
#include <iostream>

#ifndef MARKET_MANAGER_STOCK_H
#define MARKET_MANAGER_STOCK_H

class Stock {

private:

    std::map<std::string, int> countItems;
    std::map<std::string, Item> items;
    int size = 0;

public:

    int getSize();
    bool addItem( Item item, int volume );
    bool removeItem( const std::string& itemName, int volume );
    std::map<std::string, Item> getStockItems();
    std::map<std::string, int> getStockItemsVolume();

};

#endif //MARKET_MANAGER_STOCK_H
