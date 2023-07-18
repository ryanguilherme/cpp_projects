//
// Created by ryan on 18/07/23.
//

#include "../lib/Item.h"

/*  ==============================================
 *  Function:    Item()
 *  Type:        constructor
 *  Description: Item default constructor
 *  ==============================================
 */
Item::Item() {
    this->name = "";
    this->price = 0.0;
    this->weight = 0.0;
}

/*  ==============================================
 *  Function:    Item()
 *  Type:        constructor
 *  Description: Item constructor with parameters
 *  ==============================================
 */
Item::Item(std::string name, double price, double weight) {

    this->name = name;
    this->price = price;
    this->weight = weight;

}

/*  ==============================================
 *  Function:    changePrice
 *  Type:        bool
 *  Description: Item price modifier
 *  ==============================================
 */
bool Item::changePrice(double price) {

    this->price = price;
    return true;

}

/*  ==============================================
 *  Function:    getName
 *  Type:        string
 *  Description: Return item's name
 *  ==============================================
 */
std::string Item::getName() {

    return this->name;

}

/*  ==============================================
 *  Function:    getPrice
 *  Type:        double
 *  Description: Return item's price
 *  ==============================================
 */
double Item::getPrice() {

    return this->price;

}

/*  ==============================================
 *  Function:    Item()
 *  Type:        double
 *  Description: Return item's weight
 *  ==============================================
 */
double Item::getWeight() {

    return this->weight;

}


