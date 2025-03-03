#ifndef INSERTABLE_HH
#define INSERTABLE_HH


template <template <typename> class Container, typename Type>
struct Insertable : public Container<Type>
{
    // default, copy and move constructors
    Insertable() = default;
    Insertable(Insertable const &other) = default;
    Insertable(Insertable &&tmp) = default;

    // initialization by an existing data storage object
    Insertable(Container<Type> const &other);
    Insertable(Container<Type> &&tmp);

    // initialization by a single data element of the used container
    Insertable(Type const &other);
    Insertable(Type &&tmp);
};

// #include "insertable.i"
// the file is provided in ex 27, therefore outcommented here.

#endif