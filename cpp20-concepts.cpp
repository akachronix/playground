#include <type_traits>

#if defined (__GNUC__)
    #if (__cplusplus >= 201103L)
        #define INLINE [[gnu::always_inline]]
    #else
        #define INLINE inline
    #endif
#elif defined (_MSVC_VER)
    #define INLINE __always_inline
#else
    #define INLINE
#endif

namespace {
    template <class T>
    concept Integral = std::is_integral_v<T>;

    template <class T>
    concept FloatingPoint = std::is_floating_point_v<T>;

    template <class T>
    concept Number = Integral<T> || FloatingPoint<T>;

    template <Number T>
    INLINE T add(T x, T y) {
        return x + y;
    }

    template <Number T>
    INLINE T subtract(T x, T y) {
        return x - y;
    }

    template <Number T>
    INLINE T multiply(T x, T y) {
        return x * y;
    }

    template <Number T>
    INLINE T divide(T x, T y) {
        return x / y;
    }

    template <Number T>
    INLINE T square(T x) {
        return x * x;
    }

    template <Number T>
    INLINE T cube(T x) {
        return x * x * x;
    }
}

int main() {
    return multiply(4, 8);
}
