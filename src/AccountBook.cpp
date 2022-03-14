#include <iostream>
#include "../include/AccountBook.h"

using namespace std;

AccountBook::AccountBook()
{
    isTermiate = false;
}
void AccountBook::initialize()
{
}
MENU AccountBook::printAndGetMenu()
{
    MENU menu;

    int input;
    while (true)
    {
        cout << endl;
        cout << "---------- Please select menu ----------" << endl;
        cout << "1. Input" << endl;
        cout << "2. Spend Pattern Analysis" << endl;
        cout << "3. Terminate" << endl;

        cin >> input;
        if (input > (int)MENU::NONE && input < (int)MENU::LAST)
        {
            menu = (MENU)input;
            break;
        }
        else
        {
            cout << "You entered wrong menu" << endl;
            cout << "Please select menu again" << endl;
        }
    }

    return menu;
}
bool AccountBook::isProgramTerminate()
{
}
INPUT_MENU AccountBook::printAndGetInputMenu()
{
    INPUT_MENU menu;

    int input;
    while (true)
    {
        cout << endl;
        cout << "---------- Please select input menu ----------" << endl;
        cout << "1. Income" << endl;
        cout << "2. Outcome" << endl;

        cin >> input;
        if (input > (int)INPUT_MENU::NONE && input < (int)INPUT_MENU::LAST)
        {
            menu = (INPUT_MENU)input;
            break;
        }
        else
        {
            cout << "You entered wrong menu" << endl;
            cout << "Please select input menu again" << endl;
        }
    }

    return menu;
}
void AccountBook::runInput(INPUT_MENU inputMenu)
{
}
void AccountBook::runSPA()
{
}
void AccountBook::setProgramTerminate()
{
    isTermiate = true;
}