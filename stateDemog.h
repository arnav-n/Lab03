#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"

/*
  class to represent state data - fairly redundent at this point but will use
  inheritence next
*/
class stateDemog {
  public:
    stateDemog(string inS) :
            state(inS),
            popOver65(0), popUnder18(0),
            popUnder5(0), bachelorDegreeUp(0), highSchoolUp(0),
            belowPoverty(0), population2014(0), numCounties(0)  {
    }

  string getState() const { return state; }
  /* these return percentages */
  double getpopOver65() const  { return 100.0f*(double)(popOver65)/population2014; }
  double getpopUnder18() const  { return 100.0f*(double)(popUnder18)/population2014; }
  double getpopUnder5() const  { return 100.0f*(double)(popUnder5)/population2014; }
  double getBAup() const { return 100.0f*(double)(bachelorDegreeUp)/population2014; }
  double getHSup() const  { return 100.0f*(double)(highSchoolUp)/population2014; }
  double getBelowPoverty() const  { return 100.0f*(double)(belowPoverty)/population2014; }

  //these are counts
  int getpopOver65Count() const { return popOver65; }
  int getpopUnder18Count() const { return popUnder18; }
  int getpopUnder5Count() const { return popUnder5; }
  int getBAupCount() const { return bachelorDegreeUp; }
  int getHSupCount() const { return highSchoolUp; }
  int getBelowPovertyCount() const { return belowPoverty; }

  int getNumC() const { return numCounties; }
  int getPop() const { return population2014; }

  //note this stores a running total until averageOut - lots of ways to do this
  void addCountytoState(shared_ptr<demogData>  CI);

  friend std::ostream& operator<<(std::ostream &out, const stateDemog &SD);

private:

    const string state;
    /* store counts */
    int popOver65;
    int popUnder18;
    int popUnder5;
    int bachelorDegreeUp;
    int highSchoolUp;
    int belowPoverty;
    int population2014;
    
    int numCounties;
};
#endif
