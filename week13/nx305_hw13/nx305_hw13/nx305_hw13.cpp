#include <iostream>
#include <vector>
using namespace std;

class Organism {
public:
    Organism();
    virtual void move();
    virtual Organism breed();
    virtual int setStarve(int st);
    virtual int getStarve() const;
    void setCoords(int x, int y);
    vector<int> getCoords() const;
    bool operator ==(const Organism& rhs);
    int getMoves() const;
    void setMoves(int numMove);
protected:
    vector<int> coords;
    int numMoves=0;
};

Organism Organism:: breed(){Organism newOrganism; return newOrganism;}

int Organism:: getStarve() const{int starve=0; return starve;}

int Organism:: setStarve(int st){int starve=0; return starve;}

void Organism:: setMoves(int numMove){
    numMoves = numMove;
}

int Organism:: getMoves() const{
    return numMoves;
}

bool Organism:: operator ==(const Organism& rhs){
    return coords == rhs.getCoords();
}

void Organism:: setCoords(int x, int y){
    coords.push_back(x);
    coords.push_back(y);
}

vector<int> Organism:: getCoords() const{
    return coords;
}

class db: public Organism {
    int dbMoves, starve;
public:
    db();
    virtual void move();
    int setStarve(int st);
    int getStarve() const;
};

int db:: setStarve(int st){
    starve = st;
    return st;
}

int db:: getStarve() const{
    return starve;
}

class ant: public Organism {
    int antMoves;
public:
    ant();
    virtual void move();
    int antCount() const;
    virtual Organism breed();
};

Organism ant:: breed(){
    ant newAnt;
    newAnt.setCoords(rand()%20+1, rand()%20+1);
    return newAnt;
}

Organism:: Organism(){}
ant:: ant(): Organism(), antMoves(0){}
db:: db(): Organism(), dbMoves(0),starve(0){}

void Organism:: move(){}
void ant:: move(){
    int movement;
    movement = rand()%4;
    if (movement == 0 && coords[0]<20){
        coords[0]++;
        numMoves++;}
    else if (movement == 1 && coords[0]>0)
        coords[0]--;
    else if (movement == 2 && coords[1]<20)
        coords[1]++;
    else if (movement == 3 && coords[1]>0)
        coords[1]--;
    else move();
}

void db:: move(){
    int movement;
    movement = rand()%4;
    if (movement == 0 && coords[0]<20){
        coords[0]++;
        numMoves++;}
    else if (movement == 1 && coords[0]>0)
        coords[0]--;
    else if (movement == 2 && coords[1]<20)
        coords[1]++;
    else if (movement == 3 && coords[1]>0)
        coords[1]--;
    else move();
}

void moves(vector<ant> v1, vector<db> v2, int n1, int n2);

int main() {
    int i, k, antCount=100, dbCount=5, antMoves=0, dbMoves=0;
    vector<ant> antVec;
    vector<db> dbVec;

    ant a;
    a.setCoords(rand()%20+1, rand()%20+1);
    antVec.push_back(a);

    bool dup = false;
    while (antVec.size() < antCount){
        ant curr;
        curr.setCoords(rand()%20+1, rand()%20+1);
        for (k=0; k<antVec.size(); k++){
            if (antVec[k] == curr)
                dup = true;
            else dup = false;
            }
        if (dup == false) antVec.push_back(curr);
    }
    
    dup = false;
    while (dbVec.size() < dbCount){
        db curr;
        curr.setCoords(rand()%20+1, rand()%20+1);
        for (k=0; k<dbVec.size(); k++){
            if (dbVec[k] == curr)
                dup = true;
            else dup = false;
        }
        if (dup == false) dbVec.push_back(curr);
    }
    
    for (i=0; i<dbCount; i++){
        db d;
        d.setCoords(rand()%20+1, rand()%20+1);
        dbVec.push_back(d);
    }

    moves(antVec, dbVec, antCount, dbCount);

    Organism** antArray = new Organism*[antCount];
    Organism** dbArray = new Organism*[dbCount];
    for (i=0; i<antCount; i++)
        antArray[i] = &antVec[i];
    for (i=0; i<dbCount; i++)
        dbArray[i] = &dbVec[i];

    int numStarve=0;
while (antCount>0 && dbCount>0){
    for (i=0; i<antCount; i++){
        antArray[i] -> move();
        antMoves++;
        antArray[i]->setMoves(antMoves);
        if (antArray[i]->getMoves() == 3)
            Organism newAnt = antArray[i]->breed();
    }

    for (i=0; i<dbCount; i++){
        dbArray[i] -> move();
        dbMoves++;
        dbArray[i]->setMoves(dbMoves);
        for (k=0; k<antVec.size(); k++){
            if (abs(dbArray[i]->getCoords()[0]+dbArray[i]->getCoords()[1]-antArray[k]->getCoords()[0]-antArray[k]->getCoords()[1])==1){
                antCount--;
                dbArray[i]->setCoords(antArray[k]->getCoords()[0], antArray[k]->getCoords()[1]);
            }
            else {
                numStarve++;
                dbArray[i]->setStarve(numStarve);
        }
    }
    for (k=0; k<antVec.size(); k++){
        if (dbArray[i]->getStarve() == 3){
           dbCount--;
            }
        }
    cout<<endl;
    moves(antVec, dbVec, antCount, dbCount);
    }
}
    return 0;
}

void moves(vector<ant> v1, vector<db> v2, int n1, int n2){
    int i, j, k, m;
    bool occupied = false;
    for (i=1; i<21; i++){
        for(j=1; j<21; j++){
            for(k=0; k<n1;k++){
                if (i==v1[k].getCoords()[0] && j==v1[k].getCoords()[1]){
                    cout<<'o';
                    occupied = true;
                }
                else occupied = false;
            }
            for(m=0; m<n2; m++){
                if (i==v2[m].getCoords()[0] && j==v2[m].getCoords()[1]){
                    cout<<'X';
                    occupied = true;
                }
                else occupied = false;
            }
            if (occupied == false) cout<<'-';
        }
        cout<<endl;
    }
}
