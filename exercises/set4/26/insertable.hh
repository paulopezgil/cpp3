#include <utility>
#include <algorithm>
#include <iterator>

// the extension of the file should .i instead of .hh
// it's being changed so the mail handler accepts it

// initialize Insertable with a Container object using base class initializer
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Container<Type> const &other)
:
    Container<Type>(other)
{}

// initialize insertable with a temporary Container object
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Container<Type> &&tmp)
:
    Container<Type>(std::move(tmp))
{}

// initialize insertable with a single Type object
template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Type const &other)
:
    Container<Type>(other)
{}

template <template <typename> class Container, typename Type>
inline Insertable<Container, Type>::Insertable(Type &&tmp)
:
    Container<Type>(std::move(tmp))
{}

template <template <typename> class Container, typename Type>
std::ostream &operator<<(std::ostream &out,
                         Insertable<Container, Type> const &ins)
{
    std::copy(ins.begin(), ins.end(), std::ostream_iterator<Type>(out, "\n"));
    return out;
}