#pragma once
#include "DataManager.h"

enum class MENU
{
    NONE,
    INPUT,
    SPA,
    TERMINATE,
    LAST
};

enum class INPUT_MENU
{
    NONE,
    INCOME,
    OUTCOME,
    LAST
};

class AccountBook
{
public:
    AccountBook();
    MENU printAndGetMenu();
    bool isProgramTerminate();
    INPUT_MENU printAndGetInputMenu();
    void runInput(INPUT_MENU inputMenu);
    void runSPA();
    void setProgramTerminate();
    void initialize();

private:
    bool isTermiate;
    DataManager dataManager;
    DataAnalysis dataAnalysis;
};