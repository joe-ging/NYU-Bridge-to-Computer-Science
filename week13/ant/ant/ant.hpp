#ifndef ant_hpp
#define ant_hpp
#include <vector>
#include "organism.hpp"
#include "db.hpp"
using namespace std;

class ant: public Organism {
public:
    ant();
    virtual void move(vector<Organism>& vec1, vector<Organism>& vec2);
    int antCount() const;
    virtual void breed(vector<Organism>& vec1, vector<Organism>& vec2, int x, int y);
};

#endif /* ant_hpp */
