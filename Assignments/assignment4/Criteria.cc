#include "Criteria.h"

Cat_Criteria::Cat_Criteria(const std::string& cat) : category(cat) {}

bool Cat_Criteria::matches(const Photo& photo) const {
    return (photo.getCategory() == category);
}

void Cat_Criteria::print(std::ostream& os) const {
    os << "Category Criteria: " << category << std::endl;
}

Date_Criteria::Date_Criteria(const Date& st, const Date& en) : start(st), end(en) {}

bool Date_Criteria::matches(const Photo& photo) const {
    Date photo_date = photo.getDate();
    return (photo_date >= start && photo_date <= end);
}

void Date_Criteria::print(std::ostream& os) const {
    os << "Date Criteria: " << start << " " << end << std::endl;
}



CandD_Criteria::CandD_Criteria(const Date& st, const Date& en, const std::string& cat)
    : Criteria(), Cat_Criteria(cat), Date_Criteria(st, en) {}

bool CandD_Criteria::matches(const Photo& photo) const {
    return (Cat_Criteria::matches(photo) && Date_Criteria::matches(photo));
}

void CandD_Criteria::print(std::ostream& os) const {
    os << "Category/date-criteria: " << Cat_Criteria::getCategory() << " " << Date_Criteria::getStart() << " " << Date_Criteria::getEnd() << endl;

}



