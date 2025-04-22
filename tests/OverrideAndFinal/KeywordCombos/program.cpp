#include <bits/stdc++.h>
#include "VirtualFunctionality.cpp"
using namespace std;

class KeywordsCombinations : public Base {
    public:
        virtual void f() override { // can use 'virtual' and 'override' in one definition
            cout << "Function f of a class KeywordsCombinations" << endl;
        }; 
        virtual void g() override final { // and 'final' as well
            cout << "Function g of a class KeywordsCombinations" << endl;
        }

        virtual void z() final {
            cout << "Function z of a class KeywordsCombinations" << endl;
        }
        
    };