#include <iostream>

using namespace std;

//declaring human class
class human {
    private:
        //required variables
        float strength;
        float battle_iq;
        float height;
        float weight;
    public:
        //construct to assign the variables to the class
        human(float s, float b, float h, float w);

        //functions within the class
        float BMI(void) const;
        float fighting_index(void) const;
};

//action of calling class declared here
human::human(float s, float b, float h, float w): strength(s), battle_iq(b), height(h), weight(w) {}

//actions of both functions declared here
float human::BMI(void) const {
    return weight / height / height;
}

float human::fighting_index(void) const {
    return strength * 0.04 + battle_iq * 0.04 + weight/425 - abs(26-weight/height/height)/100;
}

int main() {
    float strength, battle_iq, height, weight;
    //setting accuracy to 3 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
  
    while (true) //this loop runs until all entered values are within the valid ranges {
        try{
            //inputting values
            cout << "Enter strength of individual from scale of 1 to 10";
            cin >> strength;
            cout << "Enter fighting skill of individual from scale of 1 to 10";
            cin >> battle_iq;
            if (battle_iq < 0 or battle_iq > 10 or strength < 0 or strength > 10) {
                throw 15; // calls the catch block
            }
            cout << "Enter weight in kg";
            cin >> weight;
            cout << "Enter height in m";
            cin >> height;
            break;
            }
        catch (int num) {
            //code which runs if range of strength or battle_iq is incorrect
            cout << "Error " << num << ", it seems you inputted a value outside of range" << endl;
        }
    }

    //assigning an object to human class
    human Henry (strength, battle_iq, height, weight);
    //calling the functions
    float bmi = Henry.BMI();
    float index = Henry.fighting_index();
    //outputting the results
    cout << "this indiviual has bmi of " << bmi << endl;
    cout << "and a fighting index between 0 and 1 of " << index;
}
