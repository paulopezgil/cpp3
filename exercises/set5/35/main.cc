#include "main.ih"

int main()
{
    // calling fun1 and fun2 with a dereferenceable type
    int *dereferenceable = 0;
    fun1(dereferenceable);
    fun2(dereferenceable);

    // creating class1 and class2 with dereferenceable types
    Class1<int *> c1{};
    Class2<int *> c2{};
    
    // using the classes so the compiler doesn't complain
    c1.fun();
    c2.fun();
    
    // The following doesn't compile:
    //int not_dereferenceable = 0;
    //fun1(not_dereferenceable);
    //fun2(not_dereferenceable);
    //Class1<int> c1{};
    //Class2<int> c2{};
}