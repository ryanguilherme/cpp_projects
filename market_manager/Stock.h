//
// Created by ryan on 16/05/23.
//
#include "Item.h"
#include <map>

#ifndef MARKET_MANAGER_STOCK_H
#define MARKET_MANAGER_STOCK_H

class Stock {

private:

    std::map<std::string, int> countItems;
    std::map<std::string, Item> items;
    int size = 0;

public:

    int getSize();
    bool addItem(Item item);
    bool removeItem(const std::string& itemName);
    std::map<std::string, Item> getStockItems();
    std::map<std::string, int> getStockItemsVolume();

};

int Stock::getSize() {

    return this->size;

}

bool Stock::addItem(Item item) {

    auto iterator = items.find(item.getName());
    if (iterator != items.end()) {
        // stock already have this item, so lets just increment the counter
        countItems[item.getName()]++;
        this->size++;
        return true;
    } else {
        // this item is not on the stock, then add and start the counter
        items[item.getName()] = item;
        countItems[item.getName()] = 1;
        this->size++;
        return true;
    }


}

bool Stock::removeItem(const std::string& itemName) {

    auto iterator = items.find(itemName);
    if (iterator != items.end()) {
        // there is this item to remove
        std::cout << "Item successfully decreased" << std::endl;
        countItems[itemName]--;
        this->size--;
        // now we need to check if this was the last item of this name on the stock
        if (countItems[itemName] == 0) {
            // so that was the last, then we need to completely erase this from the stock
            items.erase(itemName);
            countItems.erase(itemName);
        }
        return true;
    }

    std::cout << "This item is not on Stock" << std::endl;
    return false;

}

std::map<std::string, Item> Stock::getStockItems() {

    return this->items;

}

std::map<std::string, int> Stock::getStockItemsVolume() {

    return this->countItems;

}


#endif //MARKET_MANAGER_STOCK_H
