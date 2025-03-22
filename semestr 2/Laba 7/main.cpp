#include<iostream>

class VectorBool
{
    private:
       uint8_t* data;
       size_t sz;
       size_t cap;

       bool get_bit(size_t index) const 
       {
            size_t by = index / 8;
            size_t bit = index % 8;
            return (data[by] >> bit) & 1;
       }

       void set_bit(size_t index, bool vl)
       {
        size_t by = index / 8;
        size_t bit = index % 8;
        if(vl)
            data[by] |= (1 << bit);
        else
            data[by] &= ~(1 << bit);
       }

       void resize(size_t new_cap)
       {
        uint8_t* new_data = new uint8_t[(new_cap + 7) / 8];
        for (size_t i = 0; i < (sz + 7) / 8; i++ )
        {
            new_data[i] = data[i]; 
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
       }

    public:
        VectorBool() 
        {
            data = nullptr;
            sz = 0;
            cap = 0;
        }

        ~VectorBool()
        {
            delete[] data;
        }

        void push_back(bool vl)
        {
            if (sz == cap)
            {
                if (cap != 0)
                {
                    resize(cap * 2);
                }
                else
                {
                    resize(8);
                }
            }
            set_bit(sz, vl);
            sz++;
        }

        size_t size() const{
            return sz;
        }

        bool operator[](size_t index) const 
        {
            return get_bit(index);
        }

        void insert(size_t index, bool vl)
        {
            push_back(false);
            for (size_t i = sz - 1; i > index; i--)
            {
                set_bit(i, get_bit(i - 1));
            }
            set_bit(index, vl);
        }

        void erase(size_t index)
        {
            for (size_t i = index; i < sz - 1; i++)
            {
                set_bit(i, get_bit(i + 1));
            }
            sz--;
        }

        void print() const
        {
            for (size_t i = 0; i < sz; i++)
            {
                std::cout<<get_bit(i)<<" "; 
            }
            std::cout<<std::endl;
        }

};
int main()
{
    VectorBool vb;

    vb.push_back(true);
    vb.push_back(false);
    vb.push_back(true);

    vb.print();
    std::cout<<"<<<<<<<<<<<<<<>>>>>>>>>>>"<<std::endl;

    std::cout<<vb.size()<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<>>>>>>>>>>>"<<std::endl;
    
    for (size_t i = 0; i < vb.size(); i++)
        std::cout<<vb[i]<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<>>>>>>>>>>>"<<std::endl;

    vb.insert(1,true);
    vb.print();
    std::cout<<"<<<<<<<<<<<<<<>>>>>>>>>>>"<<std::endl;

    vb.erase(2);
    vb.print();
    std::cout<<"<<<<<<<<<<<<<<>>>>>>>>>>>"<<std::endl;

    return 0;
}