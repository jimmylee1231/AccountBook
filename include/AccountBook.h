
enum class MENU
{
    INPUT = 0,
    SPA,
    TERMINATE
}

enum class INPUT_MENU
{
    INCOME,
    OUTCOME
}

class AccountBook
{
public:
    MENU printAndGetMenu();
    bool isProgramTerminate();
    INPUT_MENU printAndGetInputMenu();
    void runInput(INPUT_MENU inputMenu);
    void runSPA();
    void setProgramTerminate();
    void initialize();

private:
    bool isTermiate;
};