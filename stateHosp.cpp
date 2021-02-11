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

    int localMortNum = localhosp->getMortality().getRatingNum();
    int validMcount = getMCount();
    //if rating is valid, add to current average
    if (localMortNum>0){
        //convert average to total
        mortality*=validMcount;
        //add local count to total
        mortality+=localhosp->getMortality();
        //increase the valid counter, convert total back to average
        validMcount++;
        mortality/=validMcount;
        //set variable to new mCount
        setMcount(validMcount);
    }

    int localReNum = localhosp->getReadmit().getRatingNum();
    int validRcount = getRCount();
    if (localReNum>0){
        readmission*=validRcount;
        readmission+=localReNum;
        validRcount++;
        readmission/=validRcount;
        setRcount(validRcount);
    }
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
