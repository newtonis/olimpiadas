#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void solve(int c);

int main() {
    freopen("input.in","r",stdin);

    int C; cin>>C;

    string line; getline(cin,line);

    for (int c = 1;c <= C;c++){
        solve(c);
    }
}
void solve(int c){
    cout<<"Case #"<<c<<endl;

    vector <string> words;

    string line; getline(cin,line);
    istringstream iss(line);
    string word;
    while (iss >> word){
        words.push_back(word);
    }
}