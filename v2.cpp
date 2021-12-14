#include "v11class.h"

Student::Student (const Student& df) 
{
    vardas_ = df.vardas_;
    pavarde_ = df.pavarde_;
    galutinis_paz_ = df.galutinis_paz_;
    egz_paz_ = df.egz_paz_;
    galutinis_ = df.galutinis_;
    
    for (int i=0; i!=nd_paz_.size(); i++) {
        nd_paz_[i] = df.nd_paz_[i];
    }
}

Student& Student::operator=(const Student& st) {
    if (&st == this) {
        return *this;
    }
    vardas_ = st.vardas_;
    pavarde_ = st.pavarde_;
    galutinis_paz_ = st.galutinis_paz_;
    egz_paz_ = st.egz_paz_;
    galutinis_ = st.galutinis_;

    for (int i=0; i!=nd_paz_.size(); i++) {
        nd_paz_[i] = st.nd_paz_[i];
    }
    return *this;
}

Student::Student () 
{
    vardas_ = pavarde_ = "";
    nd_paz_.reserve(columncount-3);
    wordread_.reserve(columncount);
    galutinis_ =0;
    galutinis_paz_ = 0;
    egz_paz_ = 0;
}    

void Student::setwordread(vector <string> v) {
    wordread_ = v;    
}   

