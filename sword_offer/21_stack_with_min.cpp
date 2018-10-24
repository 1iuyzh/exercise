#include <vector>
#include <stack>

template <typename T>
class StackWithMin {
public:
    void push(const T& value);
    void pop();
    const T& min() const;
private:
    std::stack<int> m_data;
    std::stack<int> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T& value) {
    m_data.push(value);

    if (m_min.size() == 0 || value < m_data.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop() {
    assert(m_data.size() > 0 && m_min.size() > 0);
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const {
    assert(m_data.size() > 0 && m_min.size() > 0)
    return  m_min.top();
}