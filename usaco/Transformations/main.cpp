/*
ID: newtonis
LANG: C++
TASK: transform
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector <vector <char> > matrix;
typedef vector <char> line;

bool equal(matrix a,matrix b,int N);
matrix new_matrix(int N);
matrix rotate90(matrix a,int N);
matrix reflect(matrix a,int N);
void show(matrix a,int N);

int main() {
    freopen("transform.in","r",stdin);
    freopen("transform.out","w+",stdout);
    int N; cin>>N;

    matrix a;
    matrix b;

    for (int r = 0;r < N;r++){
        string row; cin>>row;
        line l;
        for (int c = 0;c < N;c++){
            l.push_back(row[c]);
        }
        a.push_back(l);
    }

    for (int r = 0;r < N;r++){
        string row; cin>>row;
        line l;
        for (int c = 0;c < N;c++){
            l.push_back(row[c]);
        }
        b.push_back(l);
    }

    matrix rotated90 = rotate90(a,N);
    if (equal(rotated90,b,N)){
        cout<<1<<endl;
        return 0;
    }
    matrix rotated180 = rotate90(rotated90,N);
    if (equal(rotated180,b,N)){
        cout<<2<<endl;
        return 0;
    }
    matrix rotate270 = rotate90(rotated180,N);
    if (equal(rotate270,b,N)){
        cout<<3<<endl;
        return 0;
    }
    matrix reflected = reflect(a,N);
    if (equal(reflected,b,N)){
        cout<<4<<endl;
        return 0;
    }
    matrix r90 = rotate90(reflected,N);
    matrix r180= rotate90(r90 ,N);
    matrix r270= rotate90(r180,N);
    if (equal(r90,b,N) or equal(r180,b,N) or equal(r270,b,N)){
        cout<<5<<endl;
        return 0;
    }
    if (equal(a,b,N)){
        cout<<6<<endl;
        return 0;
    }
    cout<<7<<endl;
    return 0;
}

bool equal(matrix a,matrix b,int N){
    for (int r = 0;r < N;r++){
        for (int c = 0;c < N;c++){
            if (a[r][c] != b[r][c]){
                return false;
            }
        }
    }
    return true;
}
matrix new_matrix(int N){
    matrix a;
    for (int r = 0;r < N;r++){
        line l;
        for (int c = 0;c < N;c++){
            l.push_back('-');
        }
        a.push_back(l);
    }
    return a;
}
matrix rotate90(matrix a,int N){
    matrix b = new_matrix(N);
    //la fila de la rotada es la columna de la comun
    //la columna de la rotada es la fila de la comun invertida

    for (int r = 0;r < N;r++){
        for (int c = 0;c < N;c++){
            b[c][N-r-1] = a[r][c];
        }
    }
    return b;
}
matrix reflect(matrix a,int N){
    matrix b = new_matrix(N);
    for (int r = 0;r < N;r++){
        for (int c = 0;c < N;c++){
            b[r][N-c-1] = a[r][c];
        }
    }
    return b;
}
void show(matrix a,int N){
    for (int r = 0;r < N;r++){
        for (int c = 0;c < N;c++){
            cout<<a[r][c];
        }
        cout<<endl;
    }
}