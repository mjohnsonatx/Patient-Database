#include "patient.h"

int main ( )
{
    const int SIZE = 100;
    Patient patient;
    Allergies reported_allergy; // instant of allergies
    DailyMeds daily_meds;
    bool more = false;

    string a, b, c, d, e, f, answer, answer2, n;
    int g, l;
    double h, w;
    char x, z;
    bool yes, Yes = true;
    bool no, No = false;

    cout << "Is this a new patient? ";
    cin >> answer;

    if (answer == "yes" || answer == "Yes"){

        cout << "Enter the patients name: ";
        getline(cin >> ws, n);
        patient.setName(n);

        cout << "Enter the patient's age: ";
        cin >> ws >> l;
        patient.setAge(l);

        cout << "Enter the patient's weight (in pounds): ";
        cin >> ws >> h;
        patient.setWeight(h);
    }

    cout << "Does the patient have any allergies? ";
    cin >> answer;

    if (answer == "Yes" || answer == "yes"){
        do {
            cout << "Please enter the allergy: ";
            cin >> ws >> a;

            cout << "Please enter the reaction: ";
            cin >> ws >>b;

            reported_allergy.substance = a;
            reported_allergy.reaction = b;

            patient.setAllergies(reported_allergy);

            cout << "Is there more: ";
            getline(cin >> ws, answer);

            if (answer == "yes" || answer == "Yes"){
                more = true;

            } else
                more = false;
        }while (more);
        }

more = false; // reset the flag

        cout << "Does the patient take any medications? ";
        cin >> answer;

        if (answer == "Yes" || answer == "yes"){
            do {
                cout << "Medication: ";
                cin >> d;

                cout << "What is the dose? ";
                getline(cin >> ws, e);

                daily_meds.med = d;
                daily_meds.dose = e;

                patient.setDailyMeds(daily_meds);

                cout << "Is there more? ";
                getline(cin >> ws, answer2);


     if ( answer2 == "yes" || answer2 == "Yes")
        more = true;

     else
        more = false;

    }while (more);
}

cout << "Patient name: " << patient.getName() << endl
     << "Patient age: " << patient.getWeight() << endl
     << "Patient weight: " << patient.getWeight() << endl<< endl;



patient.displayAllergies (cout);
cout << endl;

patient.displayDailyMeds (cout);

return 0;
}

