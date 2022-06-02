template<typename T, typename Container>
class PriorityQueue {
	Container _container;
	
	//Возвращает индекс левого ребёнка по индексу родителя 2*i + 1
	int _leftChildIndex(int parentIndex);
	
	//Возвращает индекс правого ребёнка по индексу родителя 2*i + 2
	int _rightChildIndex(int parentIndex);
	
	//Возвращает индекс родителя по индексу ребёнка (int)(0.5 * i + 0.5) - 1
	int _parentIndex(int childIndex);
	
	//"Просеивание" вверх
	void _siftUp(int index);
	
	//"Просеивание" вниз
	void _siftDown(int index);

	// при необходимости просеивает вниз элементы
	void _stabilization();
	
public:
	//Добавление элемента в очередь, реализуется через siftUp
	void push(const T& value);
	
	//Возвращает верхний элемент очереди, не удаляя его
	T top() const;
	 
	//Возвращает верхний элемент, удаляет его, делает siftDown
	T pop();
	
	//Проверяет, пустая очередь или нет
	bool empty() const;
};