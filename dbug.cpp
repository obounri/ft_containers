#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"
// #include "Stack.hpp"
// #include "fcts.hpp"
#include "pair.hpp"
// #include "BST.hpp"
#include "map.hpp"
#include <memory>

int main()
{
    Vector< pair<std::string, int> > v;

    const char *p[58] = { "wording", "far", "original", "crouch", "revive", "mainstream", "waiter", "sunshine", "motivation", 
        "quarter", "zero", "noble", "module", "lump", "incredible", "visual", "ranch", "default", "admiration", "chase", 
        "pedestrian", "evening", "concert", "environmental", "alarm", "injury", "disaster", "theft", "bill", "fax", "trainer", 
        "display", "looting", "crystal", "fill", "prisoner", "war", "breakfast", "camera", "coup", "gravity", "lay", "hit", 
        "straight", "rate", "band", "helpless", "sex", "eject", "dash", "contrast", "rehearsal", "golf", "poem", "desire", "waist", 
        "nonremittal", "indulge" };
    for (size_t i = 0; i < 58; i++) {
        pair<std::string, int> tmp(p[i], i);
        v.push_back(tmp);
    }

    Vector< pair<std::string, int> >::iterator ib = v.begin();
    Vector< pair<std::string, int> >::iterator ie = v.end();

    map<std::string, int> m(ib, ie);
    
    m.debug();

    
    map<std::string, int> n;
    n.debug();

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}