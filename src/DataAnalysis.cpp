#include "../include/DataAnalysis.h"
#include <iostream>

using namepace std;

void DataAnalysis::selectTarget(string date, string date_end = "")
{
    // year : 2022
    // month : 202203
    // daily : 20220302
    // period : 20220301(date), 20220305(date_end)
    this->date = date;
    this->date_end = date_end;
    this->dateKey = date + date_end;
}
void DataAnalysis::analyze(ANALYSIS_TYPE type, ANALYSIS_MODE mode)
{
    swtich(mode)
    {
    case ANALYSIS_MODE::NETCOME:
        /* mode == ANALYSIS_MODE::NETCOME
        Total income : 1000000
        Total outcome : 650000
        Your spend rate : 65%
        You have spent a lot 또는
        You are saving well
        */
        int spend_rate = (100 * analysisDataOutcome[type][dateKey]) / analysisDataIncome[type][dateKey];
        cout << "Total income : ";
        cout << analysisDataIncome[type][dateKey] << endl;
        cout << "Total outcome : ";
        cout << analysisDataOutcome[type][dateKey] << endl;
        cout << "Your spend rate : ";
        cout << spend_rate << "%" << endl;
        if (spend_rate > wasteRate)
            cout << "You have spent a lot." << endl;
        else
            cout << "You are saving well." << endl;
        break;
    case ANALYSIS_MODE::CATEGORY_COME:
        /*
        Category
        You have spent 얼마 at 카테고리 이름(퍼센티지%) at most
        */
        int maxSpendMoney = 0;
        string maxSpendCategoryName = "";
        for (auto data : analysisDataOutcomeByCategory[type][dateKey])
        {
            if (data.second > maxSpendMoney)
            {
                maxSpendMoney = data.second;
                maxSpendCategoryName = data.first;
            }
        }
        int spend_rate = (100 * maxSpendMoney) / analysisDataIncome[type][dateKey];
        cout << "Category" << endl;
        cout << "You have spent ";
        cout << maxSpendMoney << " at ";
        cout << maxSpendCategoryName << "(";
        cout << spend_rate << "%)  at most" << endl;
        break;
    default:
        break;
    }
}
#include <map>
using namespace std;
void DataAnalysis::makeAnalysisData(ANALYSIS_TYPE type, ANALYSIS_MODE mode,
                                    map<string, vector<AccountData>> data)
{
    map<int> temp;
    temp.cl
        analysisDataIncome[type][dateKey]
            .clear();
    for (auto p : data)
    {
        if (getDateKey(p.first, type) != dateKey)
            continue;
        for (auto val : p.second)
        {
            switch (val.getType())
            {
            case DATA_TYPE::INCOME:
                analysisDataIncome[type][dateKey] += val.getAmount();
                break;
            case DATA_TYPE::OUTCOME:
                switch (mode)
                {
                case ANALYSIS_MODE::NETCOME:
                    analysisDataOutcome[type][dateKey] += val.getAmount();
                    break;
                case ANALYSIS_MODE::CATEGORY_COME:
                    analysisDataOutcomeByCategory[type][dateKey][val.getCategory()] += val.getAmount();
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}