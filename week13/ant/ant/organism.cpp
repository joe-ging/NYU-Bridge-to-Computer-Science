#include <iostream>
#include <vector>
#include "organism.hpp"
#include "db.hpp"
#include "ant.hpp"
using namespace std;

Organism:: Organism(){}

void Organism:: move(vector<Organism>& vec1, vector<Organism>& vec2){}

void Organism:: breed(vector<Organism>& vec1, vector<Organism>& vec2, int x, int y){}

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
