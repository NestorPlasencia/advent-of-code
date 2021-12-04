#include <iostream>

using namespace std;

int pow(int base, int e);

int main()
{
    string input;
    int n = 0;
    int v[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    while(cin) {
        if( cin.eof() ) break;
        getline(cin,input);
        for( int i = 0 ; i < input.length() ; i++) {
            if( input[i] == '1'){
                v[i] += 1;
            }
        }
        n++;
    }
    int gamma = 0;
    int epsilon = 0;
    int vlength = sizeof(v)/sizeof(v[0]);
    for (int i =0 ; i < vlength ; i++){
        if( v[i] > n/2) {
            gamma += pow(2,vlength-i-1);
        }else{
            epsilon += pow(2,vlength-i-1);
        }
    }
    cout <<  gamma*epsilon << endl;
    return 0;
}

int pow(int base, int e) {
    if( e == 0) {
        return 1;
    }else {
        return base * pow(base,e - 1);
    }
}