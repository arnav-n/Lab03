#include "dataAQ.h"
#include "parse.h"
#include <iostream>
#include "tddFuncs.h"
#include <memory>
using namespace std;

int main() {


cout << "Testing hospital sort..." << endl;

	dataAQ theAnswers;

    //Would like to add test to query between the two (may need to specify more) 

    //read in a csv file and create a vector of objects representing hospital data
    std::vector<shared_ptr<hospitalData>> theHospitalData = read_csvHospital(
            "hospitals.csv", HOSPITAL);
    
    //print vector of hospitals
    // for (int i = 0; i<theHospitalData.size();i++){
    //   cout<<*theHospitalData[i]<<endl;
    // }
    theAnswers.createStateHospData(theHospitalData);
    std::vector<shared_ptr<demogData>> theData = read_csv(
            "county_demographics.csv", DEMOG);

    theAnswers.createStateDemogData(theData);
    // // debug print out
    // map<string, stateHosp*>:: iterator it;
    // for (it = theAnswers.allStateHospData.begin(); it!=theAnswers.allStateHospData.end(); it++){
    //     cout<<*(it->second)<<endl;
    // }
    // cout<<"done printing list"<<endl;


    // string lowO = theAnswers.LowHospRating();
    // string highO = theAnswers.HighHospRating();

    // stateHosp* x = theAnswers.allStateHospData[lowO];
    // stateDemog* xs = theAnswers.allStateDemogData[lowO];
    // cout<<"the state with lowest overall rating is: "<<x->getState()<<endl;
    // cout<<*x<<endl;
    // cout<<"Demographic data for that state is: "<<endl;
    // cout<<*xs<<endl;
    // cout<<"Demographic data for that state is: "<<*(theAnswers.allStateDemogData[lowO])<<endl;
    
    
    // cout<<theAnswers.HighMortHospRating()<<endl;
    // cout<<theAnswers.HighReadmitHospRating()<<endl;

    std::vector<stateHosp*> hospHighToLow;
    theAnswers.sortStateHospRatingHighLow(hospHighToLow);
    cout<<endl;

    std::vector<stateHosp*> hospLowToHigh;
    theAnswers.sortStateHospRatingLowHigh(hospLowToHigh);
    cout<<endl;


    // std::vector<stateDemog*> povHighToLow;
    // theAnswers.sortStateDemogPovLevelHighLow(povHighToLow);


    // // Test case #1
    // string topHosp[] {"WI", "SD", "UT", "HI", "ID"};

    // //only test if vector valid
    // if (hospHighToLow.size() > 5 ) {
    //   for (int i=0; i < 5; i++) {
  	//    ASSERT_EQUALS(topHosp[i], hospHighToLow.at(i)->getState());
    //   }
    // } else {
    //   cout << "FAIL due to invalid vector size - fix all code for lab03" << endl;
    // }

  return 0;
}
