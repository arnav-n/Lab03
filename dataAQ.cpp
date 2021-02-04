/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include <iostream>
#include <algorithm>

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateDemogData(std::vector<shared_ptr<demogData>> theData) {
	    //process the vector in our county data aggregate 
    for (const auto &obj : theData) {
        string stateName = obj->getState();
        //if first state entry, create it
        if (allStateDemogData.count(stateName) < 1) {
           //cout << "Making a new state entry: " << stateName << endl;
           allStateDemogData[stateName] = new stateDemog(stateName);
        }
        //either way now add this county info 
        //this keeps a running total
        allStateDemogData[stateName]->addCountytoState(obj);
    }
}

void dataAQ::createStateHospData(std::vector<shared_ptr<hospitalData>> theData) {
	//TODO fill in
    for (const auto &obj : theData) {
        string stateName = obj->getState();
        //if first state entry, create it
        if (allStateHospData.count(stateName) < 1) {
           //cout << "Making a new state entry: " << stateName << endl;
           allStateHospData[stateName] = new stateHosp(stateName);
        }
        //either way now add this county info 
        //this keeps a running total
        allStateHospData[stateName]->addHosp(obj);
    } 
}

//compare predicate on teen population (on map entry)
bool compareTeen(std::pair<std::string, stateDemog *> left, std::pair<std::string, stateDemog *> right) {
        return left.second->getpopUnder18() < right.second->getpopUnder18();
}

//predicate version
//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
  std::pair<std::string, stateDemog *> min 
      = *max_element(allStateDemogData.begin(), allStateDemogData.end(), compareTeen);
  return min.first; 
}


bool compareOverall(std::pair<std::string, stateHosp *> left1, std::pair<std::string, stateHosp *> right1) {

    // stateHosp* left = left1.second;
    // stateHosp* right = right1.second;
    
    // double Lpovc = left->getOverallRate();
    // double Lcount = left->getVRCount();
    // double LbelowPercent = Lpovc/Lcount;

    // double Rpovc = right->getOverallRate();
    // double Rcount = right->getVRCount();
    // double RbelowPercent = Rpovc/Rcount;


    // return LbelowPercent < RbelowPercent;
    return (left1.second->getOverallRate() < right1.second->getOverallRate());
}
bool compareVecOverall(stateHosp* left, stateHosp* right) {
    // double Lpovc = left->getOverallRate();
    // double Lcount = left->getCount();
    // double LbelowPercent = Lpovc/Lcount;

    // double Rpovc = right->getOverallRate();
    // double Rcount = right->getCount();
    // double RbelowPercent = Rpovc/Rcount;
    // return LbelowPercent < RbelowPercent;
    return left->getOverallRate() < right->getOverallRate();
}


bool comparePov(stateDemog* left, stateDemog* right) {
    double Lpovc = left->getBelowPovertyCount();
    double Lcount = left->getPop();
    double LbelowPercent = Lpovc/Lcount;

    double Rpovc = right->getBelowPovertyCount();
    double Rcount = right->getPop();
    double RbelowPercent = Rpovc/Rcount;


    return LbelowPercent < RbelowPercent;
}

bool compareMort(std::pair<std::string, stateHosp *> left, std::pair<std::string, stateHosp *> right) {
        return left.second->getMortality().getRatingNum() < right.second->getMortality().getRatingNum();
}

bool compareReadmit(std::pair<std::string, stateHosp *> left, std::pair<std::string, stateHosp *> right) {
        return left.second->getReadmit().getRatingNum() < right.second->getReadmit().getRatingNum();
}
/* Lab03 fill in */

string dataAQ::LowHospRating() {
	//TODO fix
	std::pair<std::string, stateHosp *> min  = *min_element(allStateHospData.begin(), allStateHospData.end(), compareOverall);
    return min.first;

}

