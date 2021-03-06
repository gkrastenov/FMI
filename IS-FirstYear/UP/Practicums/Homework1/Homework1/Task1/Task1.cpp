#include<iostream>
#include<cmath>
using namespace std;

void printWeekdays(int number)
{
    switch (number)
    {
    case 0: cout << "Saturday";
        break;
    case 1: cout << "Sunday";
        break;
    case 2: cout << "Monday";
        break;
    case 3: cout << "Tuesday";
        break;
    case 4: cout << "Wednesday";
        break;
    case 5: cout << "Thursday";
        break;
    case 6: cout << "Friday";
        break;

    default:
        cout << "Not found this day";
        break;
    }
}
void printMonths(int number)
{
    switch (number)
    {
    case 1: cout << "January";
        break;
    case 2: cout << "February";
        break;
    case 3: cout << "March";
        break;
    case 4: cout << "April";
        break;
    case 5: cout << "May";
        break;
    case 6: cout << "June";
        break;
    case 7: cout << "July";
        break;
    case 8: cout << "August";
        break;
    case 9: cout << "September";
        break;
    case 10: cout << "Octomber";
        break;
    case 11: cout << "Novmeber";
        break;
    case 12: cout << "December";
        break;

    default:
        cout << "Not found this month";
        break;
    }
}

void zellersAlgorithm(int day, int month, int year) {
    int mon;
    if (month > 2)
        mon = month;    //for march to december month code is same as month
    else {
        mon = (12 + month);    //for Jan and Feb, month code will be 13 and 14
        year--; //decrease year for month Jan and Feb
    }

    int y = year % 100;    //last two digit
    int c = year / 100;    //first two digit
    int w = (day + floor((13 * (mon + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c));
    w = w % 7;
    printWeekdays(w);
}

/// <summary>
/// Return days in given month
/// </summary>
int daysMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        if (month == 2)
            return 28;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;

        return 31;
    }
    return 0;
}
void calculateNextDay(int day, int month, int year)
{
    int daysM = daysMonth(month);
    if (month == 12 && day == 31)
    {
        month = 1;
        year = year + 1;
    }

    if (day != daysM)
    {
        day = day + 1;
    }

    if (day == daysM)
    {
        day = 1;
    }

    cout << "It was: ";
    zellersAlgorithm(day, month, year);
    cout<< " " << day << " ";
    printMonths(month);
    cout<< " " << year << endl;
}
int main() {
    int day, month, year;
    cin >> day >> month >> year;

    bool isCorrect = true;
    if (day <= 0 || day>31)
    {
        cout << "This day: " << day << " is not correct" << endl;
        isCorrect = false;
    }
    if (year < 1900 || year > 2100 )
    {
        cout << "This year: "<< year <<" is not correct" << endl;
        isCorrect = false;
    }
    if (month <= 0 || month > 12)
    {
        cout << "This month: " << month << " is not correct" << endl;
        isCorrect = false;
    }

    if (isCorrect)
    {
        calculateNextDay(day, month, year);
    }
    else {
        cout << "Your output was incorrect" << endl;
    }
}