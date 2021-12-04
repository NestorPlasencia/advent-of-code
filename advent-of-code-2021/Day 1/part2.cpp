#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> values;
    string line;
    while ( getline(cin, line) ) {
        if (line.size() == 0)
           break;
        values.push_back(stoi(line));
    };
    int n = values.size();
    int sum = values[0] + values[1] + values[2];
    int count = 0;
    for( int i = 3; i < n; i++){
        int newsum = values[i-2] + values[i-1] + values[i];
        if( newsum > sum )
            count++;
        sum = newsum;
    }
    cout << count << endl;
    return 0;
}