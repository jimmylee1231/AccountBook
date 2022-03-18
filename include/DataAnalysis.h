#pragma once
#include <string>
#include <map>
#include "AccountData.h"

using namespace std;

enum class ANALYSIS_MODE
{
    NONE,
    NETCOME,
    CATEGORY_COME,
    LAST
}

enum class ANALYSIS_TYPE
{
    NONE,
    PERIOD,
    YEARLY,
    MONTHLY,
    DAILY,
    LAST
}

class DataAnalysis
{
public:
    DataAnalysis()
    {
    }
    void selectTarget(string date, string date_end = "");
    void analyze(ANALYSIS_TYPE type, ANALYSIS_MODE mode);
    void makeAnalysisData(ANALYSIS_TYPE type, ANALYSIS_MODE mode,
                          map<string, vector<AccountData>> data);
    virtual void getDataKey(string date);

public:
    int wasteRate = 60;
    string date, date_end;
    string dateKey;
    // 2022 : year
    // 202203 : month
    // 20220302 : daily
    // 2022030120220305 : period
    map<string, int> analysisDataIncome;
    map<string, int> analysisDataOutcome;
    map<string, map<string, int>> analysisDataOutcomeByCategory;
}