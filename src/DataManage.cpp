#include "../include/DataManager.h"
#include <fstream>

DataManager::DataManager()
{
}
void DataManager::save()
{
    ofstream outFile(filename);
    string line;
    if (outFile.is_open())
    {
        //뭔갈 저장하고
        /*
        INCOME type  : date, type, amount
        OUTCOME type : date, type, name, category, amount
        */
        for (auto data_set : accountData)
        {
            for (auto data : data_set.second)
            {
                line = "";
                line += data.getDate();
                line += "," + to_string((int)data.getType());
                if (data.getType() == DATA_TYPE::OUTCOME)
                {
                    line += "," + data.getName();
                    line += "," + data.getCategory();
                }
                line += "," + to_string(data.getAmount());
                outFile << line << endl;
            }
        }
        outFile.close();
    }
    else
    {
        cout << filename << " can't be opened" << endl;
    }
}
void DataManager::load()
{
}