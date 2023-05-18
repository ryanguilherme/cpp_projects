#include <iostream>
#include "Account.h"
#include "Item.h"
#include "Stock.h"
#include "MainFunctions.h"
#include <vector>

using namespace std;

int main() {

    // data
    bool logged = false;
    vector<Item> itemList;
    vector<Account> accountList;
    Stock stock = *new Stock();

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
        if ( option == 2 ) { removeItem( &itemList );   }

        // list items
        if ( option == 3 ) { listItems( itemList );     }


        if ( option == 4 ) {
            
        }

        if ( option == 0 ) {
            logged = false;
            system("clear");
            cout << "Logging off..." << std::endl;
            goto loginScreen;
        }


    }




}
