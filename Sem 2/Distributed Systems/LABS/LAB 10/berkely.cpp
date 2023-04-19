#include <iostream>
using namespace std;

class Time
{
public:
    int hour;
    int min;

    Time()
    {
        hour = 0;
        min = 0;
    }

    Time(int h, int s)
    {
        hour = h;
        min = s;
    }
};

Time add(int size, Time obj[])
{
    Time tmp;

    for (int i = 0; i < size; i++)
    {
        tmp.hour += obj[i].hour;
        tmp.min += obj[i].min;
    }

    if (tmp.min >= 60)
    {
        tmp.hour += tmp.min / 60;
        tmp.min = tmp.min % 60;
    }

    int minutes = tmp.hour * 60 + tmp.min;
    minutes = minutes / size;

    float finalHr = minutes / 60;
    float finalMin = minutes % 60;

    tmp.hour = finalHr;
    tmp.min = finalMin;

    return tmp;
}

int main()
{
    Time obj[3];

    int size = 3;

    cout << "Enter server time (hour) : ";
    cin >> obj[0].hour;
    cout << "Enter server time (min) : ";
    cin >> obj[0].min;

    for (int i = 1; i < size; i++)
    {
        cout << "Enter time of " << i << "th clock (hour) : ";
        cin >> obj[i].hour;
        cout << "Enter time of " << i << "th clock (min) : ";
        cin >> obj[i].min;
    }

    Time ans = add(size, obj);
    cout << "Time of all clocks after synchronization : ";
    cout << ans.hour << " : " << ans.min << endl;

    return 0;
}