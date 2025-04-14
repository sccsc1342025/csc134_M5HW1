// CSC 134
// M5HW1
// Sebastian Camacho
// 04/14/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Function prototypes
void question1();
void question2();
void question3();
void question4();
void question5();

int main() {
    int choice;
    
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Average Rainfall Calculator\n";
        cout << "2. Hyperrectangle Volume Calculator\n";
        cout << "3. Roman Numeral Converter\n";
        cout << "4. Geometry Calculator\n";
        cout << "5. Distance Traveled Calculator\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        // Input validation
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }
        
        switch(choice) {
            case 1: question1(); break;
            case 2: question2(); break;
            case 3: question3(); break;
            case 4: question4(); break;
            case 5: question5(); break;
            case 6: cout << "Exiting program...\n"; break;
        }
        
    } while (choice != 6);
    
    return 0;
}

// Question 1: Average Rainfall Calculator
void question1() {
    vector<string> months;
    vector<double> rainfalls;
    
    cout << "\nAverage Rainfall Calculator\n";
    for (int i = 0; i < 3; i++) {
        string month;
        double rainfall;
        
        cout << "Enter month: ";
        cin.ignore();
        getline(cin, month);
        
        cout << "Enter rainfall for " << month << ": ";
        cin >> rainfall;
        rainfalls.push_back(rainfall);
        months.push_back(month);
    }
    
    double sum = 0;
    for (double rain : rainfalls) {
        sum += rain;
    }
    double average = sum / 3;
    
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << months[0] << ", " << months[1] 
         << ", and " << months[2] << " is " << average << " inches.\n";
}

// Question 2: Hyperrectangle Volume Calculator
void question2() {
    double width, length, height;
    
    cout << "\nHyperrectangle Volume Calculator\n";
    do {
        cout << "Enter width: ";
        cin >> width;
        if (width <= 0) cout << "Width must be greater than 0.\n";
    } while (width <= 0);
    
    do {
        cout << "Enter length: ";
        cin >> length;
        if (length <= 0) cout << "Length must be greater than 0.\n";
    } while (length <= 0);
    
    do {
        cout << "Enter height: ";
        cin >> height;
        if (height <= 0) cout << "Height must be greater than 0.\n";
    } while (height <= 0);
    
    double volume = width * length * height;
    cout << "The volume of the block is: " << volume << endl;
}

// Question 3: Roman Numeral Converter
void question3() {
    int number;
    
    cout << "\nRoman Numeral Converter\n";
    do {
        cout << "Enter a number (1-10): ";
        cin >> number;
        if (number < 1 || number > 10) {
            cout << "Number must be between 1 and 10.\n";
        }
    } while (number < 1 || number > 10);
    
    string roman;
    switch(number) {
        case 1: roman = "I"; break;
        case 2: roman = "II"; break;
        case 3: roman = "III"; break;
        case 4: roman = "IV"; break;
        case 5: roman = "V"; break;
        case 6: roman = "VI"; break;
        case 7: roman = "VII"; break;
        case 8: roman = "VIII"; break;
        case 9: roman = "IX"; break;
        case 10: roman = "X"; break;
    }
    
    cout << "The Roman numeral version of " << number << " is " << roman << ".\n";
}

// Question 4: Geometry Calculator
void question4() {
    int choice;
    const double PI = 3.14159;
    
    do {
        cout << "\nGeometry Calculator\n";
        cout << "1. Calculate the Area of a Circle\n";
        cout << "2. Calculate the Area of a Rectangle\n";
        cout << "3. Calculate the Area of a Triangle\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (choice < 1 || choice > 4) {
            cout << "The valid choices are 1 through 4.\n";
            continue;
        }
        
        switch(choice) {
            case 1: {
                double radius;
                do {
                    cout << "Enter the circle's radius: ";
                    cin >> radius;
                    if (radius < 0) cout << "The radius cannot be less than zero.\n";
                } while (radius < 0);
                cout << "The area is " << (PI * radius * radius) << endl;
                break;
            }
            case 2: {
                double length, width;
                do {
                    cout << "Enter the rectangle's length: ";
                    cin >> length;
                    if (length < 0) cout << "Only enter positive values for length.\n";
                } while (length < 0);
                do {
                    cout << "Enter the rectangle's width: ";
                    cin >> width;
                    if (width < 0) cout << "Only enter positive values for width.\n";
                } while (width < 0);
                cout << "The area is " << (length * width) << endl;
                break;
            }
            case 3: {
                double base, height;
                do {
                    cout << "Enter the triangle's base: ";
                    cin >> base;
                    if (base < 0) cout << "Only enter positive values for base.\n";
                } while (base < 0);
                do {
                    cout << "Enter the triangle's height: ";
                    cin >> height;
                    if (height < 0) cout << "Only enter positive values for height.\n";
                } while (height < 0);
                cout << "The area is " << (base * height * 0.5) << endl;
                break;
            }
        }
    } while (choice != 4);
}

// Question 5: Distance Traveled Calculator
void question5() {
    double speed, hours;
    
    cout << "\nDistance Traveled Calculator\n";
    do {
        cout << "What is the speed of the vehicle in mph? ";
        cin >> speed;
        if (speed < 0) cout << "Speed cannot be negative.\n";
    } while (speed < 0);
    
    do {
        cout << "How many hours has it traveled? ";
        cin >> hours;
        if (hours < 1) cout << "Time must be at least 1 hour.\n";
    } while (hours < 1);
    
    cout << "Hour  Distance Traveled\n";
    cout << "-------------------------------\n";
    for (int i = 1; i <= hours; i++) {
        cout << setw(3) << i << setw(15) << (speed * i) << endl;
    }
}