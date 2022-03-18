#pragma once
#include <string>
#include <map>

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
        analysisDataIncome.reserve(ANALYSIS_TYPE::LAST);
        analysisDataOutcome.reserve(ANALYSIS_TYPE::LAST);
        analysisDataOutcomeByCategory.reserve(ANALYSIS_TYPE::LAST);
    }
    void selectTarget(string date, string date_end = "");
    void analyze(ANALYSIS_TYPE type, ANALYSIS_MODE mode);
    void makeAnalysisData(ANALYSIS_TYPE type, ANALYSIS_MODE mode,
                          map<string, vector<AccountData>> data);

public:
    int wasteRate = 60;
    string date, date_end;
    // 2022 : year
    // 202203 : month
    // 20220302 : daily
    // 2022030120220305 : period
    vector<map<string, int>> analysisDataIncome;
    vector<map<string, int>> analysisDataOutcome;
    vector<map<string, map<string, int>>> analysisDataOutcomeByCategory;
}