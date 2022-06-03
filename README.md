# ft_containers
Re-implementation of C++ containers

## Vector
Without the vector<bool> specialization.

## Map
 
## Stack
It will use the implemented vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.

## Useful links
### Mans nd docs:

  https://www.cplusplus.com/reference/vector/vector/  
  AllocatorAwareContainer // https://en.cppreference.com/w/cpp/named_req/AllocatorAwareContainer  
  https://en.cppreference.com/w/cpp/memory/allocator

### Vector behavior:
  
  https://stackoverflow.com/questions/17299951/c-vector-what-happens-whenever-it-expands-reallocate-on-stack  
  vector constructor: https://www.cplusplus.com/reference/vector/vector/vector/  
  Writing your own STL Container: https://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622. 

### Details about iterator_traits:
  
An Introduction to "Iterator Traits": https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits  
http://www.cplusplus.com/forum/beginner/43395/  
https://en.cppreference.com/w/cpp/iterator/iterator_traits#:~:text=std%3A%3Aiterator_traits%20is%20the,only%20in%20terms%20of%20iterators.  
https://en.cppreference.com/w/cpp/iterator/reverse_iterator  

### A bit deeper into c++:
destruction and built-in types: https://stackoverflow.com/questions/71010802/will-destructor-delete-built-in-types-and-pointer-objects  
allocator: http://candcplusplus.com/c-allocator-class-member-functions  
iterators and reallocation: https://stackoverflow.com/questions/36300745/how-do-iterators-update-after-vector-reallocation  
insert(), emplace_back(), emplace(), push_back(), erase(), pop_back(), resize(), clear() invalidate iterators, references and pointers  

### For map:
  data-structures:  
  https://github.com/Bibeknam/algorithmtutorprograms  
  binary search tree:  
  https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/. 
  AVL tree - balanced binary search tree:  
  https://www.youtube.com/watch?v=vRwi_UcZGjU&ab_channel=BackToBackSWE  
  https://www.youtube.com/watch?v=FNeL18KsWPc&ab_channel=MITOpenCourseWare  
  https://progmohamedali.wordpress.com/2013/03/20/third-semester-project/  
  Red-Black trees:  
  https://www.youtube.com/watch?v=nMExd4DthdA&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=67&ab_channel=RobEdwards  
  https://www.youtube.com/watch?v=v6eDztNiJwo&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=67&ab_channel=RobEdwards  
  https://www.youtube.com/watch?v=-qjrcxVmf2Q&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=68&ab_channel=RobEdwards  
  https://tildesites.bowdoin.edu/~ltoma/teaching/cs231/fall16/Lectures/05-BST/rbtrees.pdf  
  https://courses.cs.duke.edu/cps100e/fall98/lects/sect17rbtreeH.pdf  
  https://www.programiz.com/dsa/deletion-from-a-red-black-tree  

### enable_if:  
https://www.youtube.com/watch?v=H-m23Vvzcug&ab_channel=CppinDetail  
  
(See expected vector implementations in refs.txt)
