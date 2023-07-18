//
// Created by ryan on 16/05/23.
//
#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
private:

    std::string name;
    double price;
    double weight;

public:

    Item();
    Item(std::string name, double price, double weight);
    bool changePrice(double price);
    std::string getName();
    double getPrice();
    double getWeight();

};

#endif //ITEM_H