string dataAQ::HighHospRating() {
	//TODO fix
    string name = "";
	std::pair<std::string, stateHosp *> max 
      = *max_element(allStateHospData.begin(), allStateHospData.end(), compareOverall);
    return max.first;
}

string dataAQ::HighMortHospRating(){
	//TODO fix
	std::pair<std::string, stateHosp *> max 
      = *max_element(allStateHospData.begin(), allStateHospData.end(), compareMort);
    // string maxfirst="MA";
    string maxfirst = max.first;
    return maxfirst;
}

string dataAQ::HighReadmitHospRating() {
	//TODO fix
	std::pair<std::string, stateHosp *> max 
      = *max_element(allStateHospData.begin(), allStateHospData.end(), compareReadmit);
    // string maxfirst="UT";
    string maxfirst = max.first;
    return maxfirst;
}

void dataAQ::sortStateHospRatingHighLow(std::vector<stateHosp *>& hospHighToLow) {
	//TODO fix
    map<string, stateHosp*>:: iterator it;
    for (it = allStateHospData.begin(); it!=allStateHospData.end(); it++){
        hospHighToLow.push_back(it->second);
    }
    std::sort(hospHighToLow.begin(), hospHighToLow.end(), compareVecOverall);
    std::reverse(hospHighToLow.begin(), hospHighToLow.end());
    // stateHosp * ID = hospHighToLow[1];
    // stateHosp * SD = hospHighToLow[2];
    // stateHosp * UT = hospHighToLow[3];
    // hospHighToLow[1] = SD;
    // hospHighToLow[2] = UT;
    // hospHighToLow[3] = hospHighToLow[4];
    // hospHighToLow[4] = ID;
}

void dataAQ::sortStateHospRatingLowHigh(std::vector<stateHosp *>& hospLowToHigh) {
	//TODO fix
    map<string, stateHosp*>:: iterator it;
    for (it = allStateHospData.begin(); it!=allStateHospData.end(); it++){
        hospLowToHigh.push_back(it->second);
    }
    std::sort(hospLowToHigh.begin(), hospLowToHigh.end(), compareVecOverall);
    // stateHosp * temp = hospLowToHigh[2];
    // hospLowToHigh[2] = hospLowToHigh[1];
    // hospLowToHigh[1] = temp;
    // hospLowToHigh[4] = hospLowToHigh[5];
}


void dataAQ::sortStateDemogPovLevelLowHigh(std::vector<stateDemog*>& incomeHighLow) {
	//TODO fix
   map<string, stateDemog*>:: iterator it;
    for (it = allStateDemogData.begin(); it!=allStateDemogData.end(); it++){
        incomeHighLow.push_back(it->second);
    }
    std::sort(incomeHighLow.begin(), incomeHighLow.end(), comparePov);
    
    // for(int i=0; i<10;i++){
    //     cout<<i<<" "<<incomeHighLow[i]->getState()<<" ";
    //     cout<<"poverty level: "<<incomeHighLow[i]->getBelowPovertyCount()<<endl;
    // }
}


void dataAQ::sortStateDemogPovLevelHighLow(std::vector<stateDemog*>& povLevelHighLow) {
	//TODO fix
    map<string, stateDemog*>:: iterator it;
    for (it = allStateDemogData.begin(); it!=allStateDemogData.end(); it++){
        povLevelHighLow.push_back(it->second);
    }

    std::sort(povLevelHighLow.begin(), povLevelHighLow.end(), comparePov);
    std::reverse(povLevelHighLow.begin(), povLevelHighLow.end());
    // for(int i=0; i<10;i++){
    //     double povc = povLevelHighLow[i]->getBelowPovertyCount();
    //     double count = povLevelHighLow[i]->getPop();

    //     double belowPercent = povc/count;
    //     cout<<i<<" "<<povLevelHighLow[i]->getState()<<" ";
    //     cout<<"poverty level: "<<belowPercent<<endl;
    // }
    
}


