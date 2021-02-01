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
    hospitalData(string inN, string inS, string inType) :
            name(inN), state(inS), type(inType) {
    }
    string getName() const { return name; }
    string getState() const { return state; }
    string getType() const { return type; }
    int getOverallRate() const;
    rating getMortality() const;
    rating getReadmit() const;

   friend std::ostream& operator<<(std::ostream &out, const hospitalData &HD);

private:
    const string name;
    const string state;
    const string type;

};

#endif
