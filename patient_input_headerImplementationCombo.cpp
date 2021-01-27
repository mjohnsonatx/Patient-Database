// begin at line 110 and make a new patient demographic input, convert meds and allergies to switch statement
#include <iomanip>
#include <iostream>

using namespace std;

int num_allergies = 0,
    num_meds = 0;

struct Allergies {
        Allergies(): substance (" "), reaction (" ") {}
        Allergies (string substance, string reaction);
        string substance;
        string reaction;
        };

struct DailyMeds {
        DailyMeds (): med (" "), dose (" "){}
        DailyMeds ( string med, string dose);
        string med;
        string dose;
        };

class Patient {


private:
    static const int MAX_SIZE = 100;
    string name;
    int age;
    double weight_lbs;


public:

Allergies allergy_list[MAX_SIZE];
DailyMeds dailyMeds[MAX_SIZE];

Patient () {
    name = "Jane Doe";
    age = 0;
    weight_lbs = 220.0;
}

Patient (string n, int a, double w){
        n = name;
        a = age;
        w = weight_lbs;
}

void setWeight (double w) {
        weight_lbs = w;
}

void setName (string n){
        name = n;
}

void setAge (int a) {
        age = a;
}

void setAllergies (Allergies allergies) {

        allergy_list[num_allergies] = allergies;
        num_allergies++;
}

void setDailyMeds(DailyMeds dailymeds) {

        dailyMeds[num_meds] = dailymeds;
        num_meds++;
        }
void displayAllergies(ostream& out){

    if (num_allergies == 0 )
        out << "The patient has NKDA." << endl;

    else if (num_allergies == 1)
        out << "The patient has one allergy: " << allergy_list[0].substance
            << " which causes " << allergy_list[0].reaction << endl;
    else {
        out << "The patient has " << num_allergies << " allergies." << endl;
        out << "Allergy:" << setw(10) << "Reaction:" << endl;
            for (int i = 0; i < num_allergies; i++)
                {
                    out << allergy_list[i].substance << setw (10)
                        << allergy_list[i].reaction << endl;
                }
        }
}

void displayDailyMeds(ostream& out){

    if (num_meds == 0)
        out << "No meds reported." << endl;
    else {
        out<<"Daily Medication: " << setw(10) << "Dose: " << endl;
        for(int i = 0; i < num_meds; i++)
        out << dailyMeds[i].med << setw(10) << dailyMeds[i].dose << endl;
         }
}

void displayPatientDemo (ostream& out) {}

double getWeight () const {return weight_lbs;}

string getName () const {return name;}

int getAge () const {return age;}

};

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

