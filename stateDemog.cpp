#include "stateDemog.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

 //note this stores a running total of population counts
//just adds the current county info to the running total
void stateDemog::addCountytoState(shared_ptr<demogData> CI) {
	assert(state.compare(CI->getState()) == 0);
	popOver65 += CI->getpopOver65Count();
	popUnder18 += CI->getpopUnder18Count();
	popUnder5 += CI->getpopUnder5Count();
	bachelorDegreeUp += CI->getBAupCount();
	highSchoolUp += CI->getHSupCount() ;
    belowPoverty += CI->getBelowPovertyCount();
	population2014 += CI->getPop();
	numCounties++;
}


/* print state data - as average of all the county data */
std::ostream& operator<<(std::ostream &out, const stateDemog&SD) {
    out << "State Info: " << SD.state;
    out << "\nNumber of Counties: " << SD.numCounties;
    out << std::setprecision(2) << std::fixed;
    out << "\nPopulation info: \n(over 65): " << SD.getpopOver65() << "\% and total: ";
    out << SD.getpopOver65Count();
    out << "\n(under 18): " << SD.getpopUnder18() << "\% and total: ";
    out << SD.getpopUnder18Count();
    out << "\n(under 5): " << SD.getpopUnder5() << "\% and total: ";
    out << SD.getpopUnder5Count();
    out << "\nEducation info: \n(Bachelor or more): " << SD.getBAup() << "\% and total: ";
    out << SD.getBAupCount() ;
    out << "\n(high school or more): " << SD.getHSup() << "\% and total: ";
    out << SD.getHSupCount();
    out << "\npersons below poverty: " << SD.getBelowPoverty() << "\% and total: ";
    out << SD.getBelowPovertyCount();
    out << "\nTotal population: " << SD.population2014;
    return out;
}
