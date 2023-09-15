#ifndef CRITERIA_H
#define CRITERIA_H
#define CRITERIA_H

#include "defs.h"
#include "Photo.h"
#include <iostream>


using namespace std;

class Criteria {
public:
friend ostream& operator<<(ostream& ost, const Criteria& criteria){
    criteria.print(ost);
    return ost;
}
    virtual bool matches(const Photo&) const = 0;
    virtual void print(ostream&) const = 0;
};

class Cat_Criteria : virtual public Criteria {
public:
    string getCategory() const{
        return category;
    }

    Cat_Criteria(const string&);
    virtual bool matches(const Photo&) const;
    virtual void print(ostream&) const;

    private:
    string category;
};

class Date_Criteria : virtual public Criteria {
public:
    Date_Criteria(const Date& start, const Date& end);
    virtual bool matches(const Photo&) const;
    virtual void print(ostream&) const;
    Date getStart() const{
        return start;
    };
    Date getEnd() const{
        return end;
    }

    private:
    Date start;
    Date end;
};

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
public:
    CandD_Criteria(const Date&, const Date&, const string&);
    virtual bool matches(const Photo&) const;
    virtual void print(ostream&) const;
};

#endif