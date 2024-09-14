// c++17
// vec(val, dim1, dim2...)
auto vec(auto elem, size_t sz, auto... dim) {
    if constexpr (sizeof...(dim) == 0) return vector(sz, elem);
    else return vector(sz, vec(elem, dim...));
}

// c++14
template <typename T> 
auto vec(T elem, size_t sz) {
    return vector<T>(sz, elem);
}

template <typename T, typename... Args>
auto vec(T elem, size_t sz, Args... dim) {
    auto ret = vec(elem, dim...);
    return vector<decltype(ret)>(sz, ret);
}

