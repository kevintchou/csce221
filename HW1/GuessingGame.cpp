#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

void calculate(int min, int max) {
    vector<int> guess;
    vector<int> range;
    vector<int> mini;
    vector<int> number;
    int Guess;
    int count = 0;
    range.push_back(max);
    mini.push_back(min);
    string answer = "";
    cout << "Please select a number between 1 and " << max << endl;;
    cout << "Enter 'lower' if you number is lower than the number displayed or 'higher' if your number is higher or 'yes' if the number is correct.\n";
    
    while(min!= max)
    {
        ++count;
        int half = (max-min)/2;
        double average = (max-min)/2;
        int averagediff = average-(int)average;
        
        if(averagediff!=0)
            half = (int)average+1;
        else
            half = average;
        Guess = min+half;
        
        cout << count << ". " << Guess << endl;
        cin>>answer;
        try {
            if(answer == "yes") {
                Guess = min;
                max = min;
            }
            else if(answer == "lower") {
                max = Guess;
                guess.push_back(Guess);
                number.push_back(count);
            }
            else if(answer == "higher") {
                min = Guess+1;
                guess.push_back(Guess);
                number.push_back(count);
            }
            else throw invalid_argument("invalid answer");
        }
        catch(exception e) {
            cout << "Invalid answer, enter your answer again\n";
            --count;
        }

    }
    
    ++count;
    int half = (max-min)/2;
    double average = (max-min)/2;
    int averagediff = average-(int)average;
    
    if(averagediff!=0)
        half = (int)average+1;
    else
        half = average;
    Guess = min+half;

    guess.push_back(Guess);
    number.push_back(count);
    cout << "Your number is " << min << endl;
    cout << "Number of operations: " << count << endl;
    cout << "Range     Guess      #Guess" << endl;
    for(int i = 0;i<guess.size(); i++) {
        cout << "[" << mini[0] << "," << range[0] << "]      " << guess[i] << "          " << number[i] << endl;
    }
    
}
                                

int main() {
    int min = 1;
    int max;
    cout << "Enter the maximum range: ";
    cin >> max;
    calculate(min, max);
}



                                
