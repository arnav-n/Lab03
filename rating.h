#ifndef RATING_H
#define RATING_H

#include <string>
#include<iostream>

using namespace std;

class rating {
  public:
    //default
    rating(){
        aggregated=0;
        phrase = "Same";
    }

    //constructor that takes in a number
    rating(double inRating)  {
        //TODO fill in
        aggregated = inRating;
        phrase = "";
    }

    //constructor that takes in a string
    rating(string inRating) {
        //TODO fill in
        phrase = inRating;
        //to do: depending on the rating, add a value to the aggregated score
        if(inRating=="Below")
            aggregated=-1;
        else if (inRating=="Same")
            aggregated=0;
        else if (inRating=="Above")
            aggregated=1;
        else aggregated=-999;
    }

    //a method to return a string based on the current rating TODO complete
    const string getRating() const;
    double getRatingNum() const;

    void setRatingNum(double input);

    friend std::ostream& operator<<(std::ostream &out, const rating &r) {
        //TODO fill in
        out<< r.aggregated << ", ";
        out << r.phrase <<"\n";
        return out;
    }

    //TODO write operator overload

private:
     //TODO decide what data to represent
    double aggregated;
    string phrase; 
};
#endif
