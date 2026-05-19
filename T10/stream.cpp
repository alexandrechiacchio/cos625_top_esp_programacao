#include <algorithm>
#include <vector>


template <typename V, typename F>
auto operator | (const V& v, F map) {
    using elem_t = std::decay_t<decltype(*std::begin(v))>;
    using result_t = std::invoke_result_t<F, elem_t>;
    if constexpr (std::is_same_v<result_t, bool>) {
        auto ret = std::vector<elem_t>(std::size(v));
        auto lastIter = std::copy_if(std::begin(v), std::end(v), ret.begin(), map);
        ret.resize(lastIter - ret.begin());
        return ret;
    }
    else if constexpr (!std::is_same_v<result_t, void>) {
        auto ret = std::vector<elem_t>(std::size(v));
        std::transform(std::begin(v), std::end(v), ret.begin(), map);
        return ret;
    }
    std::for_each(std::begin(v), std::end(v), map);
}