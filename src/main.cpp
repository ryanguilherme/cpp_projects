#include <iostream>
#include "../lib/Account.h"
#include "../lib/Item.h"
#include "../lib/Stock.h"
#include "../lib/MainFunctions.h"
#include <vector>

using namespace std;

int main() {
    system("clear");
    // data
    bool logged = false;
    vector<Item> itemList;
    vector<Account> accountList;
    Stock stock = *new Stock();
    bool onStock = false;

    loginScreen:
    while ( !logged ) {
        loginMenu();
        accountMenu( &logged, &accountList );
    }

    // principal menu
    while ( logged ) {
        menu();
        int option;
        cout << "Choose an option: ";
        cin >> option;

        // add item
        if ( option == 1 ) { addItem( &itemList );      }

        // remove item
        else if ( option == 2 ) { removeItem( &itemList );   }

        // list items
        else if ( option == 3 ) { listItems( itemList );     }

        else if ( option == 4 ) {
            onStock = true;
            int stockOption;
            while ( onStock ) {
                stockMenu();
                cout << "Choose an option: ";
                cin >> stockOption;
                if ( stockOption == 1 ) {
                    listItems( itemList );
                    if ( !itemList.empty() ) {
                        cout << "Available items to add" << endl;
                        string itemName;
                        cout << "Type an item name to add: ";
                        cin >> itemName;
                        bool added = false;
                        int itemVolume;
                        cout << "Type the volume you want to add: ";
                        cin >> itemVolume;
                        for ( auto item : itemList ) {
                            if ( itemName == item.getName() ) {
                                stock.addItem(item, itemVolume);
                                added = true;
                                system("clear");
                                cout << "Item successfully increased on stock" << endl;
                                break;
                            }
                        }
                        if ( !added ) {
                            system("clear");
                            cout << "This item doesnt exist" << endl;
                        }
                    }
                }
                else if ( stockOption == 2 ) {
                    showStock( &stock );
                    if ( !itemList.empty() ) {
                        cout << "Available items to remove" << endl;
                        string itemName;
                        cout << "Type an item name to remove: ";
                        cin >> itemName;
                        int itemVolume;
                        cout << "Type the volume to remove: ";
                        cin >> itemVolume;
                        for ( auto item : itemList ) {
                            if ( itemName == item.getName() ) {
                                if ( stock.getStockItemsVolume()[itemName] < itemVolume ) {
                                    cout << "There is not enough volume to remove" << endl;
                                    break;
                                } else {
                                    stock.removeItem( itemName, itemVolume );
                                    cout << "Item volume successfully decreased" << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if ( stockOption == 3 ) {
                    system("clear");
                    showStock( &stock );
                }
                else if ( stockOption == 0 ) {
                    system("clear");
                    cout << "Exiting from stock..." << endl;
                    onStock = false;
                }
                else {
                    system("clear");
                    cout << "Invalid option!" << endl;
                }
            }
        }

        else if ( option == 0 ) {
            logged = false;
            system("clear");
            cout << "Logging off..." << std::endl;
            goto loginScreen;
        }

        else {
            system("clear");
            cout << "Invalid option!" << endl;
        }


    }




}
