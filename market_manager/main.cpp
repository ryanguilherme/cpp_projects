#include <iostream>
#include "Account.h"
#include "Item.h"
#include "Stock.h"
#include <vector>

using namespace std;

void loginMenu() {

    cout << "\n"
            "+--------------------+\n"
            "|       LOGIN        |\n"
            "+--------------------+\n"
            "| 1 - Create Account |\n"
            "| 2 - LOGIN          |\n"
            "+--------------------+\n"
            "";
}

//void menu() {
//
//
//
//}

int main() {

    bool running = true;
    bool logged = false;
    vector<Account> accountList;
    Stock stock = *new Stock();

    loginScreen:
    while (!logged) {
        loginMenu();
        int option;
        cout << "type: ";
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
                        cout << "Login successfull" << endl;
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





}
