#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
private:
    T*              _array;
    unsigned int    _size;

public:
    Array() : _array(NULL), _size(0)
    {
    }

    Array(unsigned int n) : _array(NULL), _size(n) 
    {
        if (_size > 0) 
            _array = new T[_size]();
    }

    Array(const Array& src) : _array(NULL), _size(0) 
    {
        *this = src; 
    }

    Array& operator=(const Array& src)
    {
        if (this != &src) {
            T* tmp_array = NULL;
            if (src._size > 0)
            {
                tmp_array = new T[src._size]();
                for (unsigned int i = 0; i < src._size; i++)
                    tmp_array[i] = src._array[i];
            }
            
            delete[] _array;
            _array = tmp_array;
            _size = src._size;
        }
        return *this;
    }

    ~Array() 
    {
        delete[] _array;
    }

    T& operator[](unsigned int index) 
    {
        if (index >= _size)
            throw OutOfBoundsException();
        return _array[index];
    }

    const T& operator[](unsigned int index) const 
    {
        if (index >= _size)
            throw OutOfBoundsException();
        return _array[index];
    }

    unsigned int size() const 
    {
        return _size;
    }

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: Index is out of bounds";
        }
    };
};

#endif