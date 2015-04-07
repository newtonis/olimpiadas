/*
ID: newtonis
LANG: C++
TASK: friday
*/
#include <iostream>
#include <cstdio>
using namespace std;
//             j f m a m j j a s o n d
int s30[12] = {0,0,0,1,0,1,0,0,1,0,1,0};
int snd[12] = {0,1,0,0,0,0,0,0,0,0,0,0};

int main() {
    freopen("friday.in","r",stdin);
    freopen("friday.out","w+",stdout);
    int N; cin>>N;

    int output[7];
    for (int x = 0;x < 7;x++){
        output[x] = 0;
    }

    int weekday = 0; //0 = monday

    for (int y = 0;y < N;y++){
        int year = 1900 + y;
        bool leap = false;
        if (year % 100 == 0){
            if (year % 400 == 0){
                leap = true;
            }
        }else{
            if (year % 4 == 0){
                leap = true;
            }
        }
        for (int m = 0;m < 12;m++){
            int days;
            if (s30[m]){
                days = 30;
            }else if(snd[m]){
                if (leap){
                    days = 29;
                }else{
                    days = 28;
                }
            }else{
                days = 31;
            }
            for (int d = 1;d <= days;d++) {
                if (d == 13) {
                    output[weekday]++;
                }
                weekday++;
                if (weekday > 6){
                    weekday = 0;
                }
            }
        }
    }

    cout<<output[5]<<" "<<output[6]<<" "<<output[0]<<" "<<output[1]<<" "<<output[2]<<" "<<output[3]<<" "<<output[4]<<endl;

}