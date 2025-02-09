#include <iostream>
#include <limits>
using namespace std;

bool isValidNumber(string input) {
    if (input.empty()) {
        return false;
    }

    int startIndex = 0;

    if (input[0] == '-') {
        if (input.length() == 1) {
            return false;
        }
        
        startIndex = 1;
    }

    for (int i = startIndex; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

int arrNumOfElementsInput(string prompt, int min, int max) {
    while (true) {
            string input;
            int value;
            cout << prompt;
            getline (cin, input);

            if (isValidNumber(input)) {
                value = stoi(input);

                if (value < min || value > max) {
                    cout << "\nInvalid number! Please enter a number between " << min << " and " << max << ".\n\n";
                }
                else {
                    return value;
                }
            }
            else {
                cout << "\nInvalid input! Please enter a number between " << min << " and " << max << ".\n\n";
            }
            
        }
    }

    int arrElementsInput(string prompt) {
        while (true) {
            string input;
            int value;
            cout << prompt;
            getline (cin, input);

            if (isValidNumber(input)) {
                value = stoi(input);
                return value;
            }
            else {
                cout << "\nInvalid input! Please enter a number.\n\n";
            }
            
        }
    }

int main() {
    int arrOneElements, arrTwoElements;

    arrOneElements = arrNumOfElementsInput("Enter the number of elements for the first array (1 - 10): ", 1, 10);
    cout << endl;
    arrTwoElements = arrNumOfElementsInput("Enter the number of elements for the second array (1 - 10): ", 1, 10);
    cout << endl;

    int arrOne[arrOneElements], arrTwo[arrTwoElements];

    cout << "Input the elements for the first array.\n";
    for (int i = 0; i < arrOneElements; i++) {
        arrOne[i] = arrElementsInput("Element " + to_string(i + 1) + ": ");
    }

    cout << endl;

    cout << "Input the elements for the second array.\n";
    for (int i = 0; i < arrTwoElements; i++) {
        arrTwo[i] = arrElementsInput("Element " + to_string(i + 1) + ": ");
    }

    cout << endl;

    cout << "First array elements: \n";
    for (int i : arrOne) {
        cout << i << " ";
    }

    cout << endl << endl;

    cout << "Second array elements: \n";
    for (int i : arrTwo) {
        cout << i << " ";
    }

    cout << endl;
    int mergedArrSize = arrOneElements + arrTwoElements;
    int mergedArr[mergedArrSize];

    for (int i = 0; i < arrOneElements; i++) {
        mergedArr[i] = arrOne[i];
    }
    for (int i = 0; i < arrTwoElements; i++) {
        mergedArr[i + arrOneElements] = arrTwo[i];
    }

    cout << endl;

    for (int i = 0; i < mergedArrSize - 1; i++) {
        for (int j = 0; j < mergedArrSize - i - 1; j++) {
            if (mergedArr[j] < mergedArr[j + 1]) {
                int temp = mergedArr[j];
                mergedArr[j] = mergedArr[j + 1];
                mergedArr[j + 1] = temp;

            }
        }
    }

    cout << "Merged Array elements in descending order: \n";
    for (int i : mergedArr) {
        cout << i << " ";
    }

    return 0;
}