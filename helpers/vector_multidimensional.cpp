template <class T> vector<T> create(size_t size, T initialValue) { return vector<T>(size, initialValue); }
template <class T, class... Args> auto create(size_t head, Args&&... tail) { auto inner = create<T>(tail...); return vector<decltype(inner)>(head, inner); }