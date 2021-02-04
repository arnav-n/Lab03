#ifndef STATEH_H
#define STATEH_H

#include <memory>
#include <string>
#include <iostream>
#include "hospitalData.h"

/*
  class to represent state hospital data - fairly redundent at this point but will use
  inheritence next
*/
class stateHosp {
  //TODO implement
public:
  stateHosp(string statename){ 
    name=statename;
    numHospitals = 0;
    overallRate = 0;
    validMCount = 0;
    validRCount = 0;
  }
  string getState() const { return name; }
  int getCount() const { return numHospitals; }
  void addHosp(shared_ptr<hospitalData> localhosp);

  int getRCount() const { return validRCount; }
  int getMCount() const{ return validMCount; }

  double getOverallRate() const { return overallRate; }
  rating getMortality() const { return mortality; }
  rating getReadmit() const { return readmission; }

  void setMcount(int x){ validMCount = x;};
  void setRcount(int x){ validRCount = x;};
  void setMAgg(double x){ mortality.setRatingNum(x);}
  void setRAgg(double x){ readmission.setRatingNum(x);}

  friend std::ostream& operator<<(std::ostream &out, const stateHosp &sh);
private:
  string name; 
  int numHospitals;
  double overallRate;
  
  //add rating vars for readmit and mort
  rating mortality;
  int validMCount;

  rating readmission; 
  int validRCount;
};
#endif
