#include <iostream>
#include <vector>
#include "organism.hpp"
#include "db.hpp"
#include "ant.hpp"
using namespace std;

void moves(vector<Organism> v1, vector<Organism> v2, int n1, int n2);

int main() {
    int i, k, antCount=100, dbCount=5;
    vector<Organism> antVec;
    vector<Organism> dbVec;
//    initialize vector of ants, ensuring no duplicates:
    ant a;
    a.setCoords(rand()%20+1, rand()%20+1);
    antVec.push_back(a);
    
    bool dup = false;
    while (antVec.size() < antCount){
        Organism curr;
        curr.setCoords(rand()%20+1, rand()%20+1);
        for (k=0; k<antVec.size(); k++){
            if (antVec[k] == curr)
                dup = true;
            else dup = false;
        }
        if (dup == false) antVec.push_back(curr);
    }
//    initialize vector of dbs, ensuring no duplicates:
    db d;
    d.setCoords(rand()%20+1, rand()%20+1);
    dbVec.push_back(a);
    dup = false;
    while (dbVec.size() < dbCount){
        Organism curr;
        curr.setCoords(rand()%20+1, rand()%20+1);
        for (k=0; k<dbVec.size(); k++){
            if (dbVec[k] == curr)
                dup = true;
            else dup = false;
        }
        if (dup == false) dbVec.push_back(curr);
    }
    
//    initial world:
    moves(antVec, dbVec, antCount, dbCount);
    
    Organism** antArray = new Organism*[antCount];
    Organism** dbArray = new Organism*[dbCount];
    for (i=0; i<antCount; i++)
        antArray[i] = &antVec[i];
    for (i=0; i<dbCount; i++)
        dbArray[i] = &dbVec[i];
    
    int movements=0;
    while (antVec.size()>0 && dbVec.size()>0){
        for (i=0; i<antVec.size(); i++){
            antArray[i] -> move(antVec, dbVec);
            movements = antArray[i]->getMoves(); //starts with 0
            antArray[i]->setMoves(++movements);
            if (antArray[i]->getMoves() == 3)
                antArray[i]->breed(antVec, dbVec, antArray[i]->getCoords()[0],antArray[i]->getCoords()[1]);
        }
        
        for (i=0; i<dbVec.size(); i++){
            dbArray[i] -> move(antVec, dbVec);
            movements = dbArray[i]->getMoves();
            dbArray[i]->setMoves(++movements);
            if (dbArray[i]->getCoords()[0]<0) // if starved to death, coordinates set to negative values
                dbVec.erase(dbVec.begin()+i);
            }
            cout<<endl;
            moves(antVec, dbVec, unsigned(antVec.size()), unsigned(dbVec.size()));
    }
    
    delete[] antArray;
    delete[] dbArray;
    return 0;
}

void moves(vector<Organism> v1, vector<Organism> v2, int n1, int n2){
    int i, j, k, m;
    for (i=1; i<21; i++){
        for(j=1; j<21; j++){
            bool occupied = false;
            for(k=0; k<n1;k++){
                if (i==v1[k].getCoords()[0] && j==v1[k].getCoords()[1]){
                    cout<<'o';
                    occupied = true;}
                }
            for(m=0; m<n2; m++){
                if (i==v2[m].getCoords()[0] && j==v2[m].getCoords()[1]){
                    cout<<'X';
                    occupied = true;}
                }
            if (occupied == false) cout<<'-';
        }
        cout<<endl;
    }
}
