
// стратегия изменения capacity
enum class ResizeStrategy {
    Additive,
    Multiplicative
};

template<class T>
class MyVector
{
public:
    class VectorIterator
    {
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  
        using reference         = T&;  

        VectorIterator(T* ptr);
		VectorIterator(const VectorIterator& copy);
		VectorIterator operator=(const VectorIterator& copy);

        VectorIterator& operator++();
        VectorIterator operator++(int);
        VectorIterator& operator--();
        VectorIterator operator--(int);
        reference operator*() const;
        pointer operator->();
        bool operator!=(const VectorIterator& other) const;
		bool operator==(const VectorIterator& other) const;

    private:
        T* _ptr;
    };

    class ConstVectorIterator 
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = const T;
        using pointer           = const T*;  
        using reference         = const T&;  

        ConstVectorIterator(T* ptr);
		ConstVectorIterator(const ConstVectorIterator& copy);
		ConstVectorIterator operator=(const ConstVectorIterator& copy);

        ConstVectorIterator& operator++();
        ConstVectorIterator operator++(int);
        ConstVectorIterator& operator--();
        ConstVectorIterator operator--(int);
        reference operator*() const;
        pointer operator->();
        bool operator!=(const ConstVectorIterator& other) const;
		bool operator==(const ConstVectorIterator& other) const;

    private:
        T* _ptr;
    };

    // заполнить вектор значениями ValueType()
    MyVector(size_t size = 0, 
             ResizeStrategy = ResizeStrategy::Multiplicative, 
             float coef = 1.5f);
    // заполнить вектор значениями value
    MyVector(size_t size, 
             T value, 
             ResizeStrategy = ResizeStrategy::Multiplicative, 
             float coef = 1.5f);
    
    MyVector(const MyVector& copy);
    MyVector& operator=(const MyVector& copy);
    
    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;
    ~MyVector();
    
    size_t capacity() const;
    size_t size() const;
    float loadFactor() const;
    
    VectorIterator begin();
    ConstVectorIterator cbegin() const;
    VectorIterator end();
    ConstVectorIterator cend() const;

    // доступ к элементу, 
    // должен работать за O(1)
    T& operator[](const size_t i);
    const T& operator[](const size_t i) const;
    
    // добавить в конец,
    // должен работать за amort(O(1))
    void pushBack(const T& value);
    // вставить,
    // должен работать за O(n)
    void insert(const size_t i, const T& value);     // версия для одного значения
    void insert(const size_t i, const MyVector& value);      // версия для вектора
    void insert(ConstVectorIterator it, const T& value);  // версия для одного значения
    void insert(ConstVectorIterator it, const MyVector& value);   // версия для вектора
    
    // удалить с конца,
    // должен работать за amort(O(1))
    void popBack();
    // удалить
    // должен работать за O(n)
    void erase(const size_t i);
    void erase(const size_t i, const size_t len);            // удалить len элементов начиная с i
    
    // найти элемент,
    // должен работать за O(n)
    // если isBegin == true, найти индекс первого элемента, равного value, иначе последнего
    // если искомого элемента нет, вернуть end
    ConstVectorIterator find(const T& value, bool isBegin = true) const;
    
    // зарезервировать память (принудительно задать capacity)
    void reserve(const size_t capacity);
    
    // изменить размер
    // если новый размер больше текущего, то новые элементы забиваются value
    // если меньше - обрезаем вектор
    void resize(const size_t size, const T& value = T());
    
    // очистка вектора, без изменения capacity
    void clear();
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    ResizeStrategy _strategy;
    float _coef;
};