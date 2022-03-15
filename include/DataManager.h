#include "../include/AccountData.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class DataManager
{
public:
    DataManager();
    void save();
    void load();

private:
    string filename = "AccountBook.data";
    map<string, vector<AccountData>> accountData;
}