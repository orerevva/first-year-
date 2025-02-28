#include <iostream>
#include <stdexcept>

class MyVector
{
    private:
        int* data;
        size_t sz;
        size_t mx;

        void reallocate(size_t new_mx)
        {
            int* new_data = new int[new_mx];
            for(size_t i = 0; i < sz; i++)
                new_data[i] = data[i];
            delete[] data;

            data = new_data;
            mx = new_mx;
        }

    public:
        MyVector()
        {
            data = nullptr;
            sz = 0;
            mx = 0;
        }

        MyVector(int size)
        {
            sz = size;
            mx = size;
            data = new int[mx];
            for(int i = 0; i < sz; i++)
                data[i] = 0;
        }

        MyVector(const MyVector& other)
        {
            sz = other.sz;
            mx = other.mx;
            data = new int[mx];
            for(size_t i = 0; i < sz; i++)
                data[i] = other.data[i];
        }

        MyVector& operator=(const MyVector& other)
        {
            if (this == &other)
                return *this;
            delete[] data;

            sz = other.sz;
            mx = other.mx;
            data = new int[mx];
            for(size_t i = 0; i < sz; i++)
                data[i] = other.data[i];

            return *this;
        }

        ~MyVector()
        {
            delete[] data;
        }

        void resize(size_t new_size) // изменение размера вектора, добавив элементы
        {
            if(new_size > mx)
                reallocate(new_size);
            sz = new_size;
        }

        void reserve(size_t new_mx) // изменение емкости вектора, не добавляя новых элементов 
        {
            if (new_mx > mx)
                reallocate(new_mx);
        }

        void shrink_to_fit() // освободить память, которая не используется 
        {
            if(sz < mx)
                reallocate(sz);
        }
        
        int& front()
        {
            if (sz == 0)
                throw std::out_of_range("V is empty");
            return data[0];
        }

        int& back()
        {
            if(sz == 0)
                throw std::out_of_range("V is empty");
            return data[sz - 1];
        }

        size_t size() 
        {
            return sz;
        }

        bool empty()
        {
            return sz == 0;
        }

        size_t capacity()
        {
            return mx;
        }

        void push_back(int vl)
        {
            if (sz == mx)
            {
                if (mx != 0)
                    reallocate(mx * 2);
                else
                {
                    reallocate(1);
                }

            }
            data[sz++] = vl;
        }

        void insert(size_t index, int vl) // ставит элемент в определенную позицию 
        {
            if (index > sz)
                throw std::out_of_range("index error");
            if (sz == mx)
            {
                if (mx != 0)
                    reallocate(mx * 2);
                else
                {
                    reallocate(1);
                }

            }
            
            for(size_t i = sz; i > index; i--)
                data[i] = data[i-1];
            
            data[index] = vl;
            sz++;      
        }

        void erase(size_t index) // удаляет элемент, стоящи  на определенной позиции
        {
            if(index > sz)
                throw std::out_of_range("index error");
            
            for(size_t i = index; i < sz-1; i++)
                data[i] = data[i+1];
            
            sz--;
        }

        int& operator[](size_t index)
        {
            if (index >= sz)
                throw std::out_of_range("index error");
            return data[index];
        }

};

int main()
{
    MyVector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout<<"Size:"<<v.size()<<std::endl;
    std::cout<<"Capacity:"<<v.capacity()<<std::endl;
    std::cout<<"Front:"<<v.front()<<std::endl;
    std::cout<<"Back:"<<v.back()<<std::endl;

    v.insert(1,15);
    std::cout<<"1 index:"<<v[1]<<std::endl;

    v.erase(1);
    std::cout<<"1 index:"<<v[1]<<std::endl;

    v.resize(5);
    std::cout<<"after resize:"<<v.size()<<std::endl;

    v.shrink_to_fit();
    std::cout<<"after shrink_to_fit:"<<v.capacity()<<std::endl;



    return 0;
}
