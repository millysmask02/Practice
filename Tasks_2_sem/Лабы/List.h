#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iterator>
#include <cstddef>  

using ValueType = int;
class List {
    class Node {
    public:
    	Node(const ValueType& value, Node* next = nullptr);
		~Node();
		void insertNext(const ValueType& value);
		void removeNext();

		ValueType data;
		Node* next;
    };
    Node* _head;
    size_t _size;
public:
    class Iterator;
    List();
    List(const List& copy); //конструктор копирования
    List(List&& other) noexcept; //конструктор перемещения

    List& operator=(const List& copy);
    List& operator=(List&& other) noexcept;

    ~List() = default;

    size_t size() const;
    bool empty() const; //пустой ли список

    const ValueType& operator[](size_t pos) const; // доступ к значению элемента по индексу
    ValueType& operator[](size_t pos);
	List::Node* getNode(const size_t pos) const; // доступ к узлу по индексу

    const ValueType& front() const; // возвращает ссылку на первый элемент
    ValueType& front();

    const ValueType& back() const; // возвращает ссылку на последний элемент
    ValueType& back();

    void insert(size_t pos, const ValueType& value);
    
    void pushBack(const ValueType& value);
    void pushFront(const ValueType& value);

    void popFront();
    void popBack();
    void remove(size_t pos);
    

    void clear();

    // void forEach(void (* callback)(ValueType& currVal, size_t idx));
    // List map(ValueType (* callback)(const ValueType& currVal)) const;
    // List filter(bool (* callback)(const ValueType& currVal)) const;
    // void insert(const List::Iterator& pos, const ValueType& val);
    // void remove(const Iterator& pos);
    // void removeAfter(const Iterator& pos);

    void reverse(size_t begin, size_t end);

    void print();


    class Iterator {
    private:
        Node* _ptr;
    public:
        friend List;
        Iterator(Node* ptr);
        Iterator(const Iterator& it);

        Iterator operator+(size_t n);

        Iterator& operator++ ();

        Iterator operator++ (int);


        bool operator!=(const Iterator& it) const;
        bool operator==(const Iterator& it ) const;

        ValueType& operator*() const;
    };
    Iterator begin() const { return Iterator(_head); };
    Iterator end() const { return nullptr; };
};