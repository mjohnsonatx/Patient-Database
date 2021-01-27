//    Thus far, this is a simple program that contains a class Patient that holds
// the individuals name, age, weight, home medicine, and allergies.

// The program will be able to sort and search the patients by ID number and name.

// To do:
// headers to display the information better for patient demographics,
// allergies, and medications.

// error checks for adding new patients, make it max_Size 100

#include "patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>

int main ( )
{
    int num_patients = 0, size, new_patients, limit;
    Patient patient[10];
    Allergies reported_allergy; // instant of allergies
    DailyMeds daily_meds; // instant of daily meds struct to pass to instant of patient
    bool more = false;

    std::string a, b, c, d, e, f, answer, name;
    int l, num_meds = 0, num_allergies = 0, choice, id, p, q = 0; // q is a counter for file input
    double h, o;

    std::string g,//
           j, // allergy
           k, // reaction
           m, // med
           n; // dose

    std::ifstream fin;
    fin.open ("patients.txt");

    if (!fin)
        std::cout << "********INPUT FILE FAILED TO OPEN********";
    else {
        while (fin >> id) {
            patient[num_patients].setId(id);

            getline(fin >> std::ws, name);
            patient[num_patients].setName(name);

            fin >> std::ws >> p;
            patient[num_patients].setAge(p);

            fin >> std::ws >> o;
            patient[num_patients].setWeight(o);
            for (int i = 0; i < 2; i++){
                getline(fin >> std::ws, j);
                reported_allergy.substance = j;

                getline(fin >> std::ws, k);
                reported_allergy.reaction = k;

                patient[num_patients].setAllergies(reported_allergy, num_allergies);
            }
            for (int i = 0; i < 2; i++){
                getline(fin >> std::ws, m);
                getline(fin >> std::ws, n);

                daily_meds.med = m;
                daily_meds.dose = n;
                patient[num_patients].setDailyMeds(daily_meds, num_meds);
            }
        num_patients++;
        }
    }
    do {
        std::cout <<"Please make a selection: \n"
                  << "1. Enter new patient demographics.\n"
                  << "2. Add or amend patient allergies.\n"
                  << "3. Add or amend daily medications.\n"
                  << "4. Display patient demographics. \n"
                  << "5. Display patient allergies.\n"
                  << "6. Display home medication(s).\n"
                  << "7. Exit the program.\n";
        std::cin >> choice;

        while(choice < 1 || choice > 7)
        {
            std::cout << "Please enter 1, 2, 3, 4, 5, 6, or 7: \n";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                std::cout << "How many patients need to be registered?\n";
                std::cin >> new_patients;
                limit = new_patients + num_patients;

                for (int i = num_patients; i < limit ; i++){
                    std::cout << "Enter the patients name: \n";
                    getline(std::cin >> std::ws, n);
                    patient[i].setName(n);

                    std::cout << "Enter the patient's age: \n";
                    std::cin >> std::ws >> l;
                    patient[i].setAge(l);

                    std::cout << "Enter the patient's weight (in pounds): \n";
                    std::cin >> std::ws >> h;
                    patient[i].setWeight(h);

                    patient[i].setId(i);
                }
                num_patients = limit;
                break;
            case 2:
                for (int i = 0; i < num_patients; ++i)
                    {
                    std::cout << "Does the patient have any allergies? \n";
                    std::cin >> answer;

                    if (answer == "Yes" || answer == "yes"){
                        do {
                            answer = "no";
                            std::cout << "Please enter the allergy: ";
                            getline(std::cin >> std::ws, a);

                            std::cout << "Please enter the reaction: ";
                            getline(std::cin >> std::ws, b);

                            reported_allergy.substance = a;
                            reported_allergy.reaction = b;

                            patient[i].setAllergies(reported_allergy, num_allergies);

                            std::cout << "Is there more: ";
                            getline(std::cin >> std::ws, answer);

                            if (answer == "yes" || answer == "Yes")
                                more = true;
                            else
                                more = false;
                        }while (more);
                    }
                }
                    break;
            case 3:
                more = false; // reset the flag
                for (int i = 0; i < num_patients; ++i)
                    {
                    std::cout << "Does the patient take any medications? ";
                    std::cin >> answer;

                    if (answer == "Yes" || answer == "yes"){
                        do {
                            answer = "no"; // reset answer
                            std::cout << "Medication: ";
                            std::cin >> std::ws >> d;

                            std::cout << "What is the dose? ";
                            getline(std::cin >> std::ws, e);

                            daily_meds.med = d;
                            daily_meds.dose = e;

                            patient[i].setDailyMeds(daily_meds, num_meds);

                            std::cout << "Is there more? ";
                            getline(std::cin >> std::ws, answer);

                            if ( answer== "yes" || answer == "Yes")
                                more = true;
                            else
                                more = false;
                        }while (more);
                    }
                }
                break;
            case 4:
                std::cout << "Number of patient counter: " << num_patients << std::endl<<std::endl;
                for (int i = 0; i < num_patients; ++i){
                    std::cout << "Patient Name: " << patient[i].getName()
                              << "\nPatient Age: " << patient[i].getAge()
                              << "\nPatient Weight: " << patient[i].getWeight()
                              << "\nPatient ID number: " << patient[i].getId()
                              << "\n\n";
                }
                break;
            case 5:
                for (int i = 0; i < num_patients; ++i){
                    patient[i].displayAllergies (std::cout, num_allergies);
                    std::cout << "\n";
                    }
                break;
            case 6:
                for (int i = 0; i < num_patients; ++i){
                    patient[i].displayDailyMeds (std::cout, num_meds);
                }
                break;
            }
        }while (choice != 7);

    if (choice == 7)
        {
        std::cout << "Program Termninated." << std::endl;
        return 0;
        }
fin.close();
return 0;
}
