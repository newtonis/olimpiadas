#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N;
unsigned int mapa[ 1000 ][ 1000 ]; //tamanio maximo 1000x1000, uso un array ya que de esta forma gasto siempre la misma memoria

struct cor{ //para guardar una coordenada
    int y;
    int x;
    cor(int py,int px){
        x = px;
        y = py;
    }
};
void read(); //leer datos
void solve(); //resolver la primera parte
void try_2_push(vector <cor> *cola , cor pos); //intentar agregar a la cola una coordenada, si cumple varias condiciones
void mostrar_map(); //motrar el mapa (para debuggear)
void any_path(); //calculo el camino final
bool try_2_move( cor *point , int sx , int sy , char dir,vector <char> *mov , char *anterior, bool pisado[1001][1001]); //se usa en any path, sirve para haver un nuevo movimiento si es posible, y agregarlo a la lista de movimientos "mov" si corresponde
bool right_point( cor point); //reviso si un punto tipo "esquina", tiene sus 4 cuadrados "anexos" libres

//Por ejemplo si tuviera un mapa asi, donde I son islas y E, esquinas, y N nada, seria algo asi

//ENENENENE
//NININININ
//ENENENENE
//NININININ
//ENENENENE

//las esquinas no aparecen en el enunciado, pero son necesarias cuando se pide trazar una linea, que pase entre los cuadrados. Siempre se va a tener
//en un determinado mapa un numero de esquinas mayor al numero de cuadrados.

//Además, los cuadrados "anexos" de un esquina serian

//ANA
//NEN
//ANA
//Donde E es esquina, A un cuadrado anexo y N nada.

//en un tablero de 7x7 por ejemplo, hay 8x8 esquinas, siempre hay una fila y una columna mas de esquinas.

bool right(cor sq); //revisa si una cuadra anexa a una esquina cumple las condiciones que la esquina requiere

int main(){
    read(); //leo
    solve(); //resulevo la parte de marcar el area libre donde se trazara la linea de division
    any_path(); //busco un camino entre esa linea
}


void read(){ //leo el mapa
    freopen("litigio.in","r",stdin);

    cin>>N;
    for (int y = 0;y < N;y++){
        string line; cin>>line;
        for (int x = 0;x < N;x++){
            if (line[x] == '0'){
                mapa[y][x] = 0; //simboliza agua
            }else{
                mapa[y][x] = 1; //simboliza tierra
            }
        }
    }
}
void solve(){
    int cantidad_islas = 0;
    bool checked[1000][1000]; //array donde marco los lugares que ya tienen una isla asignada

    for (int y = 0;y < N;y++){
        for (int x = 0;x < N;x++){
            if (checked[y][x]){ continue; } //si ya tiene una isla asiganada, ignoro
            if (mapa[y][x] == 1){ //si hay tierra y no tiene isla asignada
                vector <cor> cola; cola.push_back( cor(y,x)); //creo una cola con ese punto
                while (not cola.empty()){ //mientras haya algo que hacer
                    cor actual = cola[0]; cola.pop_back(); //agrego el valor inicial de la cola y lo saco de la cola
                    checked[actual.y][actual.x] = true; //marco que ya le asigne una isla
                    mapa[ actual.y ][ actual.x ] = cantidad_islas + 10; //y le doy valor de isla a ese punto (como 0 y 1 estan ya usados, use 10 + numero de isla)
                    try_2_push(&cola, cor(actual.y+1,actual.x)); //intento agregar a la cola nuevos miembros de la lista, me intento mover  hacia abajo y la derecha
                    try_2_push(&cola, cor(actual.y,actual.x+1));
                }
                cantidad_islas ++; //cuando la cola se vacie, he terminado de marcar una isla mas
            }
        }
    }
    //cout<<cantidad_islas<<endl;
    //mostrar_map();
    for (int x = 0;x < N;x++){ //ahoar procedo a marcar las areas "medias" donde se trazara la linea de limite
    //por cada columna
        int magic_start = 0;  //marco como que la area "media" empieza en 0 por defecto. Si no hubieran islas de la zona "A" se mantendria en ese valor
        int magic_end; //este será el valor hasta donde habra zona "media". La zona media ira de magic start hasta magic end inclusive
        for (int y = 0;y < N;y++){ //por cada item de la columna
            if (mapa[y][x] != 0){ //si no es agua
                if (mapa[ y ][ x ] - 10 >= cantidad_islas / 2){ //si es del lado B, siginifica que llegue al limite de la zona media
                    magic_end = y - 1; //entonces quiere decir que al zona "media" termino en el item anterior
                    break; //¿Para que seguir?
                }else{
                    magic_start = y + 1; //si en cambio es del lado A, significa que el inicio de la zona media es por lo menos 1 item despues de el item actual
                }
                mapa[y][x] = 1; //marco 1, no influye
            }
            if (y == N-1){ //si llegue al final, y no encontre islas del lado B
                magic_end = N-1; //entonces la zona media termina al mismo tiempo que la columna
            }
        }
        for (int y = magic_start;y <= magic_end;y++){ //ahora recorro todos los puntos de la zona "media"
            mapa[ y ][ x ] = 5; //los marco como 5 para reconocerlos
        }
    }
    //mostrar_map();
}
void try_2_push(vector <cor> *cola , cor pos){ //intentar agregar una coordenada a la cola, si se da que es tierra y esta dentro del mapa
    if (pos.x < 0 or pos.y < 0 or pos.x >= N or pos.y >= N){ //si se va del mapa
        return; //termino 
    }else if (mapa[pos.y][pos.x] == 1){ //si es tierra
        cola->push_back( pos ); //la agrego a la cola
    }
}
void mostrar_map(){ //para debuggear, muestro el mapa
    cout<<endl;
    for (int y = 0;y < N;y++){
        for (int x = 0;x < N;x++){
            cout<<mapa[y][x];

        }
        cout<<endl;
    }
}

