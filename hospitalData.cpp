#include "hospitalData.h"
#include <sstream>


/* print hospital data partial - you must fill in*/
std::ostream& operator<<(std::ostream &out, const hospitalData &HD) {
    out << "Hospital Info: " << HD.name << ", " << HD.state;
    out << "\nType: " << HD.type;
    out << "\nOverall rating (out of 5): "<<HD.overallRate;
    out << "\nmortality rating: " <<HD.mortality;
    out << "readmission rating:" <<HD.readmission ;
    return out;
}
