#include <iostream>
#include <vector>

using namespace std;

int own_pow(int base, int e);
string find_value(vector<string> arr, string value, int pos);
int bin2dec(string bin);

int main()
{
    string line;
    vector<string> values;
    while (getline(cin, line)){
        if (line.size() == 0)
            break;
        values.push_back(line);
    }
    int oxygen = bin2dec(find_value(values, "oxygen", 0));
    int co2 = bin2dec(find_value(values, "co2", 0));
    cout << oxygen * co2 << endl;
    return 0;
}

string find_value(vector<string> arr, string value, int pos){
    int n = arr.size();
    if (n == 1 || pos == arr[0].length()){
        return arr[0];
    }
    vector<string> ones;
    vector<string> zeros;
    for (int i = 0; i < n; i++){
        if (arr[i][pos] == '1'){
            ones.push_back(arr[i]);
        }
        else{
            zeros.push_back(arr[i]);
        }
    }
    if (ones.size() >= zeros.size()){
        if (value == "oxygen")
            return find_value(ones, value, pos + 1);
        return find_value(zeros, value, pos + 1);
    }
    else{
        if (value == "oxygen")
            return find_value(zeros, value, pos + 1);
        return find_value(ones, value, pos + 1);
    }
}

int bin2dec(string bin){
    int n = bin.length();
    int dec = 0;
    for (int i = 0; i < bin.length(); i++){
        if (bin[i] == '1'){
            dec += own_pow(2, n - i - 1);
        }
    }
    return dec;
}

int own_pow(int base, int e){
    if (e == 0){
        return 1;
    }
    else{
        return base * own_pow(base, e - 1);
    }
}