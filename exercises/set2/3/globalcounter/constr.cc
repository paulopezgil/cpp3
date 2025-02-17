#include "counter.hh"

size_t GlobalCounter::s_actual = 0;
size_t GlobalCounter::s_count = 0;

GlobalCounter::GlobalCounter()
{
    ++s_actual;
    ++s_count;
}