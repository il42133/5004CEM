//code adapted from https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
#include <iostream>
using namespace std;

int main() {
    int nums[5];
    int i, x;

    for (i = 0; i < 5; i++) {
        cout << "Enter value for number " << i+1 << ": ";
        cin >> x;
        while(true) {
            if(cin.fail()) { //Using cin.fail to check for integer input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please input an integer: "; //If input is invalid, programs prompts user to input again
                cin >> x;
            }

            if(!cin.fail()) { //When input is valid, loop breaks
                break;
            }
        }
        nums[i] = x;
    }

    bool arrIsSorted = is_sorted(begin(nums), end(nums)); //Using is_sorted() from standard library to check if input is sorted.
    if(arrIsSorted) {
        cout << "Input is ordered.\n";
    } else {
        cout << "Input is not ordered.\n";
    }

}