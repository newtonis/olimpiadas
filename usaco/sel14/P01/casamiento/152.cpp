#include <fstream>
#include <vector>
#define MAX_M 100000
#define MAX_N 100000

using namespace std;


struct EnemyLink{
    int a,b;
};
struct Persona{
    vector<int> enemys;
    int nEnemys;
};

vector<Persona> personas(MAX_N);
vector<EnemyLink> links(MAX_M);
vector<bool> invitados(MAX_N, true);
int N,M,totalInvitados;

void readInput(const char*);
void algorithm();
void writeOutput(const char*);

int main(){
    readInput("casamiento.in");
    algorithm();
    writeOutput("casamiento.out");
    return 0;
}

void readInput(const char* fileName){
    ifstream file(fileName);

    file>>N>>M;

    for(int i = 0; i<M; i++){
        file>>links[i].a>>links[i].b;
        personas[links[i].a].enemys.push_back(links[i].b);
        personas[links[i].b].enemys.push_back(links[i].a);
        personas[links[i].a].nEnemys++;
        personas[links[i].b].nEnemys++;
    }
}

void algorithm(){
    for (int i = 0; i<M; i++){
        if (invitados[links[i].a] && invitados[links[i].b]){
            Persona &a = personas[links[i].a];
            Persona &b = personas[links[i].b];
            if (a.nEnemys >= b.nEnemys){
                invitados[links[i].a] = false;
                for (int j = 0; j<a.nEnemys; j++){
                    personas[a.enemys[j]].nEnemys--;
                    for (int k = 0; k<personas[a.enemys[j]].enemys.size(); k++)
                        if (personas[a.enemys[j]].enemys[k] == links[i].a)
                            personas[a.enemys[j]].enemys.erase(personas[a.enemys[j]].enemys.begin()+k);
                }
            }else if (a.nEnemys < b.nEnemys){
                invitados[links[i].b] = false;
                for (int j = 0; j<b.nEnemys; j++){
                    personas[b.enemys[j]].nEnemys--;
                    for (int k = 0; k<personas[b.enemys[j]].enemys.size(); k++)
                        if (personas[b.enemys[j]].enemys[k] == links[i].b)
                            personas[b.enemys[j]].enemys.erase(personas[b.enemys[j]].enemys.begin()+k);
                }
            }
        }
    }
    totalInvitados = 0;
    for (int i = 0; i<N; i++)
        if (invitados[i])
            totalInvitados++;
}

void writeOutput(const char* fileName){
    ofstream file(fileName);
    file<<totalInvitados<<endl;
    file.close();
}
