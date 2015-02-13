#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

///solucion selfies.cpp

using namespace std;

//para almacenar las posiciones donde hay lagunas. Como se sabe el WxH<10000 pero no W o H por separado, uso un array y no
//una matriz sabiendo que va a ocupar de cualquier forma que se organize en 10000 lugares. Es decir, cada combinacion
//x,y tiene un valor de identifiacion unico.
//Para acceder a un lugar unico mediante coordenadas x e y se utiliza la formula y*W+x, y asi se logra el valor unico
bool lagunas[10000];

//aqui marco los lugares que ya visite, con una combinacion de atracciones ya visitadas
//como son 10 atracciones como maximo, hay en total 2^10 combinaciones de atracciones que ya visite como maximo, iniciando
//desde 0000000000, hasta 1111111111 cuando ya visite todas
//ejemplo: visite el lugar con x=20,y=10, con w=300 h=400 (entonces la id de posicion seria 6010=300*20+10) cuando habia visitado
//las atracciones 2, 3 y 6 (entonces el valor de la mascara (el segundo valor de la matriz) es 0110010000=400)
bool visitados[10000][1024];

//aqui guardo una mascara que dice cuantas atracciones puedo visitar en tal lugar. El valor maxim
//de esta mascara es 2^10 si pudiera visitar todas las atracciones desde tal punto. (
//es decir 1111111111. como todas las combinaciones x,y son identificadas por un valor unico no es una matriz sino una array
unsigned short atraccionesMap[10000];

char mov[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //Movimientos que puedo hacer (adelante,atras,abajo,arriba)


int N; //atracciones
int H; //alto
int W; //ancho

void read();
void solve();

struct estado{
    unsigned int x;
    unsigned int y;
    unsigned short mask;
    unsigned int dist;
    estado();
    estado(int px,int py,unsigned short pm,unsigned int dd){
        x = px;
        y = py;
        mask = pm;
        dist = dd;
    };
};

void AddAtraction(unsigned int px,unsigned int py,int a){
    if (px >= 0 and px < W and py >= 0 and py < H){
        atraccionesMap[py*W+px] |= a;
    }
}
int main(){
    read();
    solve();
}

void read(){
    freopen("input.in","r",stdin);
    cin>>N; //leo atracciones, alto y ancho
    cin>>H;
    cin>>W;
    for (int y = 0;y < H;y++){
        string data; cin>>data;
        for (int x = 0;x < data.size();x++){
            if (data[x] == 'X'){ //si es pared
                lagunas[x*W+y] = true; //marco que hay una laguna
            }
        }
    }
    for (int a = 1;a <= N;a++){ //por cada atraccion
        int x,y,minv,maxv;
        cin>>y>>x>>minv>>maxv; //leo su posicion y su rango maximo y minimo
        x--; y--;

        //ahora procedo a marcar en el mapa todos los lugares de los cuales puedo sacar una foto de esta atraccion
        for (int dt = minv;dt <= maxv;dt++){ //por cada distancia de la atraccion
            for (int dx = 0;dx <= dt;dx++){ // por cada distanciax de esta distancia
            //la distancia y como la distancia ya esta definida y la distancia x tambien tiene que ser
            // dy = dt - dx ya que dx + dy = dt
                int dy = dt - dx;

                //agrego los 4 puntos como maximo que hay de una distancia dx y dy del punto que hay, si puedo.
                AddAtraction(x+dx,y+dy,a); //esta funcion checkea que no se vaya del rango la x e y
                if (dx != 0){
                    AddAtraction(x-dx,y+dy,a);
                }
                if (dy != 0){
                    AddAtraction(x+dx,y-dy,a);
                }
                if (dx != 0 and dy != 0){
                    AddAtraction(x-dx,y-dy,a);
                }
            }
        }
    }
}

void solve(){
    //Se llevara a cabo una busqueda en anchura (BFS)

    vector <estado> estados;
    //agrego que empiezo en el punto 0,0 sin haber visitado ninguna atraccion y habiendo recorrido 0 lugares
    estados.push_back(estado(0,0,0,0));

    while (not estados.empty()){ //mientras haya estados a analizar
        estado actual = estados[0]; estados.erase(estados.begin());
        if (actual.mask == pow(N,2)-1){ //si el estado actual visito todos los puntos
            cout<<actual.dist<<endl; //es el primero que detecto, es decir, la solucion ya que el primero que detecto es el mas cercano
            return; //para que seguir?
        }
        //marco que visite el punto con tal x, tal y y tal combinacion de lugares visitados (que se guarda en la mascara)
        visitados[actual.y*W+actual.x][actual.mask] = true;
        for (int v = 0;v < 4;v++){ //por cada movimiento posible
            int ny = actual.y + mov[v][0];
            int nx = actual.x + mov[v][1];
            if (ny >= H or nx >= W or ny < 0 or nx < 0){ continue; } //si no se va del rango
            if (lagunas[ny*W+nx]){ continue; } //si no hay una laguna
            if (visitados[ny*W+nx][actual.mask]){ continue; } //si no lo visite ya
            //agrego las atracciones que pueda ver del nuevo punto a la mascara (uso OR, entonces si ya la visite no hay problema)
            actual.mask |= atraccionesMap[ny*W+nx];
            estados.push_back( estado(nx,ny,actual.mask,actual.dist+1)); //agrego la nueva posibilidad de estado
        }
    }
    cout<<-1<<endl;
}
