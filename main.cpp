#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include "dataAQ.h"
#include "demogData.h"
#include "stateDemog.h"
#include "hospitalData.h"
#include "stateHosp.h"
#include "parse.h"

using namespace std;

int main() {

	dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<demogData>> theDemogData = read_csv(
            "county_demographics.csv", DEMOG);

    //read in a csv file and create a vector of objects representing each hospital data
    std::vector<shared_ptr<hospitalData>> theHospitalData = read_csvHospital(
            "hospitals.csv", HOSPITAL);

    //helper functions to aggregate the data
    theAnswers.createStateDemogData(theDemogData);

    //TODO: fix - this does nothing right now
    theAnswers.createStateHospData(theHospitalData);

    //set up output formating
    cout << std::setprecision(2) << std::fixed;

    //example from lab02
    // cout << "*** the state that needs the most high schools**" << endl;
    // string needHS = theAnswers.teenPop();
    // cout << *(theAnswers.allStateDemogData[needHS]) << endl;


    /*EXAMPLE extremum - TODO fix so this works*/
    /*
    string stateLowHospRate = theAnswers.LowHospRating();
    cout<< "The state with the lowest hospital rating is: " << stateLowHospRate << endl;
    //TODO print out the data
    cout << "\nDemographic data for that state is: \n";
    //TODO print out the data
    */

    /*EXAMPLE sort - TODO fix so this works*/
    /*
    std::vector<stateHosp*> hospHighToLow;
    theAnswers.sortStateHospRatingHighLow(hospHighToLow);
    cout << "the 10 states with highest hospital ratings sorted on overall: " << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << hospHighToLow.at(i)->getState();
        cout <<  " overall hospital rating: " << hospHighToLow.at(i)->getOverallRate() << endl;
    }*/

    return 0;
}

