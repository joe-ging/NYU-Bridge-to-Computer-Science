#include <iostream>
#include <vector>
#include <algorithm>
#include "organism.hpp"
#include "db.hpp"
#include "ant.hpp"
using namespace std;

ant:: ant(): Organism(){}

void ant:: move(vector<Organism>& vec1, vector<Organism>& vec2){
    int movement=rand()%4; // simulate one of four possible outcomes
    
    ant targetAnt;
    if (movement == 0 && coords[0]<20){
        targetAnt.setCoords(coords[0]+1, coords[1]);
        if (find(vec1.begin(), vec1.end(),targetAnt)==vec1.end()&&(find(vec2.begin(),vec2.end(),targetAnt)==vec2.end()))
            coords[0]++;}
    else if (movement == 1 && coords[0]>0){
        targetAnt.setCoords(coords[0]-1, coords[1]);
        if (find(vec1.begin(), vec1.end(),targetAnt)==vec1.end()&&(find(vec2.begin(),vec2.end(),targetAnt)==vec2.end()))
            coords[0]--;}
    else if (movement == 2 && coords[1]<20){
        targetAnt.setCoords(coords[0], coords[1]+1);
        if (find(vec1.begin(), vec1.end(),targetAnt)==vec1.end()&&(find(vec2.begin(),vec2.end(),targetAnt)==vec2.end()))
            coords[1]++;}
    else if (movement == 3 && coords[1]>0){
        targetAnt.setCoords(coords[0], coords[1]-1);
        if (find(vec1.begin(), vec1.end(),targetAnt)==vec1.end()&&(find(vec2.begin(),vec2.end(),targetAnt)==vec2.end()))
            coords[1]--;}
}
        
void ant:: breed(vector<Organism>& vec1, vector<Organism>& vec2, int x, int y){
    int movement=rand()%4; // simulate one of four possible outcomes
    
    ant targetAnt;
    if (movement == 0 && coords[0]<20)
        targetAnt.setCoords(coords[0]+1, coords[1]);
    else if (movement == 1 && coords[0]>0)
        targetAnt.setCoords(coords[0]-1, coords[1]);
    else if (movement == 2 && coords[1]<20)
        targetAnt.setCoords(coords[0], coords[1]+1);
    else if (movement == 3 && coords[1]>0)
        targetAnt.setCoords(coords[0], coords[1]-1);
    
    if (find(vec1.begin(), vec1.end(),targetAnt)==vec1.end()&&(find(vec2.begin(),vec2.end(),targetAnt)==vec2.end()))
        vec1.push_back(targetAnt);
}
