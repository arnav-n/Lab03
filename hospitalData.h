#ifndef HOSP_H
#define HOSP_H

#include <string>
#include <iostream>
#include <utility>
#include "rating.h"

using namespace std;

/*
  class to represent hospital data
  from CORGIS
*/
class hospitalData {
  public:
	 //constructor for starting code - make complete by adding rating
    hospitalData(string inN, string inS, string inType, int inOv, string inMort, string inReadmit) :
            name(inN), state(inS), type(inType), overallRate(inOv), mortality(inMort), readmission(inReadmit) {
    }
    string getName() const { return name; }
    string getState() const { return state; }
    string getType() const { return type; }
    int getOverallRate() const { return overallRate; }
    rating getMortality() const { return mortality; }
    rating getReadmit() const { return readmission; }

   friend std::ostream& operator<<(std::ostream &out, const hospitalData &HD);

private:
    const string name;
    const string state;
    const string type;

    int overallRate;
    rating mortality;
    rating readmission;
};

#endif
