# **Market Manager** _0.0.3_
## author: Ryan Guilherme

### description: c++ developed application for manage a market system with funccionalities to add items, remove items and add/remove those items to a stock with high volumes, with account authentication.
<hr>

[demo video](media/market_manager_demo.mp4)

## login screen
[login screen](media/loginScreen.png)
### first screen shown after start
* option 1: Create Account -> asks for a login and password with no requirements, check if the login already exists, if not, create successfully.
* option 2: LOGIN -> asks for a login and password, first check if the login exists, if exists, check if the password is correct and then authenticate.
* option 0: Exit -> print "Thank you for using market manger" "Exiting..." and then close the application.
<hr>

## main menu
[menu screen](media/mainMenu.png)
### first screen shown after login
* option 1: Add Item -> asks for a item name, price and weight. Check if already exists a item if this name, if not, create successfully.
* option 2: Remove Item -> ask only for a item name, if exists, remove the item.
* option 3: List Items -> shows a table with every item registered, with correspondent price and weight (example with a rice and gas item registered):
[list items example](media/itemListScreen.png)
* option 4: go to Stock menu.
* option 0: LogOff and go back to login screen.

## stock menu
[stock menu](media/stockMenuScreen.png)
### stock menu screen, shown after choose main menu option 4 (show stock)
* option 1: INCREASE ITEM STOCK -> list every item registered like on main menu option 3, and then ask the user to choose a item and a volume to add to the stock
* option 2: DECREASE ITEM STOCK -> show the stock volume and ask for a item and volume to reduce, the item have to be added in the option 1 before
* option 3: SHOW STOCK -> show the stock screen with item name, price, weight and volume (example with 450 gas and 7600 rices)
[show stock screen](media/showStockScreen.png)
* option 0: EXIT -> exit from stock menu and go back to main menu


### **TO DO**
## move stock implementation from main.cpp to MainFunctions.h, add file system to save data
 



