//
// Created by ryan on 18/07/23.
//

#include "../lib/MainFunctions.h"

/*  ==============================================
 *  Function:    loginMenu
 *  Type:        void
 *  Description: Print's market manager login menu
 *  ==============================================
 */
void loginMenu() {

    std::cout << "\n"
                 "+--------------------+\n"
                 "|   MARKET MANAGER   |\n"
                 "+--------------------+\n"
                 "| 1 - Create Account |\n"
                 "| 2 - LOGIN          |\n"
                 "| 0 - Exit           |\n"
                 "+--------------------+\n"
                 "";
}

/*  ==============================================
 *  Function:    menu
 *  Type:        void
 *  Description: Print's market manager main menu
 *  ==============================================
 */
void menu() {

    std::cout << "\n"
                 "+-----------------+\n"
                 "|      MENU       |\n"
                 "+-----------------+\n"
                 "| 1 - Add Item    |\n"
                 "| 2 - Remove Item |\n"
                 "| 3 - List Items  |\n"
                 "| 4 - Stock       |\n"
                 "| 0 - Exit        |\n"
                 "+-----------------+\n"
                 "";

}

/*  ==============================================
 *  Function:    accountMenu
 *  Type:        void
 *  Description: Print's market manager account menu
 *  ==============================================
 */
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
            if ( loginExists ) { continue; }

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
        system("clear");
        std::cout << std::endl << "error: Invalid option!" << std::endl;
    }
}

/*  ==============================================
 *  Function:    stockMenu
 *  Type:        void
 *  Description: Print's market manager Stock menu
 *  ==============================================
 */
void stockMenu() {
    std::cout << "\n"
                 "+--------+------------------------+\n"
                 "| OPTION |       STOCK MENU       |\n"
                 "+--------+------------------------+\n"
                 "|   1.   | INCREASE ITEM STOCK    |\n"
                 "|   2.   | DECREASE ITEM STOCK    |\n"
                 "|   3.   | SHOW STOCK             |\n"
                 "|   0.   | EXIT                   |\n"
                 "+--------+------------------------+\n"
                 "";
}

/*  ==============================================
 *  Function:    addItem
 *  Type:        void
 *  Description: Add a Item to the main vector of items
 *  ==============================================
 */
void addItem( std::vector<Item> *itemList ) {
    std::string itemName;
    std::cout << "Item Name: ";
    std::cin >> itemName;
    bool validItem = true;
    for ( auto item : *itemList) {
        if ( item.getName() == itemName ) {
            validItem = false;
            system("clear");
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
        system("clear");
        std::cout << std::endl << "Item successfully added" << std::endl;
    }
}

/*  ==============================================
 *  Function:    removeItem
 *  Type:        void
 *  Description: Remove a Item from the main vector
 *               of items
 *  ==============================================
 */
void removeItem( std::vector<Item> *itemList ) {
    if ( itemList->empty() ) {
        system("clear");
        std::cout << std::endl << "No item to remove!" << std::endl;
    } else {
        system("clear");
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
        std::cout << "Type a item number to remove: ";
        int itemIndexToRemove;
        std::cin >> itemIndexToRemove;

        // check if the item index is valid, if is, remove
        if ( itemIndexToRemove >= 0 && itemIndexToRemove < itemList->size() ) {
            itemList->erase( itemList->begin() + itemIndexToRemove );
            system("clear");
            std::cout << "Item successfully removed" << std::endl;
        } else {
            system("clear");
            std::cout << "error: Invalid item number" << std::endl;
        }
    }
}


// option 3
/*  ==============================================
 *  Function:    listItems
 *  Type:        void
 *  Description: Print's a list of the current Items
 *               stored on the main Item's vector
 *  ==============================================
 */
void listItems( const std::vector<Item>& itemList ) {
    if ( itemList.empty() ) {
        system("clear");
        std::cout << "No item to list" << std::endl;
    } else {
        system("clear");
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

//option 4
/*  ==============================================
 *  Function:    showStock
 *  Type:        void
 *  Description: Print's a list of the current
 *               Items stored on the main Stock,
 *               showing Price, Weight and Volume
 *  ==============================================
 */
void showStock( Stock *stock ) {
    if (stock->getSize() == 0 ) {
        system("clear");
        std::cout << "Empty stock" << std::endl;
    } else {
        std::cout << "\n"
                     "+---+----------------------------------+---------+----------+----------------+\n"
                     "|   |              ITEM                |  PRICE  |  WEIGHT  |     VOLUME     |\n"
                     "+---+----------------------------------+---------+----------+----------------+\n"
                     "";
        for ( auto item : stock->getStockItems() ) {
            std::cout << "|   | " <<  item.first;
            for ( int i = 0; i < (33 - item.first.size()); i++ ) {
                std::cout << " ";
            }
            std::cout << "| ";
            std::cout << std::fixed << std::setprecision(2) << item.second.getPrice();
            for ( int i = 0; i < (9 - std::to_string(item.second.getPrice()).size() + 3); i++ ) {
                std::cout << " ";
            }
            std::cout << "| ";
            std::cout << std::fixed << std::setprecision(2) << item.second.getWeight();
            for ( int i = 0; i < (10 - std::to_string(item.second.getWeight()).size() + 3); i++ ) {
                std::cout << " ";
            }
            std::cout << "| ";
            std::cout << std::fixed << std::setprecision(2) << stock->getStockItemsVolume()[item.second.getName()];
            for ( int i = 0; i < (17 - std::to_string(stock->getStockItemsVolume()[item.second.getName()]).size() - 2); i++) {
                std::cout << " ";
            }
            std::cout << "|" << std::endl << "+---+----------------------------------+---------+----------+----------------+" << std::endl;
        }
    }
}
