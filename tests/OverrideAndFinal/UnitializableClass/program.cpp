#include <bits/stdc++.h>
using namespace std;

class Uninitializable {
    private:
        static int counter;
    public:
            
            virtual void f() final = 0; // this makes the class abstract (uninitializable) 
                                        // as well as all derived classes   
            static void increaseCounter(){ // important: only nonstatic functions can be virtual
                counter++;
            }
            static int getCounter(){
                return counter;
            }
        };



int Uninitializable::counter = 10;


int checkUninitializable(){
    
    Uninitializable::increaseCounter();
    cout << Uninitializable::getCounter(); // output: 11

    // Uninitializable* obj1 = new Uninitializable; 
    // error: object of abstract class type "Uninitializable" is not allowed
}