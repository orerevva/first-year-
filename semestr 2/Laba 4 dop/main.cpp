#include <iostream>
#define N_Max 1000

class BigInt 
{
    char m_value[N_Max];
    short m_size = 0;
    bool m_negative = false; 

public:
    BigInt() {
        for(int i = 0; i < N_Max; i++)
            m_value[i] = 0;
        m_size = 1;
    }
    
    BigInt(const char* value) {
        int start = 0;
        if (value[0] == '-') {
            m_negative = true;
            start = 1;
        }
        
        int len = 0;
        while(value[len + start] != '\0') len++;
        
        for(int i = 0; i < len; i++)
            m_value[i] = value[len + start - i - 1] - '0';
        for(int i = len; i < N_Max; i++) 
            m_value[i] = 0;
        m_size = len;
        
        normalize();
    }

    void normalize()
    {
        while (m_size > 1 && m_value[m_size - 1] == 0)
        {
            m_size--;
        }
        if(m_size == 1 && m_value[0] == 0)
        {
            m_negative = false;
        }
    }
    
    BigInt absolute() const
    {
        BigInt result = *this;
        result.m_negative = false;
        return result;
    }

    BigInt& operator+=(const BigInt& other) 
    {
        if (m_negative == other.m_negative)
        {
            int max_size = std::max(m_size, other.m_size);
            for(int i = 0; i < max_size; i++) 
            {
                if (i < other.m_size)
                    m_value[i] += other.m_value[i];
                if(m_value[i] > 9) 
                {
                    m_value[i] -= 10;
                    m_value[i+1]++;
                }
            }
            m_size = max_size;
            if (m_value[m_size] != 0) m_size++;
        }
        else
        {
            if(absolute() == other.absolute())
            {
                *this = BigInt("0");
                return *this;
            }
            
            bool thisIsLarger = absolute() > other.absolute();
            
            if (thisIsLarger) 
            {
                for(int i = 0; i < m_size; i++) 
                {
                    char other_val = (i < other.m_size) ? other.m_value[i] : 0;
                    if (m_value[i] < other_val) 
                    {
                        m_value[i] += 10;
                        m_value[i+1]--;
                    }
                    m_value[i] -= other_val;
                }
            }
            else 
            {
                BigInt temp = other;
                for(int i = 0; i < temp.m_size; i++) 
                {
                    char this_val = (i < m_size) ? m_value[i] : 0;
                    if (temp.m_value[i] < this_val) 
                    {
                        temp.m_value[i] += 10;
                        temp.m_value[i+1]--;
                    }
                    temp.m_value[i] -= this_val;
                }
                *this = temp;
                m_negative = other.m_negative;
            }
        }
        normalize();
        return *this;
    }

    BigInt operator+(const BigInt& other) const
    {
        BigInt result(*this);
        result += other;
        return result;
    }

    BigInt operator*(const BigInt& other) const
    {
        BigInt result("0");
        BigInt temp;

        for (int i = 0; i < m_size; ++i) 
        {
            int carry = 0;
            temp = BigInt("0");

            for (int j = 0; j < other.m_size; ++j) 
            {
                int product = m_value[i] * other.m_value[j] + carry;
                temp.m_value[i + j] = product % 10;
                carry = product / 10;
            }
            temp.m_value[i + other.m_size] = carry;
            temp.m_size = i + other.m_size + 1;
            temp.normalize();

            result += temp;
        }
        
        result.m_negative = m_negative != other.m_negative;
        result.normalize();
        return result;
    }

    BigInt& operator*=(const BigInt& other)
    {
        *this = *this * other;
        return *this;
    }

    bool operator<(const BigInt& other) const
    {
        if (m_negative != other.m_negative)
            return m_negative;
            
        if(m_size < other.m_size)
            return !m_negative;
        else if(m_size > other.m_size)
            return m_negative;
        else 
        {
            for(int i = m_size - 1; i >= 0; i--) 
            {
                if(m_value[i] < other.m_value[i])
                    return !m_negative;
                else if(m_value[i] > other.m_value[i])
                    return m_negative;
            }
            return false;
        }
    }

    bool operator>=(const BigInt& other) const
    {
        return !(*this < other);
    }

    bool operator>(const BigInt& other) const
    {
        if (m_negative != other.m_negative)
            return other.m_negative;
            
        if(m_size > other.m_size)
            return !m_negative;
        else if(m_size < other.m_size)
            return m_negative;
        else 
        {
            for(int i = m_size - 1; i >= 0; i--) 
            {
                if(m_value[i] > other.m_value[i])
                    return !m_negative;
                else if(m_value[i] < other.m_value[i])
                    return m_negative;
            }
            return false;
        }
    }

    bool operator<=(const BigInt& other) const
    {
        return !(*this > other);
    }

    bool operator==(const BigInt& other) const
    {
        if (m_size != other.m_size || m_negative != other.m_negative)
            return false;
            
        for (int i = 0; i < m_size; ++i) 
        {
            if (m_value[i] != other.m_value[i])
                return false;
        }
        return true; 
    }

    bool operator!=(const BigInt& other) const
    {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
    friend std::istream& operator>>(std::istream& in, BigInt& other);
};

std::istream& operator>>(std::istream& in, BigInt& other) 
{
    char s[N_Max + 2];
    in >> s;
    other = BigInt(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& other) 
{
    if (other.m_negative)
        out << "-";
    for(int i = other.m_size - 1; i >= 0; i--) {
        out << static_cast<short>(other.m_value[i]);
    }
    return out;
}

int main() 
{
    BigInt x;
    std::cout << "1 number: ";
    std::cin >> x;
    
    BigInt y;
    std::cout << "2 number: ";
    std::cin >> y;
    
    BigInt x_n = x;
    BigInt y_n = y;
    
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;

    if(x < y) 
    {
        std::cout << x << " < " << y << std::endl;
    }

    if(x > y) 
    {
        std::cout << x << " > " << y << std::endl;
    }
    
    if(x >= y) 
    {
        std::cout << x << " >= " << y << std::endl;
    }
    
    if(x <= y) 
    {
        std::cout << x << " <= " << y << std::endl;
    }

    if(x == y)
    {
        std::cout << x << " == " << y << std::endl;
    }

    if(x != y)
    {
        std::cout << x << " != " << y << std::endl;
    }

    x_n += y_n;
    std::cout << "x += y: " << x_n << std::endl;

    x_n = x;
    x_n *= y_n;
    std::cout << "x *= y: " << x_n << std::endl;

    return 0;
}