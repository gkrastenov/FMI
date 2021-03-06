#include <iostream>

using namespace std;
class Time {
private:
    unsigned hours;
    unsigned minutes;

    bool validaiton_minutes(const int minutes) {
        if (minutes >= 0 || minutes <= 60)
            return true;

        return false;

    }

    bool validation_hours(const int hours) {
        if (hours >= 0 || hours <= 24)
            return true;

        return false;
    }

    void increaseHours(const unsigned hours) {
        int currentHours = this->hours + hours;
        if (currentHours >= 0 || currentHours < 24) {
            this->hours = currentHours;
        }

        if (currentHours >= 24)
        {
            this->hours = currentHours - 24;
        }  
    }

    void increaseMinutes(const unsigned minutes) {
        int currentMinutes = this->minutes + minutes;
        if (currentMinutes >= 0 || currentMinutes < 60) {
            this->minutes = currentMinutes;
        }

        if (currentMinutes >= 60)
        {
            this->minutes = currentMinutes - 60;
        }
    }

    void decreaseHours(const unsigned hours) {
         int currentHours = this->hours + hours;
         if (currentHours >= 0 || currentHours < 24) {
             this->hours = currentHours;
         }

         cout << "Hours will be negative number" << endl;
    }

    void decreaseMinutes(const unsigned minutes) {
        int currentMinutes = this->minutes + minutes;
        if (currentMinutes >= 0 || currentMinutes < 60) {
            this->minutes = currentMinutes;
        }

        cout << "Minutes will be negative number" << endl;
    }


    bool checkIsNumberPositive(const int number) {
        return number > 0;
    }
public:

    void setHours(const int hours) {
        if (validation_hours(hours))
        {
            this->hours = hours;

        }
        cout << "Invalid hours" << endl;
    }

    int gethours() {
        return this->hours;
    }

    void setMinutes(const int minutes) {
        if (validaiton_minutes(minutes))
        {
            this->minutes = minutes;

        }
        cout << "Invalid minutes" << endl;
        this->minutes = minutes;
    }

    int getMinutes() {
        return this->minutes;
    }

    void operator<(const Time& time)
    {
        if (this->hours < time.hours || this->minutes < time.minutes)
            cout << "Time 2 is closer than Time 1" << endl;

        if (this->hours == time.hours && this->minutes == time.minutes)
        {
            cout << "Time 1 and Time 2 are qeual" << endl;
        }

        if (this->hours > time.hours || this->minutes > time.minutes)
            cout << "Time 1 is closer than Time 2" << endl;
    }

    void operator+(const Time& time)
    {
        if (checkIsNumberPositive(time.hours) && checkIsNumberPositive(time.minutes))
        {
            this->addHours(time.hours);
            this->addMinutes(time.minutes);
        }
        else {
            cout << "Invalid time" << endl;
        }
    }

    void operator-(const Time& time)
    {
        if (checkIsNumberPositive(time.hours) && checkIsNumberPositive(time.minutes))
        {
            this->decreaseHours(time.hours);
            this->decreaseMinutes(time.minutes);
        }
        else {
            cout << "Invalid time" << endl;
        }
    }

    void operator*(const int number)
    {
        if (checkIsNumberPositive(number))
        {
            this->setHours(this->hours * number);
            cout << "Now hours are: " << this->hours;
            this->setMinutes(this->minutes * number);
            cout << "Now minutes are: " << this->minutes;
        }
        cout << "Invalid time" << endl;
    }

    void addMinutes(const unsigned minutes)
    {
        increaseMinutes(minutes);
        cout << "Now minutes are: " << this->minutes;
    }

    void addHours(const unsigned hours)
    {
        increaseHours(hours);
        cout << "Now hours are: " << this->hours;

    }

    int minutesFromStartOfNight()
    {
        return this->hours * 60 + this->minutes;
    }
};

int main()
{
    cout << "Hello World!\n";
}

