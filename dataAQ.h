#ifndef DATAAQ_H
#define DATAAQ_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "stateDemog.h"
#include "stateHosp.h"

/*
  data aggregator and query for testing
*/
class dataAQ {
  public:
    dataAQ();

    /* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
    void createStateDemogData(std::vector<shared_ptr<demogData>> theData);

    void createStateHospData(std::vector<shared_ptr<hospitalData>> theData);

    //return the name of the state with the largest population under age 5
    string youngestPop();
    //return the name of the state with the largest population under age 18
    string teenPop();
    //return the name of the state with the largest population over age 65
    string wisePop();
    //return the name of the state with the largest population who did not finish high school
    string underServeHS();
    //return the name of the state with the largest population who completed college
    string collegeGrads();

    string getMinTeenPop();


    string LowHospRating();
    string HighHospRating();
    string HighMortHospRating();
    string HighReadmitHospRating();

    void sortStateHospRatingHighLow(std::vector<stateHosp *>& hospHighToLow);
    void sortStateHospRatingLowHigh(std::vector<stateHosp *>& hospLowToHigh);
    void sortStateDemogPovLevelLowHigh(std::vector<stateDemog*>& incomeHighLow);
    void sortStateDemogPovLevelHighLow(std::vector<stateDemog*>& povLevelHighLow);
    
    friend std::ostream& operator<<(std::ostream &out, const dataAQ &allStateData);

    //For lab02 solution... 
    std::map<string, stateDemog*> allStateDemogData;

    //For lab03 use a similar structure....
    std::map<string, stateHosp*> allStateHospData;


};
#endif
