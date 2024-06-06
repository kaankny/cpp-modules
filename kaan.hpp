#ifndef KAAN_HPP
#define KAAN_HPP


// my own container class
template <typename T>
class Kaan
{
	private:
		T* data;
		int size;
		int capacity;
	public:
		Kaan()
		{
			size = 0;
			capacity = 1;
			data = new T[capacity];
		}

		~Kaan()
		{
			delete[] data;
		}

		void push_back(T value)
		{
			if(size == capacity)
			{
				capacity *= 2;
				T* temp = new T[capacity];
				for(int i = 0; i < size; i++)
				{
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
			}
			data[size] = value;
			size++;
		}

		T& operator[](int index)
		{
			return data[index];
		}

		int get_size()
		{
			return size;
		}

		int get_capacity()
		{
			return capacity;
		}

		void clear()
		{
			size = 0;
		}

		void pop_back()
		{
			size--;
		}

		void erase(int index)
		{
			for(int i = index; i < size - 1; i++)
			{
				data[i] = data[i + 1];
			}
			size--;
		}

		void insert(int index, T value)
		{
			if(size == capacity)
			{
				capacity *= 2;
				T* temp = new T[capacity];
				for(int i = 0; i < size; i++)
				{
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
			}
			for(int i = size; i > index; i--)
			{
				data[i] = data[i - 1];
			}
			data[index] = value;
			size++;
		}

		void resize(int new_size)
		{
			if(new_size > capacity)
			{
				capacity = new_size;
				T* temp = new T[capacity];
				for(int i = 0; i < size; i++)
				{
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
			}
			size = new_size;
		}

		void reserve(int new_capacity)
		{
			if(new_capacity > capacity)
			{
				capacity = new_capacity;
				T* temp = new T[capacity];
				for(int i = 0; i < size; i++)
				{
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
			}
		}

		void print()
		{
			for(int i = 0; i < size; i++)
			{
				std::cout << data[i] << " ";
			}
			std::cout << std::endl;
		}

		void sort()
		{
			for(int i = 0; i < size - 1; i++)
			{
				for(int j = 0; j < size - i - 1; j++)
				{
					if(data[j] > data[j + 1])
					{
						T temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
		}

		void reverse()
		{
			for(int i = 0; i < size / 2; i++)
			{
				T temp = data[i];
				data[i] = data[size - i - 1];
				data[size - i - 1] = temp;
			}
		}

		void unique()
		{
			for(int i = 0; i < size; i++)
			{
				for(int j = i + 1; j < size; j++)
				{
					if(data[i] == data[j])
					{
						erase(j);
						j--;
					}
				}
			}
		}

		void remove(T value)
		{
			for(int i = 0; i < size; i++)
			{
				if(data[i] == value)
				{
					erase(i);
					i--;
				}
			}
		}

		void remove_if(bool (*func)(T))
		{
			for(int i = 0; i < size; i++)
			{
				if(func(data[i]))
				{
					erase(i);
					i--;
				}
			}
		}

		void swap(Kaan<T>& other)
		{
			T* temp_data = data;
			int temp_size = size;
			int temp_capacity = capacity;

			data = other.data;
			size = other.size;
			capacity = other.capacity;

			other.data = temp_data;
			other.size = temp_size;
			other.capacity = temp_capacity;
		}

		class iterator
		{
			private:
				T* ptr;
			public:
				iterator(T* ptr)
				{
					this->ptr = ptr;
				}

				T& operator*()
				{
					return *ptr;
				}

				iterator& operator++()
				{
					ptr++;
					return *this;
				}

				iterator operator++(int)
				{
					iterator temp = *this;
					ptr++;
					return temp;
				}

				iterator& operator--()
				{
					ptr--;
					return *this;
				}

				iterator operator--(int)
				{
					iterator temp = *this;
					ptr--;
					return temp;
				}

				bool operator==(const iterator& other)
				{
					return ptr == other.ptr;
				}

				bool operator!=(const iterator& other)
				{
					return ptr != other.ptr;
				}
		};

		iterator begin()
		{
			return iterator(data);
		}

		iterator end()
		{
			return iterator(data + size);
		}

		iterator rbegin()
		{
			return iterator(data + size - 1);
		}

		iterator rend()
		{
			return iterator(data - 1);
		}

		iterator find(T value)
		{
			for(int i = 0; i < size; i++)
			{
				if(data[i] == value)
				{
					return iterator(data + i);
				}
			}
			return end();
		}

		iterator find_if(bool (*func)(T))
		{
			for(int i = 0; i < size; i++)
			{
				if(func(data[i]))
				{
					return iterator(data + i);
				}
			}
			return end();
		}
};

#endif