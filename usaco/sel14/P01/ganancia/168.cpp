#include<fstream>
#include<queue>
#include<vector>
#define MAX_A 50

using namespace std;



struct Car{
    int priority;
    int D;
    int T;
    int P;
};

int A;
int totalWealth;
int currentTime;
priority_queue<Car> order;
vector<Car> cars;

void readInput(const char*);
void algorithm();
void writeOutput(const char*);
bool operator< (const Car&, const Car&);

int main(){
    readInput("ganancia.in");
    algorithm();
    writeOutput("ganancia.out");

    return 0;
}

void readInput(const char* fileName){
    ifstream file(fileName);
    file>>A;
    for (int i = 0; i<A; i++){
        Car car;
        file>>car.D>>car.T>>car.P;
        car.priority = 0;
        cars.push_back(car);
    }
    file.close();
}

void algorithm(){
    for (int i = 0; i<A; i++){
        for (int j= i; j<A; j++){
            if (cars[i].D*cars[j].T < cars[j].D*cars[i].T)
                cars[i].priority++;
            else if (cars[i].D*cars[j].T > cars[j].D*cars[i].T)
                cars[j].priority++;
        }
        order.push(cars[i]);
    }
    currentTime = 0;
    totalWealth = 0;
    while (!order.empty()){
        Car car = order.top();
        totalWealth += car.P - currentTime*car.T;
        currentTime += car.D;
        order.pop();
    }
}

void writeOutput(const char* fileName){
    ofstream file(fileName);
    file<<totalWealth<<endl;
    file.close();
}


bool operator<(const Car& first, const Car& second){
    return first.priority < second.priority;
}
