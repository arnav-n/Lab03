#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData {
  public:
    demogData(string inN, string inS, int in65, int in18,
        int in5, int inBA, int inHS, int belowPov, int totalPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), bachelorDegreeUp(inBA), highSchoolUp(inHS),
            belowPoverty(belowPov), population2014(totalPop14) {
    }
    /* leaving for testing framework - imperfect */
    demogData(string inN, string inS, int in65, int in18, int in5) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), bachelorDegreeUp(0), highSchoolUp(0),
            belowPoverty(0), population2014(0) {
    }

    string getName()  const { return name; }
    string getState()  const { return state; }
    /* these return percents */
    double getpopOver65()  const { return 100.0f*(double)(popOver65)/population2014; }
    double getpopUnder18() const { return 100.0f*(double)(popUnder18)/population2014; }
    double getpopUnder5() const{ return 100.0f*(double)(popUnder5)/population2014; }
    double getBAup() const { return 100.0f*(double)(bachelorDegreeUp)/population2014; }
    double getHSup() const { return 100.0f*(double)(highSchoolUp)/population2014; }
    double getBelowPoverty() const { return 100.0f*(double)(belowPoverty)/population2014; }

    //these are counts
    int getpopOver65Count() const { return popOver65; }
    int getpopUnder18Count() const { return popUnder18; }
    int getpopUnder5Count() const { return popUnder5; }
    int getBAupCount() const { return bachelorDegreeUp; }
    int getHSupCount() const { return highSchoolUp; }
    int getBelowPovertyCount() const { return belowPoverty; }

    int getPop() const { return population2014; }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    const string name;
    const string state;
    /* store counts */
    const int popOver65;
    const int popUnder18;
    const int popUnder5;
    const int bachelorDegreeUp;
    const int highSchoolUp;
    const int belowPoverty;
    int population2014;
};
#endif
