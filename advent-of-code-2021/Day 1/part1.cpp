#include <iostream>

using namespace std;

int main()
{
    int count_increased = 0;
    int last_value = 0;
    string line;
    while (getline(cin, line)){
        if (line.size() == 0)
           break;
        int value = stoi(line);
        if (value > last_value){
            count_increased++;
        }
        last_value = value;
    };
    cout << count_increased - 1 << endl;
    return 0;
}