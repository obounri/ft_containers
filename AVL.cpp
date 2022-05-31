#include "AVL.hpp"



















int main() {
    AVL<std::string, int, std::less<std::string>, std::allocator<pair<const std::string, int> > >		bst;
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
	// bst.createSampleTree1();
	// bst.insert(v[0]);
	// bst.insert(v[1]);
	// bst.insert(v[2]);
	// bst.insert(v[3]);

    for (size_t i = 0; i < 58; i++) {
        bst.insert(v[i]);
    }
	// bst.inorder();
    bst.prettyPrint();
	return 0;
}