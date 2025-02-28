#include <iostream>
#define N_Max 1000

class BigInt 
{
  char m_value[N_Max];
  short m_size = 0;

  public:

        BigInt() = default;
        BigInt(const std::string& value) 
        {
            size_t len = value.length();
            for(int i=0;i<len;i++)
                m_value[i] = value[len-i-1] - '0';
            for(int i=len;i<N_Max;i++) 
            {
                m_value[i] = 0;
            }
            m_size = len;
        }


        BigInt& operator+=(const BigInt& other) 
        {
            for(int i=0;i<m_size;i++) 
            {
                m_value[i] += other.m_value[i];
                if(m_value[i] > 9) 
                {
                    m_value[i] -= 10;
                    m_value[i+1]++;
                    if(i+1 == m_size)
                        m_size++;
                }
            }
            return *this;
        }


        BigInt operator+(const BigInt& other)
        {
            BigInt result(*this);
            result += other;
            return result;
        }

        BigInt operator*(const BigInt& other)
        {
            BigInt result("0");
            int carry = 0;

            for (int i = 0; i < m_size; ++i) 
            {
                carry = 0;
                BigInt temp("0");

                for (int j = 0; j < other.m_size; ++j) 
                {
                    int product = ((int)m_value[i]) * ((int)other.m_value[j]) + carry;
                    temp.m_value[i + j] += product;
                    carry = temp.m_value[i + j] / 10;
                    temp.m_value[i + j] %= 10;
                }
                temp.m_value[i + other.m_size] += carry;

                carry = 0;
                for (int k = 0; k < N_Max; ++k) 
                {
                    result.m_value[k] += temp.m_value[k] + carry;
                    carry = result.m_value[k] / 10;
                    result.m_value[k] %= 10;
                }
            }
            
            result.m_size = m_size + other.m_size;
            while (result.m_size > 0 && (int)result.m_value[result.m_size - 1] == 0) 
            {
                result.m_size--;
            }
            return result;
        }

        BigInt& operator*=(const BigInt& other)
        {
            *this = *this * other;
            return *this;
        }

        bool operator<(const BigInt& other) 
        {
            if(m_size < other.m_size)
                return true;
            else if(m_size > other.m_size)
                return false;
            else 
            {
                for(int i=m_size-1;i>=0;i--) 
                {
                    if(m_value[i] < other.m_value[i])
                        return true;
                    else if(m_value[i] > other.m_value[i])
                        return false;
                }
                return false;
            }
        }

        bool operator>=(const BigInt& other) 
        {
            return !(*this < other);
        }

        bool operator>(const BigInt& other) 
        {
            if(m_size > other.m_size)
                return true;
            else if(m_size < other.m_size)
                return false;
            else 
            {
                for(int i=m_size-1;i>=0;i--) 
                {
                    if(m_value[i] > other.m_value[i])
                        return true;
                    else if(m_value[i] < other.m_value[i])
                        return false;
                }
                return false;
            }
        }

        bool operator<=(const BigInt& other) 
        {
            return !(*this > other);
        }

        bool BigInt::operator==(const BigInt& other)
        {
            if (m_size != other.m_size)
            {
                return false;
            }
            for (int i = 0; i < m_size; ++i) 
            {
                if (m_value[i] != other.m_value[i])
                {
                    return false;
                }
            }
            return true; 
        }

        bool BigInt::operator!=(const BigInt& other)
        {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
        friend std::istream& operator>>(std::istream& in, BigInt& other);
};

std::istream& operator>>(std::istream& in, BigInt& other) 
{
    std::string s;
    in >> s;
    other = BigInt(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& other) 
{
    for(int i=0;i<other.m_size;i++) {
        out << static_cast<short>(other.m_value[other.m_size - i - 1]);
    }
    return out;
}

int main() 
{
    BigInt x;
    std::cin >> x;
    BigInt y;
    std::cin >> y;
    
    BigInt z = x + y;
    std::cout << z << std::endl;

    BigInt q ("567");
    std::cout << (q+=x) << std::endl;

    BigInt mk = x * y;
    std::cout << mk << std::endl;

    BigInt l("1");
    std::cout << (l*=x) << std::endl;


    if(x < y) 
    {
        std::cout << "<" << std::endl;
    }

    if(x > y) 
    {
        std::cout << ">" << std::endl;
    }
    
    if(x >= y) 
    {
        std::cout << ">=" << std::endl;
    }
    
    if(x <= y) 
    {
        std::cout << "<=" << std::endl;
    }

    if(x==y)
    {
        std::cout << "==" << std::endl;
    }

    if(x!=y)
    {
        std::cout << "!=" << std::endl;
    }

    return 0;
}
