class FinalExamples {
    public:
        void l1() final {
            // error: nonvirtual function cannot be declared with 'final' modifier
        };
        
        virtual void l2() final{
            // ok
        }; 
        virtual void l3() final = 0;
        // no error, even though the method is abstract
        // this makes the class uninitializable
    
    };
