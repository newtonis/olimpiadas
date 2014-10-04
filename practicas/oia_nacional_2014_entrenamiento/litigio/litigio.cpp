#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N;
unsigned int mapa[ 1000 ][ 1000 ];

struct cor{
    int y;
    int x;
    cor(int py,int px){
        x = px;
        y = py;
    }
};
void read();
void solve();
void try_2_push(vector <cor> *cola , cor pos);
void mostrar_map();
void any_path();
bool try_2_move( cor *point , int sx , int sy , char dir,vector <char> *mov , char *anterior, bool pisado[1001][1001]);
bool right_point( cor point);
bool right(cor sq);

int main(){
    read();
    solve();
    any_path();
}


void read(){
    freopen("litigio.in","r",stdin);

    cin>>N;
    for (int y = 0;y < N;y++){
        string line; cin>>line;
        for (int x = 0;x < N;x++){
            if (line[x] == '0'){
                mapa[y][x] = 0;
            }else{
                mapa[y][x] = 1;
            }
        }
    }
}
void solve(){
    int cantidad_islas = 0;
    bool checked[1000][1000];

    for (int y = 0;y < N;y++){
        for (int x = 0;x < N;x++){
            if (checked[y][x]){ continue; }
            if (mapa[y][x] == 1){
                vector <cor> cola; cola.push_back( cor(y,x));
                while (not cola.empty()){
                    cor actual = cola[0]; cola.pop_back();
                    checked[actual.y][actual.x] = true;
                    mapa[ actual.y ][ actual.x ] = cantidad_islas + 10;
                    try_2_push(&cola, cor(actual.y+1,actual.x));
                    try_2_push(&cola, cor(actual.y,actual.x+1));
                }
                cantidad_islas ++;
            }
        }
    }
    //cout<<cantidad_islas<<endl;
    //mostrar_map();
    for (int x = 0;x < N;x++){
        int magic_start = 0;
        int magic_end;
        for (int y = 0;y < N;y++){
            if (mapa[y][x] != 0){
                if (mapa[ y ][ x ] - 10 >= cantidad_islas / 2){
                    magic_end = y - 1;
                    break;
                }else{
                    magic_start = y + 1;
                }
                mapa[y][x] = 1;
            }
            if (y == N-1){
                magic_end = N-1;
            }
        }
        for (int y = magic_start;y <= magic_end;y++){
            mapa[ y ][ x ] = 5;
        }
    }
    //mostrar_map();
}
void try_2_push(vector <cor> *cola , cor pos){
    if (pos.x < 0 or pos.y < 0 or pos.x >= N or pos.y >= N){
        return;
    }else if (mapa[pos.y][pos.x] == 1){
        cola->push_back( pos );
    }
}
void mostrar_map(){
    cout<<endl;
    for (int y = 0;y < N;y++){
        for (int x = 0;x < N;x++){
            cout<<mapa[y][x];

        }
        cout<<endl;
    }
}

void any_path(){
    cor actual = cor( N , 0);
    vector <char> mov;
    vector <cor> fui_por;
    int estado = 0;
    char anterior = 'A';
    bool pisado[ 1001 ][ 1001 ];
    for (int x = 0;x < 1000;x++){
        for (int y = 0;y < 1000;y++){
            pisado[x][y] = false;
        }
    }
    while ( not (actual.y == 0 and actual.x == N) ){
        pisado[actual.y][actual.x] = 1;

        //cout<<actual.y<<" "<<actual.x<<endl;
        //for (int x = 0;x < 1000*1000*100;x++);
        //cout<<anterior<<endl;

        switch (anterior){
            case 'A':
                if ( try_2_move(&actual,-1,0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 ,-1,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,1 ,0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 , 1,'S',&mov,&anterior,pisado) ){ break; }
            case 'N':
                if ( try_2_move(&actual,-1,0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 ,-1,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,1 ,0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,0 , 1,'S',&mov,&anterior,pisado) ){ break; }
            break;
            case 'S':
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
            break;
            case 'E':
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
            break;
            case 'O':
                if ( try_2_move(&actual, 0, 1 ,'S',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual,-1, 0 ,'O',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 0,-1 ,'N',&mov,&anterior,pisado) ){ break; }
                if ( try_2_move(&actual, 1, 0 ,'E',&mov,&anterior,pisado) ){ break; }
            break;
        }
    }
    for (int w = 0;w < mov.size();w++){
        cout<<mov[w];
    }
    cout<<endl;
}

bool try_2_move( cor *point , int sx , int sy , char dir,vector <char> *mov , char *anterior, bool pisado[1001][1001]){
    if (right_point( cor(point->y + sy , point->x + sx)) ){
        point->x += sx;
        point->y += sy;
        *anterior = dir;
        if (pisado[point->y][point->x]){
            mov->pop_back();
        }else{
            mov->push_back( dir );
            //mov->pop_back();
        }
        return true;
    }
    return false;
}

bool right_point( cor point){
    if (not right(cor(point.y,point.x))){ return false; }
    if (not right(cor(point.y,point.x-1))){ return false; }
    if (not right(cor(point.y-1,point.x))){ return false; }
    if (not right(cor(point.y-1,point.x-1))){ return false; }
    if (point.y < 0 or point.x < 0 or point.y > N or point.x > N){ return false; }
    return true;
}
bool right(cor sq){
    if (sq.x < 0 or sq.y < 0 or sq.x >= N or sq.y >= N){ return true; }
    if (mapa[sq.y][sq.x] != 5){ return false; }
    return true;
}
