#ifndef PYTHONIC_NUMPY_ISSCTYPE_HPP
#define PYTHONIC_NUMPY_ISSCTYPE_HPP

#include "pythonic/include/numpy/issctype.hpp"

#include "pythonic/numpy/isscalar.hpp"

namespace pythonic
{

  namespace numpy
  {
    template <class E>
    constexpr auto issctype(E const &expr) ->
        typename std::enable_if<not types::is_dtype<E>::value and
                                    not std::is_same<E, types::str>::value,
                                bool>::type
    {
      return isscalar(typename E::type());
    }

    template <class E>
    constexpr auto issctype(E const &expr) ->
        typename std::enable_if<types::is_dtype<E>::value or
                                    std::is_same<E, types::str>::value,
                                bool>::type
    {
      return false;
    }

    DEFINE_FUNCTOR(pythonic::numpy, issctype);
  }
}

#endif
