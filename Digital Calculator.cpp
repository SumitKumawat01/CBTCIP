#include <iostream>
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;
    char operation;
    bool keepRunning = true;

    while (keepRunning) {
        displayMenu();
        cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q') {
            keepRunning = false;
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) {
            case '+':
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Error: Invalid operation." << endl;
        }

        // Clear any error flags and ignore the rest of the input to prevent infinite loops
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Calculator terminated." << endl;
    return 0;
}

void displayMenu() {
    cout << "Simple Calculator" << endl;
    cout << "=================" << endl;
    cout << "Operations available:" << endl;
    cout << " + : Addition" << endl;
    cout << " - : Subtraction" << endl;
    cout << " * : Multiplication" << endl;
    cout << " / : Division" << endl;
    cout << " q : Quit" << endl;
    cout << "=================" << endl;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
