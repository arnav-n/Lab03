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

/* Lab03 fill in */

string dataAQ::LowHospRating() {
	//TODO fix
	return "fixMe";
}

string dataAQ::HighHospRating() {
	//TODO fix
	return "fixMe";
}

string dataAQ::HighMortHospRating(){
	//TODO fix
	return "fixMe";
}

string dataAQ::HighReadmitHospRating() {
	//TODO fix
	return "fixMe";
}

void dataAQ::sortStateHospRatingHighLow(std::vector<stateHosp *>& hospHighToLow) {
	//TODO fix
}

void dataAQ::sortStateHospRatingLowHigh(std::vector<stateHosp *>& hospLowToHigh) {
	//TODO fix
}

void dataAQ::sortStateDemogPovLevelLowHigh(std::vector<stateDemog*>& incomeHighLow) {
	//TODO fix
}

void dataAQ::sortStateDemogPovLevelHighLow(std::vector<stateDemog*>& povLevelHighLow) {
	//TODO fix
}


