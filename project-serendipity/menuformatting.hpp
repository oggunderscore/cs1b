#ifndef MENUFORMATTING_HPP_
#define MENUFORMATTING_HPP_

enum MenuOption {
    MENU_MAIN,
    MENU_CASHIER,
    MENU_INVENTORY,
    MENU_ADDBOOK,
    MENU_LOOKUPBOOK,
    MENU_EDITBOOK,
    MENU_DELETEBOOK,
    MENU_REPORTS
};

void printHeaderMenu(int option);
void printError(int option);

#endif