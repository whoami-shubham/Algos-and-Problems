/*
Consider a special family of Engineers and Doctors. This family has the following rules:

Everybody has two children.
The first child of an Engineer is an Engineer and the second child is a Doctor.
The first child of a Doctor is a Doctor and the second child is an Engineer.
All generations of Doctors and Engineers start with an Engineer.
We can represent the situation using this diagram:

                E
           /         \
          E           D
        /   \        /  \
       E     D      D    E
      / \   / \    / \   / \
     E   D D   E  D   E E   D
Given the level and position of a person in the ancestor tree above, find the profession of the person.
Note: in this tree first child is considered as left child, second - as right.


*/

string findProfession(int level, int pos) {
    
    char cur = 'E';
    int n = pow(2,level-1);
    int half = n/2;
    int dist = pos;
    while(dist>0 && half>0){
         if(half<dist){
             cur  = cur=='D'?'E':'D';
             dist = abs(half-dist);
         }
         half = half/2;
    }
    return cur=='E'?"Engineer":"Doctor";
    

}
