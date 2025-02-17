#ifndef UNIQUE_HH_
#define UNIQUE_HH_

#include "globalcounter/counter.hh"
#include <memory>

template <typename Type>
class Unique
{
    std::unique_ptr<Type> d_ptr;
    static size_t s_count;
    static size_t s_actual;
    GlobalCounter d_counter;    // independent of template arguments

    public:
        // destructor
        ~Unique();

        // default, copy and move constructor
        Unique();
        Unique(Unique const &other);
        Unique(Unique &&tmp);

        // constructors accepting Types
        Unique(Type const &tp);
        Unique(Type *ptr);

        // copy and move assignment
        Unique &operator=(Unique const &other);
        Unique &operator=(Unique &&other) = default; // uses unique_ptr default
                                                    // move assignment
        // get members
        Type &get();
        Type const &get() const;
        
        size_t actual() const;
        size_t count() const;
        size_t globalActual() const;
        size_t globalCount() const;
};

#include "unique.ii"
#endif