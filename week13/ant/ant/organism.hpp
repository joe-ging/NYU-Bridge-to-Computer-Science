#ifndef organism_hpp
#define organism_hpp
#include <vector>
using namespace std;

class Organism {
public:
    Organism();
    virtual void move(vector<Organism>& vec1, vector<Organism>& vec2);
    virtual void breed(vector<Organism>& vec1, vector<Organism>& vec2, int x, int y);
    void setCoords(int x, int y);
    vector<int> getCoords() const;
    bool operator ==(const Organism& rhs);
    void setMoves(int num) {moves = num;}
    int getMoves() const {return moves;}
protected:
    vector<int> coords;
    int moves=0;
};

#endif /* organism_hpp */
