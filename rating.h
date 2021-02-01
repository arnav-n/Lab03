#ifndef RATING_H
#define RATING_H

#include <string>
#include<iostream>

using namespace std;

class rating {
  public:
    //constructor that takes in a number
    rating(double inRating)  {
        //TODO fill in
    }

    //constructor that takes in a number
    rating(string inRating) {
        //TODO fill in
    }

    //a method to return a string based on the current rating TODO complete
    const string getRating() const;
    double getRatingNum() const;

    friend std::ostream& operator<<(std::ostream &out, const rating &r) {
        //TODO fill in
    }

    
    //TODO write operator overload


private:
     //TODO decide what data to represent
};
#endif
