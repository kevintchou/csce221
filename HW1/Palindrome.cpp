#include <iostream>
#include <string>

using namespace std;

void palindrome(string input) {
    if (input == string(input.rbegin(), input.rend())) {
        cout << input << " is a palindrome";
    }
    else
        cout << input << " is not a palindrome";
}

int main() {
    string input = "";      // test 1: empty string
    palindrome(input);
    cout << endl;
    
    input = "tacocat";      // test 2: palindrome
    palindrome(input);
    cout << endl;
    
    input = "racecar";      // test 3: palindrome
    palindrome(input);
    cout << endl;
    
    input = "gohangasalamiimalasagnahog";   // test 4: palindrome
    palindrome(input);
    cout << endl;
    
    input = "kayak";        // test 5: palindrome
    palindrome (input);
    cout << endl;
    
    input = "palindrome";   // test 6: not a palindrome
    palindrome(input);
    cout << endl;
    
    input = "string";       // test 7: not a palindrome
    palindrome(input);
    cout << endl;
}