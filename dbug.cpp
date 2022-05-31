#include <iostream>
#include "Vector.hpp"
#include "pair.hpp"
#include "map.hpp"

int main()
{
    ft::vector< fc::pair<std::string, int> > v;

    const char *p[58] = { "wording", "far", "original", "crouch", "revive", "mainstream", "waiter", "sunshine", "motivation", 
        "quarter", "zero", "noble", "module", "lump", "incredible", "visual", "ranch", "default", "admiration", "chase", 
        "pedestrian", "evening", "concert", "environmental", "alarm", "injury", "disaster", "theft", "bill", "fax", "trainer", 
        "display", "looting", "crystal", "fill", "prisoner", "war", "breakfast", "camera", "coup", "gravity", "lay", "hit", 
        "straight", "rate", "band", "helpless", "sex", "eject", "dash", "contrast", "rehearsal", "golf", "poem", "desire", "waist", 
        "nonremittal", "indulge" };

    for (size_t i = 0; i < 58; i++) {
        fc::pair<std::string, int> tmp(p[i], i);
        v.push_back(tmp);
    }

    ft::vector< fc::pair<std::string, int> >::iterator ib = v.begin();
    ft::vector< fc::pair<std::string, int> >::iterator ie = v.end();

    ft::map<std::string, int> m(ib, ie);
    ft::map<std::string, int>::iterator first = m.begin();
    ft::map<std::string, int>::iterator last = m.end();
    
    for (; first != last; first++) {
        std::cout << (*first).first << std::endl; 
    }
    

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}