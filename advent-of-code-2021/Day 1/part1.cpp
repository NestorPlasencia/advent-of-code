#include <iostream>

using namespace std;

int main()
{
    int count_increased = 0;
    int last_value = 0;
    string s_temp;
    while (cin)
    {
        if (cin.eof())
            break;
        getline(cin, s_temp);
        int value = stoi(s_temp);
        if (value > last_value)
        {
            count_increased++;
        }
        last_value = value;
    };
    cout << count_increased - 1 << endl;
    return 0;
}