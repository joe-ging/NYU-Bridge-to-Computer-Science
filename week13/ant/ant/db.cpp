#include <iostream>
#include <vector>
#include "organism.hpp"
#include "db.hpp"
#include "ant.hpp"
using namespace std;

db:: db(): Organism(){}

void db:: breed(vector<Organism>& v1, vector<Organism>& v2, int x, int y){
    db newDb;
    newDb.setCoords(x,y);
    v2.push_back(newDb);
}

void db:: move(vector<Organism>& vec1, vector<Organism>& vec2){
    int movement, newMove, x, y, newX=0, newY=0, numStarves=0, numMoves=0;
    bool breedPossible=false;
    
//    if there's an ant in an adjacent cell, move there and eliminate ant
    
    for (int i=0; i<vec1.size(); i++){
        if (coords[0]+1 == vec1[i].getCoords()[0] || coords[1] == vec1[i].getCoords()[1]){
            coords[0]++; // if there's an ant in the cell to the right
            numMoves++;
            vec1.erase(vec1.begin()+i);
        }
        else if (coords[0]-1 == vec1[i].getCoords()[0] || coords[1] == vec1[i].getCoords()[1]){
            coords[0]--; // if there's an ant in the cell to the left
            numMoves++;
            vec1.erase(vec1.begin()+i);
        }
        else if (coords[0] == vec1[i].getCoords()[0] || coords[1]+1 == vec1[i].getCoords()[1]){
            coords[1]++; // if there's an ant in the cell above
            numMoves++;
            vec1.erase(vec1.begin()+i);
        }
        else if (coords[0] == vec1[i].getCoords()[0] || coords[1]-1 == vec1[i].getCoords()[1]){
            coords[1]--; // if there's an ant in the cell below
            numMoves++;
            vec1.erase(vec1.begin()+i);
        }
        else numStarves++;
    }
    
//    If there's no ant around, check if another db already occupies the cell above. Only move if false
    movement = rand()%4; // simulate one of four possible outcomes
    if (movement == 0 && coords[0]<20){
        for (int i=0; i<vec2.size(); i++){
            if (coords[0]+1!=vec2[i].getCoords()[0] || coords[1]!=vec2[i].getCoords()[1]){
                coords[0]++;
                numMoves++;}
        }
    }
    else if (movement == 1 && coords[0]>0){
        for (int i=0; i<vec2.size(); i++){
            if (coords[0]-1!=vec2[i].getCoords()[0] || coords[1]!=vec2[i].getCoords()[1]){
                coords[0]--;
                numMoves++;}
        }
    }
    else if (movement == 2 && coords[1]<20){ // up move (y axis ++)
        for (int i=0; i<vec2.size(); i++){
            if (coords[0]!=vec2[i].getCoords()[0] || coords[1]+1!=vec2[i].getCoords()[1]){
                coords[1]++;
                numMoves++;}
        }
    }
    else if (movement == 3 && coords[1]>0){ // down move (y axis --)
        for (int i=0; i<vec2.size(); i++){
            if (coords[0]!=vec2[i].getCoords()[0] || coords[1]-1!=vec2[i].getCoords()[1]){
                coords[1]--;
                numMoves++;}
        }
    }
    
    //  Below only used if breed()
    if (numMoves == 8){
        x = getCoords()[0];
        y = getCoords()[1];
        newMove = rand()%4; // simulate one of four possible outcomes for new db;
        if (newMove == 0 && coords[0]<20){ //place new db to parent's right (x axis ++)
            //    check if a db already occupies the cell above. Only move if false
            for (int i=0; i<vec2.size(); i++){
                if (coords[0]+1!=vec2[i].getCoords()[0] || coords[1]!=vec2[i].getCoords()[1])
                    newX = x+1;
                    breedPossible = true;
            }
            }
        else if (newMove == 1 && coords[0]>0){
            for (int i=0; i<vec2.size(); i++){
                if (coords[0]-1!=vec2[i].getCoords()[0] || coords[1]!=vec2[i].getCoords()[1])
                    newX = x-1;
                    breedPossible = true;
            }
            }
        else if (newMove == 2 && coords[1]<20){ // place new db above parent (y axis ++)
          for (int i=0; i<vec2.size(); i++){
                if (coords[0]!=vec2[i].getCoords()[0] || coords[1]+1!=vec2[i].getCoords()[1])
                    newY = y+1;
                    breedPossible = true;
          }
        }
        else if (newMove == 3 && coords[1]>0){ // place db below parent (y axis --)
            for (int i=0; i<vec2.size(); i++){
                if (coords[0]!=vec1[i].getCoords()[0] || coords[1]-1!=vec1[i].getCoords()[1])
                    newY = y-1;
                    breedPossible = true;
            }
        }
        else breedPossible = false;
    }
    
    if (breedPossible == true)
        breed(vec1, vec2, newX, newY);
    if (numMoves == 3 && numStarves == 3)
        setCoords(-1, -1);
}
