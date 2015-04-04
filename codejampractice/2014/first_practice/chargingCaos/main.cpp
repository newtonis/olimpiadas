#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

typedef unsigned long long ui;
void solve(int t);
ui bsti(string value); //binary string to int

int main() {
    freopen("A-large-practice.in","r",stdin);
    freopen("output.out","w+",stdout);
    int T; cin>>T;
    for (int c = 1;c <= T;c++){
        solve(c);
    }
}
struct chance{
    ui changes; //cambios a hacer

    vector <int> disponibles; //fuentes que estarian disponibles
    chance(ui c,vector <int> a){
        changes = c;
        disponibles   = a;
    }
    void show(){
        bitset<3> x(changes);
        cout<<"chages="<<x<<endl;
        for (int x = 0;x < disponibles.size();x++){
            cout<<disponibles[x]<<" ";
        }
        cout<<endl;
    }
};
void solve(int c){
    cout<<"Case #"<<c<<": ";

    int N,L; cin>>N>>L;
    vector <ui> fuentes; //mascara de bits
    vector <ui> dispositivos; //mascara de bits
    vector <int> afuentes;

    for (int x = 0;x < N;x++){
        string fuente; cin>>fuente;
        fuentes.push_back(bsti(fuente));
        afuentes.push_back(x);
        //cout<<fuentes[x]<<endl;
    }
    //cout<<"-------------"<<endl;
    for (int x = 0;x < N;x++){
        string dispositivo; cin>>dispositivo;
        dispositivos.push_back(bsti(dispositivo));

        //cout<<dispositivos[x]<<endl;
    }



    vector <chance> pc; //posibilidades cambios;

    for (int f = 0;f < fuentes.size();f++){ //por cada fuente

        ui diferencias = dispositivos[0] ^ fuentes[f];
        vector <int> copyfuentes = afuentes;

        copyfuentes.erase(copyfuentes.begin() + f);

        pc.push_back(chance(diferencias,copyfuentes));

    }


    for (int d = 1;d < N;d++) { //por cada dispositivo

        vector <chance> next = vector<chance>(); //vector futuro
        for (int f = 0; f < pc.size(); f++) { //por cada posibilidad de cambio
            ui valor = dispositivos[d] ^ pc[f].changes;

            vector <int> cfuentes = pc[f].disponibles; //por cada fuente disponible

            for (int a = 0; a < cfuentes.size(); a++) {

                if (valor == fuentes[cfuentes[a]]) {

                    vector<int> copyfuentes = cfuentes;
                    copyfuentes.erase(copyfuentes.begin() + a);

                    next.push_back(chance(pc[f].changes, copyfuentes)); //esta posibilidad es valida
                    break;
                }
            }
        }
        pc = next;
        if (pc.size() == 0){
            break;
        }else{

        }
    }

    if (pc.size() == 0){
        cout<<"NOT POSSIBLE"<<endl;
    }else{
        int less = 50;
        for (int x = 0;x < pc.size();x++){
            int amount = 0;
            for (int b = 1;b <= L;b++){ //por cada bit
                ui power = pow(2,b);
                if (pc[x].changes % power > power/2-1){
                    amount ++;
                }
            }
            if (amount < less){
                less = amount;
            }
        }
        cout<<less<<endl;
    }

}
ui bsti(string value){
    ui solution = 0;
    for (int x = 0;x < value.size();x++){
        if (value[x] == '1'){
            solution += pow(2,value.size()-x-1);
        }
    }
    return solution;
}