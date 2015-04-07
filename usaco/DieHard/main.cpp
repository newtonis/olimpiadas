#include <iostream>

using namespace std;

int a1[2] = {  3,  2}; //aire
int a2[2] = { -5,-10}; //agua
int a3[2] = {-20,  5}; //fuego

int main() {
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    #endif
    int C; cin>>C;
    while (C--){
        int h,a; cin>>h>>a; //health, armor

        int r = 0; //rondas que pasaron
        int last_survival = -1;

        while (1) {
            int ah = -(h - 1) / (a1[0] + a2[0]); //cuantas rondas aguantamos en h
            int aa = -(a - 1) / (a1[1] + a2[1]); //cuantas rondas aguantamos en a

            int survival = min(ah, aa) * 2 + 1; //cuanto tiempo sobrevivo repitiendo agua mas aire

            if (survival < last_survival - 2 and last_survival != -1){ //si la supervivencia de esta ronda es peor que la de la anterior
                r = r + last_survival - 2; //sin aplicar la ronda anterior sumamos la supervivencia anterior
                break;
            }
            last_survival = survival;
            //aplicamos una ronda de aire + fuego
            h += a1[0] + a3[0];
            a += a1[1] + a3[1];
            if (h <= 0 or a <= 0){ //si no podemos aplicar mas aire + fuego
                r = r + survival; //entonces el resultado final es cuanto mas podemos sobrevivir
                break;
            }

            r += 2; //pasaron dos rondas
        }
        cout<<r<<endl;
    }
}