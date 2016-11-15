#ifndef INCLUDED_PDCAST_H
#define INCLUDED_PDCAST_H

namespace Pluto{

template <class Target, class Source>
inline Target polymorphic_downcast(Source& x)
{
    BOOST_ASSERT( dynamic_cast<Target>(x) == x );  // detect logic error
    return static_cast<Target>(x);
}

}

#endif