void any_path(){ //ahora esta funcion con los terrenos "medios" marcados, me calcula algun camino que vaya a travez de las esquinas de los cuadrados desde el SO hasta el NE
    cor actual = cor( N , 0); //inicio en el SO
    vector <char> mov; //lista de los movimientos que hice (puede contener N, S , E , O)
    vector <cor> fui_por;
    int estado = 0;
    char anterior = 'A'; //el ultimo movimiento que hice. A significa que recien empiezo
    bool pisado[ 1001 ][ 1001 ]; //aca almaceno las esquinas por las que ya circule. en un mapa de 1000x1000 cuadrados, hay 1001x1001 esquinas
    for (int x = 0;x < 1001;x++){ 
        for (int y = 0;y < 1001;y++){
            pisado[x][y] = false; //las pongo todas el false defecto
        }
    }
    while ( not (actual.y == 0 and actual.x == N) ){ //mientras que no haya llegado a la esquinas NE
        pisado[actual.y][actual.x] = 1; //marco que ya visite

        //cout<<actual.y<<" "<<actual.x<<endl;
        //for (int x = 0;x < 1000*1000*100;x++);
        //cout<<anterior<<endl;

        switch (anterior){ //esta hecho de tal forma que siempre giro a la derecha del movimiento anterior
            case 'A': //si es el primer movimiento
                if ( try_2_move(&actual,-1,0 ,'O',&mov,&anterior,pisado) ){ break; } //si logro mover al oeste, termino el switch
                if ( try_2_move(&actual,0 ,-1,'N',&mov,&anterior,pisado) ){ break; } //si logro mover al norte, termino el switch
                if ( try_2_move(&actual,1 ,0 ,'E',&mov,&anterior,pisado) ){ break; } 
                if ( try_2_move(&actual,0 , 1,'S',&mov,&anterior,pisado) ){ break; }
            case 'N': //si el movimiento anterior fue norte
                if ( try_2_move(&actual,-1,0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 ,-1,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,1 ,0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 , 1,'S',&mov,&anterior,pisado) ){ break; }
            break; 
            case 'S': //si el movimiento anterior fue sur
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
            break;
            case 'E': //si el movimiento anterior fue este
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
            break;
            case 'O': //si el movimiento anterior fue oeste
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
            break;
        }
    }
    for (int w = 0;w < mov.size();w++){ //muestro la solucion
        cout<<mov[w];
    }
    cout<<endl;
}

bool try_2_move( cor *point , int sx , int sy , char dir,vector <char> *mov , char *anterior, bool pisado[1001][1001]){
    //para intentar mover desde una esquina point en una modificacion x,y de posicion
    
    if (right_point( cor(point->y + sy , point->x + sx)) ){ //si la esquina tiene sus 4 cuadras anexas en condicion de "medio",y ademas esta o en el tablero o en un borde del mismo
        point->x += sx; //muevo en x
        point->y += sy; //muevo en y
        *anterior = dir; //grabo la anterior
        if (pisado[point->y][point->x]){ //si ya lo visite, quiere decir que estoy lledo para atras. elimino reciprocamente el movimiento anterior y no agrego ninguno ahora.
            mov->pop_back();
        }else{
            mov->push_back( dir ); //si no lo visite, lo agrego ral array de movimientos
            //mov->pop_back();
        }
        return true; //me pude mover
    }
    return false; //no me pude mover
}

bool right_point( cor point){ //reviso si una esquina tiene sus 4 cuadras (islas o agua) anexas en condicion de "medio"
    if (not right(cor(point.y,point.x))){ return false; } //si la cuadra NE no es "medio" o no esta en el tablero
    if (not right(cor(point.y,point.x-1))){ return false; }  //etc
    if (not right(cor(point.y-1,point.x))){ return false; }  //etc
    if (not right(cor(point.y-1,point.x-1))){ return false; } //si la cuadra SO no es "medio" o no esta en el tablero
    if (point.y < 0 or point.x < 0 or point.y > N or point.x > N){ return false; } //si la esquina se va del tablero
    //notar que es > a N y no >=, ya que hay una fila y una columna mas de esquinas que de cuadras de tablero
    return true; //si no fallo ninguna de las cuadras anexas a la esquian
}
bool right(cor sq){ //si una cuadra es correcta
    if (sq.x < 0 or sq.y < 0 or sq.x >= N or sq.y >= N){ return true; } //si se va del tablero, como puede haber caminos en el borde del tablero, es valida
    if (mapa[sq.y][sq.x] != 5){ return false; } //si no esta en condicion de "medio" la esquina
    return true; //si salio todo bien
}
