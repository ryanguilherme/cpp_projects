#include <iostream>
#include "Account.h"
#include "Item.h"
#include "Stock.h"
#include <vector>

using namespace std;

void loginMenu() {

    cout << "\n"
            "+--------------------+\n"
            "|   MARKET MANAGER   |\n"
            "+--------------------+\n"
            "| 1 - Create Account |\n"
            "| 2 - LOGIN          |\n"
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

    bool running = true;
    bool logged = false;
    vector<Item> itemList;
    vector<Account> accountList;
    Stock stock = *new Stock();

    loginScreen:
    while ( !logged ) {
        loginMenu();
        int option;
        cout << "choose an option: ";
        cin >> option;

        if ( option == 1 ) {
            bool registered = false;
            while (!registered) {
                string login;
                cout << "Login: ";
                cin >> login;
                bool loginExists = false;
                for (auto account : accountList) {
                    if ( account.getLogin() == login ) {
                        cout << "Login already exists" << endl;
                        loginExists = true;
                        break;
                    }
                }
                if ( loginExists ) {
                    loginExists = false;
                    continue;
                }
                string password;
                cout << "Password: ";
                cin >> password;

                // add account to a vector of accounts
                accountList.emplace_back(login, password);
                registered = true;

            }
        } else if ( option == 2 ) {
            string login;
            cout << "Login: ";
            cin >> login;
            for ( auto account : accountList ) {
                if ( account.getLogin() == login ) {
                    string password;
                    cout << "Password: ";
                    cin >> password;
                    if ( account.getPassword() == password ) {
                        cout << "Login successfully" << endl;
                        logged = true;
                        break;
                    } else {
                        cout << "Incorrect password" << endl;
                        break;
                    }
                }
                cout << "Invalid login" << endl;
                break;
            }
        }
    }
    // principal menu
    while ( logged ) {
        menu();
        int option;
        cout << "choose an option: ";
        cin >> option;

        // add item
        if ( option == 1 ) {
            string itemName;
            cout << "Item Name: ";
            cin >> itemName;
            bool validItem = true;
            for ( auto item : itemList) {
                if ( item.getName() == itemName ) {
                    validItem = false;
                    cout << "Item already exists" << endl;
                    break;
                }
            }
            if ( validItem ) {
                double itemPrice, itemWeight;
                cout << "Price: ";
                cin >> itemPrice;
                cout << "Weight: ";
                cin >> itemWeight;
                // add new item to items vector
                itemList.emplace_back( itemName, itemPrice, itemWeight );
                cout << "Item successfully added" << endl;
            }
        }

        if ( option == 2 ) {
            if ( itemList.empty() ) {
                cout << "No item to remove!" << endl;
            } else {
                int itemIndex = 0;
                cout << "\n"
                        "+--------------+\n"
                        "|     ITEM     |\n"
                        "+--------------+\n"
                        "\n"
                        "";
                for (auto item: itemList) {
                    cout << "|" << itemIndex << "." << item.getName();
                    itemIndex++;
                }
                cout << "+--------------+" << endl;
                cout << "Type a item number to remove: ";
                int itemIndexToRemove;
                cin >> itemIndexToRemove;

                // check if the item index is valid, if is, remove
                if ( itemIndexToRemove >= 0 && itemIndexToRemove < itemList.size() ) {
                    itemList.erase( itemList.begin() + itemIndexToRemove );
                    cout << "Item successfully removed" << endl;
                } else {
                    cout << "error: Invalid item number" << endl;
                }
            }
        }


    }




}
