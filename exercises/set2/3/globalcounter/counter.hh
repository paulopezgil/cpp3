#ifndef COUNTER_HH_
#define COUNTER_HH_
#include <iosfwd>

class GlobalCounter
{
    static size_t s_actual;
    static size_t s_count;

    public:
        ~GlobalCounter();
        GlobalCounter();

        size_t count() const;
        size_t actual() const;
};

inline GlobalCounter::~GlobalCounter()
{
    --s_actual;
}

inline size_t GlobalCounter::count() const
{
    return s_count;
}

inline size_t GlobalCounter::actual() const
{
    return s_actual;
}

#endif