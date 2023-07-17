# **Market Manager** _0.0.3_

## Description:

C++ developed application for manage a market system with funccionalities to add items, remove items and add/remove those items to a stock with high volumes, with account authentication.

## Developer(s)
- [Ryan Guilherme](https://github.com/ryanguilherme)

## **Install and execution** _(linux)_
### Only shell is required to run
### Download project files and start application:
```bash
git clone https://github.com/ryanguilherme/market_manager.git
cd market_manager/cmake-build-debug
./market_manager
```
---

## **Login Screen**
```
+--------------------+
|   MARKET MANAGER   |
+--------------------+
| 1 - Create Account |
| 2 - LOGIN          |
| 0 - Exit           |
+--------------------+
Choose an option: 
```
### _First screen shown after start_
* **Option 1:** _Create Account_ -> asks for a login and password with no requirements, check if the login already exists, if not, create successfully.
* **Option 2:** _LOGIN_ -> asks for a login and password, first check if the login exists, if exists, check if the password is correct and then authenticate.
* **Option 0:** _Exit_ -> print "Thank you for using market manager" "Exiting..." and then close the application.
---

## **Main Menu**
```
Login successfully

+-----------------+
|      MENU       |
+-----------------+
| 1 - Add Item    |
| 2 - Remove Item |
| 3 - List Items  |
| 4 - Stock       |
| 0 - Exit        |
+-----------------+
Choose an option: 
```

### _First screen shown after login_
* **Option 1:** _Add Item_ -> asks for a item name, price and weight. Check if already exists a item if this name, if not, create successfully.
* **Option 2:** _Remove Item_ -> ask only for a item name, if exists, remove the item.
* **Option 3:** _List Items_ -> shows a table with every item registered, with correspondent price and weight (example with a rice and gas item registered)
* **Option 4:** _Stock_ -> go to Stock menu.
* **Option 0:** _Exit_ -> LogOff and go back to login screen.
---

## **Stock Menu**
```
+--------+------------------------+
| OPTION |       STOCK MENU       |
+--------+------------------------+
|   1.   | INCREASE ITEM STOCK    |
|   2.   | DECREASE ITEM STOCK    |
|   3.   | SHOW STOCK             |
|   0.   | EXIT                   |
+--------+------------------------+
Choose an option:
```
### _Stock menu screen, shown after choose **Main menu** option 3 (show stock)_
* **Option 1:** _INCREASE ITEM STOCK- -> list every item registered like on main menu option 3, and then ask the user to choose a item and a volume to add to the stock
* **Option 2:** _DECREASE ITEM STOCK_ -> show the stock volume and ask for a item and volume to reduce, the item have to be added in the option 1 before
* **Option 3:** _SHOW STOCK_ -> show the stock screen with item name, price, weight and volume (example with 450 gas and 7600 rices)
* **Option 0:** _EXIT_ -> exit from stock menu and go back to main menu
---

## _Stock example, with gas and rice registered_
```
+---+----------------------------------+---------+----------+----------------+
|   |              ITEM                |  PRICE  |  WEIGHT  |     VOLUME     |
+---+----------------------------------+---------+----------+----------------+
|   | gas                              | 110.00  | 25.00    | 450            |
+---+----------------------------------+---------+----------+----------------+
|   | rice                             | 4.20    | 1.00     | 7600           |
+---+----------------------------------+---------+----------+----------------+

+--------+------------------------+
| OPTION |       STOCK MENU       |
+--------+------------------------+
|   1.   | INCREASE ITEM STOCK    |
|   2.   | DECREASE ITEM STOCK    |
|   3.   | SHOW STOCK             |
|   0.   | EXIT                   |
+--------+------------------------+
Choose an option:
```

![demo video](media/market_manager_demo.mp4)

### **TO DO**
## Move stock implementation from main.cpp to MainFunctions.h, add file system to save data




