#include <iostream>

using namespace std;

template<typename T>
struct TypedBuffer
{
    T* array;
    int size;
    TypedBuffer()
    {
        array = nullptr;
        size = 0;
    }

};
template<typename T>
TypedBuffer<T> create(size_t n, T k)
{
    TypedBuffer<T> buffer = TypedBuffer<T>();
    buffer.array = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        buffer.array[i] = k;
        buffer.size++;
    }
    return buffer;
}
template<typename T>
TypedBuffer<T> concat(TypedBuffer<T> a, TypedBuffer<T> b)
{
    TypedBuffer<T> buffer = TypedBuffer<T>();
    // add T elements from A buffer
    buffer.array = new T[a.size + b.size];
    for (size_t i = 0; i < a.size; i++)
    {
        buffer.array[i] = a.array[i];
        buffer.size++;
    }

    // add T elements from B buffer
    for (size_t i = 0; i < b.size; i++)
    {
        buffer.array[buffer.size] = b.array[i];
        buffer.size++;
    }

    return buffer;
}
template<typename T>
TypedBuffer<T> append(TypedBuffer<T> a, TypedBuffer<T> b)
{
    T* array = new T[a.size + b.size];
    for (size_t i = 0; i < a.size; i++)
    {
        array[i] = a.array[i];
    }

    for (size_t i = 0; i < b.size; i++)
    {
        array[a.size] = b.array[i];
        a.size++;
    }
    delete[] a.array;
    a.array = array;

    return a;
}
template<typename T>
TypedBuffer<T> union_buffers(TypedBuffer<T> a, TypedBuffer<T> b)
{
    TypedBuffer<T> buffer = TypedBuffer<T>();
    buffer.array = new T[a.size + b.size];
    // add T elements from A buffer
    for (size_t i = 0; i < a.size; i++)
    {
        if (contains(buffer, a.array[i]))
        {
            continue;
        }

        buffer.array[i] = a.array[i];
        buffer.size++;
    }

    for (size_t i = 0; i < b.size; i++)
    {

        if (contains(buffer, b.array[i]))
        {
            continue;
        }
        else {
            buffer.array[buffer.size] = b.array[i];
            buffer.size++;
        }
    }
    return buffer;
}
template<typename T>
bool contains(TypedBuffer<T> buffer, T element)
{
    for (size_t i = 0; i < buffer.size; i++)
    {
        if (buffer.array[i] == element)
        {
            return true;
        }
    }
    return false;
}
template<typename T>
void print(TypedBuffer<T> buffer)
{
    for (size_t i = 0; i < buffer.size; i++)
    {
        cout << buffer.array[i] << endl;
    }
}


// exr 2
class SumAvgCalculator 
{
private:
    int* elements;
    int size;
public:
    SumAvgCalculator()
    {
        elements = nullptr;
        size = 0;
    }
    ~SumAvgCalculator()
    {
        delete[] elements;
        elements = nullptr;
        size = 0;
    }
    SumAvgCalculator(int element)
    {
        elements = new int[1];
        elements[0] = element;
        size = 1;
    }
    int sum()
    {
        int result = 0;
        for (size_t i = 0; i < size; i++)
        {
            result += elements[i];
        }
        return result;
    }
    void add(int element)
    {
        int* newElements = new int[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        newElements[size] = element;
        delete[] elements;
        elements = newElements;
        size++;
    }
    int num()
    {
        return size;
    }
    double average()
    {
        double result = 0;
        for (size_t i = 0; i < size; i++)
        {
            result += elements[i];
        }
        return result / size;
    }
    void sub(int element)
    {
        element = element * (-1);

        int* newElements = new int[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        newElements[size] = element;
        delete[] elements;
        elements = newElements;
        size++;
    }
    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << elements[i] << endl;
        }
    }

    SumAvgCalculator& operator+=(SumAvgCalculator& other)
    {
        int* newElements = new int[size + other.size];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }

        for (size_t i = 0; i < other.size; i++)
        {
            newElements[size] = other.elements[i];
            size++;
        }
        delete[] elements;
        elements = newElements;
        return *this;
    }
    SumAvgCalculator& operator+(SumAvgCalculator& other)
    {
        /*SumAvgCalculator calc = SumAvgCalculator();
        int* newElements = new int[size + other.size];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        calc.size = size;
        for (size_t i = 0; i < other.size; i++)
        {
            newElements[calc.size] = other.elements[i];
            calc.size++;
        }
        calc.elements = newElements;
        return calc;*/

        int* newElements = new int[size + other.size];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }

        for (size_t i = 0; i < other.size; i++)
        {
            newElements[size] = other.elements[i];
            size++;
        }
        delete[] elements;
        elements = newElements;
        return *this;
    }
};
int main()
{
    // ex1 tests
    /*
    TypedBuffer<int> buffer1 = create(10, 1);
    print(buffer1);
    TypedBuffer<int> buffer2 = create(5, 2);
    print(buffer2);
    TypedBuffer<int> union_buffer= union_buffers(buffer1, buffer2);
    print(union_buffer);
    buffer1 = append(buffer1, buffer2);
    print(buffer1);
    TypedBuffer<int> buffer3 = concat(buffer1, buffer2);
    print(buffer3);
    */

    SumAvgCalculator seq1(10);

    seq1.add(10);

    seq1.add(5);

    seq1.sub(15);
    seq1.print();
    cout << seq1.sum() << endl; //->10 (10+10+5-15)
    cout << seq1.average() << endl;; //->(10+10+5-15) / 4 = 2.5

    SumAvgCalculator seq2(-10);
    seq2.add(-10);

    seq2.add(-5);

    seq2.sub(-15);
    // (seq1 + seq2).print();
    seq1 += seq2;

    seq1.print();
}
