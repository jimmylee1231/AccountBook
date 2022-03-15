#include <string>

using namespace std;

enum class DATA_TYPE
{
    NONE,
    INCOME,
    OUTCOME,
    LAST
};

class AccountData
{
public:
    AccountData(
        string date,
        DATA_TYPE type,
        int amount,
        string name = "",
        string category = "");

private:
    string date;
    DATA_TYPE type;
    string name;
    string category;
    int amount;
};