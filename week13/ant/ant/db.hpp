#ifndef db_hpp
#define db_hpp
#include <vector>
#include "organism.hpp"
#include "ant.hpp"
using namespace std;

class db: public Organism {
public:
    db();
    virtual void move(vector<Organism>& vec1, vector<Organism>& vec2);
    virtual void breed(vector<Organism>& v1, vector<Organism>& v2, int x, int y);
};

#endif /* db_hpp */
