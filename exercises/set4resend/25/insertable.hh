// JB: ?
#ifndef INSERTABLE_HH
#define INSERTABLE_HH
#include <iosfwd>

template <template <typename> class Container, typename Type>
struct Insertable : public Container<Type>
{
    // default, copy and move constructors
    Insertable() = default;
    Insertable(Insertable const &other) = default;
    Insertable(Insertable &&tmp) = default;

    // initialization by an existing data storage object
    Insertable(Container<Type> const &other); //JB: SF <type>.
    Insertable(Container<Type> &&tmp);

    // initialization by a single data element of the used container
    Insertable(Type const &other);
    Insertable(Type &&tmp);

    // make the class insertable into a stream
    friend std::ostream &
    operator<<<Container, Type>(std::ostream &out,
                                Insertable<Container, Type> const &ins);
};

// #include "insertable.i"
// the file is provided in ex 27, therefore outcommented here.
//JB: While that's fair enough, the exercise calls for a class that is
//JB: insertable into an ostream. This one is not.

#endif
