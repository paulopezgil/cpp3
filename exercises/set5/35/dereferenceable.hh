#ifndef DEREFERENCEABLE_HH
#define DEREFERENCEABLE_HH

// a concept that checks if a Type supports the dereference operator
template <typename Type>
concept Dereferenceable = 
    requires(Type type)
    {
        *type;
    };

#endif