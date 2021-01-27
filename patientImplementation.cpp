#include <iomanip>
#include "patient.h"
#include <iostream>

Patient::Patient () {
    name = "Jane Doe";
    age = 0;
    weight_lbs = 220.0;
    iD = 000;
}
Patient::Patient (std::string n, int a, double w, int d){
        n = name;
        a = age;
        w = weight_lbs;
        d = iD;
}
void Patient::setWeight (double w) {
        weight_lbs = w;
}
void Patient::setName (std::string n){
        name = n;
}
void Patient::setAge (int a) {
        age = a;
}
void Patient::setId (int i){
        iD = i;
}
void Patient::setAllergies (Allergies allergies, int &num_allergies) {
        allergy_list[num_allergies] = allergies;
        num_allergies++;
}
void Patient::setDailyMeds(DailyMeds dailymeds, int &num_meds) {
        dailyMeds[num_meds] = dailymeds;
        num_meds++;
        }
void Patient::displayAllergies(std::ostream& out, int num_allergies){  //should make prettier with setFill
    for (int i = 0; i<num_patients; i++) {
        std::cout << patient[i].getName() << std::endl;
        if (num_allergies == 0 )
            out << "The patient does not report allergies." << std::endl;

        else if (num_allergies == 1)
            out << "The patient has one allergy: " << allergy_list[0].substance
                << " which causes " << allergy_list[0].reaction << std::endl;
        else {
            out << "The patient has " << num_allergies << " allergies." << std::endl;
            out << "Allergy:" << std::setw(15) << "Reaction:" << std::endl;
                for (int i = 0; i < num_allergies; i++)
                {
                    out << allergy_list[i].substance << std::setw (15)
                        << allergy_list[i].reaction << std::endl;
                }
        }

}

void Patient::displayDailyMeds(std::ostream& out, int num_meds){   //should make prettier with setFill
    if (num_meds == 0)
        out << "No meds reported." << std::endl;
    else {
        out<<"Daily Medication: " << std::setw(10) << "Dose: " << std::endl;
        for(int i = 0; i < num_meds; i++)
        out << dailyMeds[i].med << std::setw(10) << dailyMeds[i].dose << std::endl;
         }
}
void Patient::displayPatientDemo (std::ostream& out) {}

double Patient::getWeight () const {return weight_lbs;}

std::string Patient::getName () const {return name;}

int Patient::getAge () const {return age;}

int Patient::getId () const {return iD;}

