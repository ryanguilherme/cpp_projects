//
// Created by ryan on 18/05/23.
//
#include "Item.h"
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef MARKET_MANAGER_MAINFUNCTIONS_H
#define MARKET_MANAGER_MAINFUNCTIONS_H

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
