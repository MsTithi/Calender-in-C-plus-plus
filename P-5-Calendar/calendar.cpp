#include <bits/stdc++.h>
using namespace std;

// Function to get the first day of the year
int getFirstDayOfYear(int year) {
    int day_start;
    int x1, x2, x3;
    
    // Calculate values for the formula
    x1 = (year - 1) / 4;
    x2 = (year - 1) / 100;
    x3 = (year - 1) / 400;

    // Calculate the starting day using Zeller's Congruence
    day_start = (year + x1 - x2 + x3) % 7;
    
    return day_start;
}

int main() {
    // Arrays for months, days, and days in each month
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int year;

    // Get the year from the user
    cout << "Enter a Year: ";
    cin >> year;

    cout << endl;
    cout << "WELCOME TO " << year << " YEAR" << endl;

    // Adjust days in February for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonths[1] = 29;
    }

    // Get the first day of the year
    int weekOfDay = getFirstDayOfYear(year);

    // Print the names of the 12 months
    for (int i = 0; i < 12; i++) {
        cout << endl << endl << "----------------------" << months[i] << "----------------------" << endl << endl;

        // Print the names of the 7 days
        for (int j = 0; j < 7; j++) {
            cout << setw(6) << days[j];
        }

        cout << endl;

        // Print leading spaces based on the first day of the month
        for (int space = 0; space < weekOfDay; space++) {
            cout << setw(6) << " ";
        }

        // Print the days of the month
        for (int k = 1; k <= daysInMonths[i]; k++) {
            cout << setw(6) << k;
            weekOfDay++;

            // Move to the next line after each week
            if (weekOfDay > 6) {
                weekOfDay = 0;
                cout << endl;
            }
        }

        // Move to the next line if the last week is not complete
        if (weekOfDay != 0) {
            cout << endl;
        }
    }

    return(0);
}
