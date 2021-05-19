#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
   unordered_map<char, int> um;
   cout << "Initial size of unordered map = " << um.size() << endl;
   um = {
         {'a', 1},
         {'b', 2},
         {'c', 3},
         {'d', 4},
         {'e', 5},
      };
   cout << "Size of unordered map after inserting elements = " << um.size() << endl;
   cout<<um['f']<<endl;
   cout << "Size of unordered map after inserting elements = " << um.size() << endl;
   return 0;
}
