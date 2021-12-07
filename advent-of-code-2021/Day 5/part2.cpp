#include <iostream>
#include <vector>


using namespace std;

vector<string> split(string s, string delimiter);
string string_slice(string s, int begin, int end );
vector<int> filter_line(int x1,int x2,int y1,int y2);
int main()
{
    string line;
    vector<vector<int>> lines;
    vector<vector<int>> intersections;
    while(cin) {
        if (cin.eof())
            break;
        getline(cin,line);
        vector<string> p = split(line,"->");
        vector<string> p0 = split(p[0],",");
        vector<string> p1 = split(p[1],",");
        int x1 = stoi(p0[0]);
        int y1 = stoi(p0[1]);
        int x2 = stoi(p1[0]);
        int y2 = stoi(p1[1]);
        vector<int> gen_line = filter_line(x1,x2,y1,y2);
        if( gen_line.size() > 1 ){
            lines.push_back(gen_line);
        }
    }

    int maxX = 0;
    int maxY = 0;
    for(int i = 0 ; i < lines.size() ; i++){
        if(lines[i][0] > maxX){
            maxX = lines[i][0];
        }
        if(lines[i][1] > maxX){
            maxX = lines[i][1];
        }
        if(lines[i][2] > maxY){
            maxY = lines[i][2];
        }
        if(lines[i][3] > maxY){
            maxY = lines[i][3];
        }
    }

    int figure[maxX + 1][maxY + 1];

    for (int i = 0; i < maxY + 1; i++) {
        for (int j = 0; j < maxX + 1; j++) {
            figure[i][j] = 0;
        }
    }

    for(int i = 0 ; i < lines.size() ; i++){
        int x1 = lines[i][0];
        int x2 = lines[i][1];
        int y1 = lines[i][2];
        int y2 = lines[i][3];
        if (x1 == x2) {
            for (int j = y1; j <= y2; j++) {
                figure[j][x1] = figure[j][x1] + 1;
            }
           
        } else if( y1 == y2 ) {
            for (int j = x1; j <= x2; j++) {
                figure[y1][j] = figure[y1][j] + 1;
            }
        } else {
            int m = (y2 - y1) / (x2 - x1);
            int b = y2 - m * x2;
            for (int i = x1; i <= x2; i++) {
                int y = i * m + b;
                figure[y][i] = figure[y][i] + 1;
            }
        }
    }

    for (int i = 0; i < maxY + 1; i++) {
        for (int j = 0; j < maxX + 1; j++) {
            if (figure[i][j] < 1) {
                cout<<'.';
            }else{
                cout<<figure[i][j];
            }
        }
        cout<<endl;
    }

    int count = 0;
    for (int i = 0; i < maxY + 1; i++) {
        for (int j = 0; j < maxX + 1; j++) {
            if (figure[i][j] > 1) {
                count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}


vector<int> filter_line(int x1,int x2,int y1,int y2) {
    vector<int> line;
    if( x1 == x2) {
        line.push_back(x1);
        line.push_back(x2);
        if( y1 <= y2 ){
            line.push_back(y1);
            line.push_back(y2);
        }else{
            line.push_back(y2);
            line.push_back(y1);
        } 
    }else if( y1 == y2) {
        if( x1 <= x2 ){
            line.push_back(x1);
            line.push_back(x2);
        }else{
            line.push_back(x2);
            line.push_back(x1);
        }
        line.push_back(y1);
        line.push_back(y2);
    }else{
        int side1 = x1 - x2;
        int side2 = y1 - y2;
        if (side1 == side2 || -1 * side1 == side2){
            if (x1 <= x2){
                line.push_back(x1);
                line.push_back(x2);
                line.push_back(y1);
                line.push_back(y2);
            }else{
                line.push_back(x2);
                line.push_back(x1);
                line.push_back(y2);
                line.push_back(y1);
            }
        }  
    }
    return line;
}

vector<string> split(string s, string delimiter){
    int n = delimiter.length();
    vector<string> vals;
    string acum;
    for(int i = 0;i < s.length(); i++){
        string sec = string_slice(s,i,i+n);
        if( sec == delimiter){
            vals.push_back(acum);
            acum = "";
            i = i + ( n - 1);
        }else{
            acum += s[i];
        }
    }
    vals.push_back(acum);
    return vals;
}

string string_slice(string s, int begin, int end ){
    string slice_s;
    for( int i = begin; i < end; i++){
        slice_s += s[i];
    }
    return slice_s;
}