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

};

Item::Item() {
    this->name = "";
    this->price = 0.0;
    this->weight = 0.0;
}

Item::Item(std::string name, double price, double weight) {

    this->name = name;
    this->price = price;
    this->weight = weight;

}

bool Item::changePrice(double price) {

    this->price = price;
    return true;

}

std::string Item::getName() {

    return this->name;

}

#endif //ITEM_H
