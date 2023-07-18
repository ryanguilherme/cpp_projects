//
// Created by ryan on 18/07/23.
//

#include "../lib/Stock.h"

/*  ==============================================
 *  Function:    getSize
 *  Type:        int
 *  Description: Return stock's size (number of items)
 *  ==============================================
 */
int Stock::getSize() {

    return this->size;

}

/*  ==============================================
 *  Function:    addItem
 *  Type:        bool
 *  Description: Add a 'volume' number of items to
 *               the Stock hashmap structure
 *  ==============================================
 */
bool Stock::addItem( Item item, int volume ) {

    auto iterator = items.find(item.getName());
    if (iterator != items.end()) {
        // stock already have this item, so lets just increment the counter
        countItems[item.getName()] += volume;
        this->size += volume;
        return true;
    } else {
        // this item is not on the stock, then add and start the counter
        items[item.getName()] = item;
        countItems[item.getName()] = volume;
        this->size += volume;
        return true;
    }


}

/*  ==============================================
 *  Function:    removeItem
 *  Type:        bool
 *  Description: Remove a 'volume' number of items
 *               from Stock's hashmap structure
 *  ==============================================
 */
bool Stock::removeItem( const std::string& itemName, int volume ) {

    auto iterator = items.find(itemName);
    if (iterator != items.end()) {
        // there is this item to remove
        countItems[itemName] -= volume;
        this->size -= volume;
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

/*  ==============================================
 *  Function:    getStockItems
 *  Type:        map
 *  Description: Return Stock's hashmap structure
 *               that stores Stock items
 *  ==============================================
 */
std::map<std::string, Item> Stock::getStockItems() {

    return this->items;

}

/*  ==============================================
 *  Function:    getStockItemsVolume
 *  Type:        map
 *  Description: Return Stock's total volume
 *  ==============================================
 */
std::map<std::string, int> Stock::getStockItemsVolume() {

    return this->countItems;

}
