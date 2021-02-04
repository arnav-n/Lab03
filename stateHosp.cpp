#include "stateHosp.h"
#include "hospitalData.h"
#include <sstream>
#include <string>
#include <iostream>
#include <assert.h>
#include <iomanip>

 //TODO implement state hospital data

 //function to add a hospital's data to the state's data
void stateHosp::addHosp(shared_ptr<hospitalData> localhosp){
    //double check that the hospital's state is this one
    assert(name.compare(localhosp->getState())==0);


    

    //if the star rating exists, calculate the new average rating
    //otherwise ignore the rating
    int localRate = localhosp->getOverallRate();
    if (localRate!=-1){
        double temp = 
        (overallRate*getReal())+(localhosp->getOverallRate()); 
        temp = temp/(getReal()+1);
        // overallRate += localRate;
        overallRate = temp;
        setReal(getReal()+1);
    }

    //none of this shit works:
    int lmNum = localhosp->getMortality().getRatingNum();
    int lrNum = localhosp->getReadmit().getRatingNum();
    int validRcount = getRCount();
    int validMcount = getMCount();
    //if the local hospital has a data entry, add the number value to the state's number value, using the same algo as the avg
    if (lmNum!=-999){
        validMcount++;  
        setMAgg(getMortality().getRatingNum()+lmNum);
        setMcount(validMcount);
    }
    if (lrNum!=-999){
        double temp = (getReadmit().getRatingNum()*validRcount)+lrNum; 
        temp = temp/(validRcount+1);
        validRcount++;
        getReadmit().setRatingNum(temp);
        setRcount(validRcount);
    }
    //until here
    numHospitals++;
}

std::ostream& operator<<(std::ostream &out, const stateHosp &sh){
    out<<"State Info: "<<sh.getState()<<"\n";
    out<<"Number of Hospitals: "<<sh.getCount()<<"\n";
    out << std::setprecision(2) << std::fixed <<"Overall Rating: "<<sh.getOverallRate()<<"\n";
    out<<"Mortality Rating: "<<sh.getMortality();
    out<<"Valid Mcount: "<<sh.getMCount()<<"\n";
    out<<"Readmission Rating: "<<sh.getReadmit();
    out<<"Valid Rcount: "<<sh.getRCount()<<"\n";


    return out;
}
