#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INFINITO -1
#define UNDEFINED -2

using namespace std;

struct calle;
struct esquina;

struct esquina{
    int numero;
    int distancia_A;
    int distancia_B;
    int changed_B;
    vector <calle*> uniones_comunes;
    vector <calle*> uniones_inversas;

    esquina(int n){
        numero = n;
        distancia_A = INFINITO;
        distancia_B = INFINITO;
        changed_B   = UNDEFINED;
    }
};
struct calle{
    esquina* inicio;
    esquina* fin;
    int distancia;
    int numero;
    calle(esquina* i, esquina* f,int d,int n){
        distancia = d;
        numero = n;
        inicio = i;
        fin = f;
    }
};
struct compare{
    bool operator()(esquina* A,esquina* B){
        return A->distancia_A > B->distancia_A;
    }
};
struct compare2{
    bool operator()(esquina* A,esquina* B){
        return A->distancia_B > B->distancia_B;
    }
};

struct Arbol{
    vector <esquina*> esquinas;
    vector <calle*> calles;
    int inicio;
    int fin;
    Arbol(int E){
        for (int x = 0;x < E;x++){
            esquinas.push_back( new esquina(x) );
        }
    }
    void add_calle(int esquina_a,int esquina_b,int distancia){
        esquina_a--;
        esquina_b--;

        calle* nueva = new calle(esquinas[esquina_a],esquinas[esquina_b],distancia,calles.size()+1);
        esquinas[esquina_a]->uniones_comunes.push_back(nueva);
        esquinas[esquina_b]->uniones_inversas.push_back(nueva);
        calles.push_back(nueva);

    }
    void set_inicio(int i){
        i--;
        inicio = i;
    }
    void set_fin(int f){
        f--;
        fin = f;
    }
    void djikstra(){
        priority_queue <esquina* , vector <esquina*> , compare  > cola_a;
        priority_queue <esquina* , vector <esquina*> , compare2 > cola_b;
        cola_a.push(esquinas[inicio]);
        esquinas[inicio]->distancia_A = 0;
        bool done = false;

        while (not cola_a.empty()){
            //comunes

            esquina* actual = cola_a.top(); cola_a.pop();

            for (int x = 0;x < actual->uniones_comunes.size();x++){
                if (actual->uniones_comunes[x]->fin->distancia_A == INFINITO or actual->uniones_comunes[x]->fin->distancia_A > actual->distancia_A + actual->uniones_comunes[x]->distancia ){
                    actual->uniones_comunes[x]->fin->distancia_A = actual->distancia_A + actual->uniones_comunes[x]->distancia;
                    cola_a.push(actual->uniones_comunes[x]->fin);
                }
            }

            for (int x = 0;x < actual->uniones_inversas.size();x++){
                if (actual->uniones_inversas[x]->inicio->distancia_B == INFINITO or actual->uniones_inversas[x]->inicio->distancia_B > actual->distancia_B + actual->uniones_inversas[x]->distancia ){
                    actual->uniones_inversas[x]->inicio->distancia_B = actual->distancia_A + actual->uniones_inversas[x]->distancia;
                    actual->uniones_inversas[x]->inicio->changed_B = actual->uniones_inversas[x]->numero;
                    cola_b.push(actual->uniones_inversas[x]->inicio);
                    while (not cola_b.empty() ){
                        esquina* mia = cola_b.top(); cola_b.pop();
                        for (int y = 0;y < mia->uniones_comunes.size();y++){
                            if (mia->uniones_comunes[y]->fin->distancia_B == INFINITO or mia->uniones_comunes[y]->fin->distancia_B > mia->uniones_comunes[y]->distancia + mia->distancia_B){
                                mia->uniones_comunes[y]->fin->distancia_B = mia->distancia_B + mia->uniones_comunes[y]->distancia;
                                mia->uniones_comunes[y]->fin->changed_B = mia->changed_B;
                                cola_b.push(mia->uniones_comunes[y]->fin);
                            }
                        }
                    }

                }
            }
        }
        cout<<esquinas[fin]->distancia_A<<endl;
        cout<<esquinas[fin]->distancia_B<<endl;
        cout<<esquinas[fin]->changed_B<<endl;
    }
};

int main(){
    freopen("invertir.in","r",stdin);
    int E; cin>>E;
    int I; cin>>I;
    int F; cin>>F;
    int C; cin>>C;

    Arbol arbol = Arbol(E);
    arbol.set_inicio(I);
    arbol.set_fin(F);
    for (int x = 0;x < C;x++){
        int i; cin>>i;
        int f; cin>>f;
        int d; cin>>d;
        arbol.add_calle( i , f , d);
    }
    arbol.djikstra();
}
