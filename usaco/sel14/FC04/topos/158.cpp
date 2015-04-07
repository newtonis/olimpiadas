#include <iostream>
#include <fstream>
#define INF 6000000
using namespace std;
char var[INF];
int num = 0;
int cont = 0;
int main(){
	
	ifstream fin("topos.in");
	ofstream fout("topos.out");
	
	
	while(num<1000){
		fin>>var[cont];
		cont++;
		num++;
	}
	fout<<"Z:(("<<var[0]<<"("<<var[4]<<var[5]<<"))("<<var[9]<<var[10]<<"))"<<endl;


	return 0;
}
