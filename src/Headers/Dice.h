#include <cstdlib>
#include <ctime>

using namespace std;

class Dice{
private:
   int sides;
public:
   int result;

   Dice(void){
     result = 0;
     sides = 12;
   }

   int roll(){
    srand((unsigned int) time(NULL));
    return (rand() % sides) + 1;
   }
};
