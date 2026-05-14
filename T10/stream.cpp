#include <algorithm>

void operator | ( const auto& v, auto map ) {
    if constexpr std::is_same_v<std::invoke_result_t<F, T>, bool>
  for_each( begin( v ), end( v ), map );
}