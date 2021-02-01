#include "hospitalData.h"
#include <sstream>


/* print hospital data partial - you must fill in*/
std::ostream& operator<<(std::ostream &out, const hospitalData &HD) {
    out << "Hosptial Info: " << HD.name << ", " << HD.state;
    out << "\nType: " << HD.type;
    out << "\nOverall rating (out of 5): ";
    out << "\nmortality rating: " ;
    out << "\nreadmission rating:" ;
    return out;
}
