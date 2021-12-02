#include <iostream>

using namespace std;

int main()
{
    string s_temp;
    int horizontal = 0;
    int depth = 0; 
    while(cin) {
        if( cin.eof() ) break;
        getline(cin,s_temp);
        string dir_str;
        string value_str;
        int count = 0;
        int p = 0;
        for(int i = 0; i < s_temp.length(); i++) {
            char l = s_temp[i];
            if(l == ' '){
                count++;
            }else{
                if(count == 0){
                    dir_str += l;
                }
                if(count == 1){
                    value_str += l;
                }
            }
        }
        if( dir_str == "forward") {
            horizontal += stoi(value_str);
        }
        if( dir_str == "down") {
            depth += stoi(value_str);
        }
        if( dir_str == "up") {
            depth -= stoi(value_str);
        }
    };
    cout<<horizontal*depth<<endl;
    return 0;
}