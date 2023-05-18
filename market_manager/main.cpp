#include <iostream>
#include "Account.h"
#include "Item.h"
#include "Stock.h"
#include "MainFunctions.h"
#include <vector>
#include <iomanip>


using namespace std;

void loginMenu() {

    cout << "\n"
            "+--------------------+\n"
            "|   MARKET MANAGER   |\n"
            "+--------------------+\n"
            "| 1 - Create Account |\n"
            "| 2 - LOGIN          |\n"
            "| 0 - Exit           |\n"
            "+--------------------+\n"
            "";
}

void menu() {

    cout << "\n"
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
        cout << "| Choose an option: ";
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
            goto loginScreen;
        }


    }




}
