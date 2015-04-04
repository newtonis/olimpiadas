#include <iostream>
#include <random>

using namespace std;

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w+",stdout);
    int T; cin>>T;

    for (int x = 1;x <= T;x++){
        cout<<"Case #"<<x<<": ";
        int N; cin>>N;
        int score = 0;
        for (int n = 0;n < N;n++){
            int number; cin>>number;
            if (number <= n){
                score ++;
            }
        }
        if (score < (472+500)/2 ){
            cout<<"BAD"<<endl;
        }else{
            cout<<"GOOD"<<endl;
        }
    }
}
