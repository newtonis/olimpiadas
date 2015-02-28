#include <iostream>
#include <ios>
#include <stdio.h>

using namespace std;

typedef unsigned int ui;

char palabra[30000];
ui need_close_right[60001];
ui need_open_left[60001];

void Crear(ui N,ui S,ui E);
void modificar(ui N,ui S,ui E,ui V);

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.in","r",stdin);
    ui casos = 10;
    while (casos--){
        ui longitud; cin>>longitud;
        cin>>palabra;
        Crear(1,0,longitud-1);
        ui mod; cin>>mod;
        while (mod --){
            ui vv; cin>>vv;
            if (vv == 0){
                if (need_close_right[1] == 0 and need_open_left[1] == 0){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                modificar(1,0,longitud-1,vv);
            }
        }
    }
}

void Crear(ui N,ui S,ui E){ //nodo , start , end

    if (S == E){
        if (palabra[S] == '('){
            need_open_left[N] = 0;
            need_close_right[N] = 1;
        }else if(palabra[S] == ')'){
            need_open_left[N] = 1;
            need_close_right[N] = 0;
        }
        return;
    }

    Crear(N*2  , S , (S+E)/2 );
    Crear(N*2+1, (S+E)/2 + 1, E);

    ui necesita_abrir_izquierda_H1 = need_open_left[N*2];
    ui necesita_cerrar_derecha_H1 = need_close_right[N*2];
    ui necesita_abrir_izquierda_H2 = need_open_left[N*2+1];
    ui necesita_cerrar_derecha_H2 = need_close_right[N*2+1];

    ui abre_H1 = necesita_cerrar_derecha_H1;
    ui cierra_H1 = necesita_abrir_izquierda_H1;
    ui abre_H2 = necesita_cerrar_derecha_H2;
    ui cierra_H2 = necesita_abrir_izquierda_H2;


    /// NECESITA_ABRIR_IZQUIERDA_H2 se desincrementa en abre_H1
    if (abre_H1 <= cierra_H2){
        need_open_left[N] = cierra_H2 - abre_H1 + cierra_H1;
        need_close_right[N] = abre_H2;
    }else{
        need_close_right[N] = abre_H1 - cierra_H2 + abre_H2;
        need_open_left[N] = cierra_H1;
    }
}

void modificar(ui N,ui S,ui E,ui V){
    if (S == E){
        if (palabra[S] == '('){
            palabra[S] = ')';
            need_open_left[N] = 1;
            need_close_right[N] = 0;
        }else if(palabra[S] == ')'){
            palabra[S] = '(';
            need_open_left[N] = 0;
            need_close_right[N] = 1;
        }
        return;
    }
    if(V <= (S+E)/2){
        modificar(N*2,S,(S+E)/2,V);
    }else{
        modificar(N*2+1,(S+E)/2+1,E,V);
    }


    ui necesita_abrir_izquierda_H1 = need_open_left[N*2];
    ui necesita_cerrar_derecha_H1 = need_close_right[N*2];
    ui necesita_abrir_izquierda_H2 = need_open_left[N*2+1];
    ui necesita_cerrar_derecha_H2 = need_close_right[N*2+1];

    ui abre_H1 = necesita_cerrar_derecha_H1;
    ui cierra_H1 = necesita_abrir_izquierda_H1;
    ui abre_H2 = necesita_cerrar_derecha_H2;
    ui cierra_H2 = necesita_abrir_izquierda_H2;


    /// NECESITA_ABRIR_IZQUIERDA_H2 se desincrementa en abre_H1
    if (abre_H1 <= cierra_H2){
        need_open_left[N] = cierra_H2 - abre_H1 + cierra_H1;
        need_close_right[N] = abre_H2;
    }else{
        need_close_right[N] = abre_H1 - cierra_H2 + abre_H2;
        need_open_left[N] = cierra_H1;
    }
}
