#include <iostream>

template <typename T, int N, int M>
class Matrix
{
    private:
        T data[N][M];
    public:
        Matrix()
        {
            for (int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    data[i][j] = T();
        }  

        Matrix(const Matrix& other)
        {
            for (int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    data[i][j] = other.data[i][j];
        }

        Matrix& operator=(const Matrix& other)
        {
            if (this != &other)
            {
                for (int i = 0; i < N; i++)
                    for(int j = 0; j < M; j++)
                        data[i][j] = other.data[i][j];
            }
            return *this;
        }

        friend std::istream& operator>>(std::istream& in, Matrix& other)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    in >> other.data[i][j];
            return in;
        }
        
        friend std::ostream& operator<<(std::ostream& out, Matrix& other)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                    out << other.data[i][j]<<" ";
                out << std::endl;
            }
            return out;
        }
        
        Matrix operator+(const Matrix& other)const
        {
            //Matrix result = *this;
            //result+=other;
            //return result;
            Matrix result;
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    result.data[i][j] = data[i][j] + other.data[i][j];
            return result;
        }

        Matrix& operator+=(const Matrix& other)
        {
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    data[i][j] += other.data[i][j];
            return *this;
        }

        template <int K>
        Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const 
        {
            Matrix<T, N, K> result;
            for (int i = 0; i < N; i++)
                for (int k = 0; k < K; k++) 
                {
                    result.data[i][k] = 0; 
                    for (int j = 0; j < M; j++)
                        result.data[i][k] += data[i][j] * other.data[j][k];
                }
            return result;
        }

        Matrix& operator*=(const Matrix& other)
        {
            *this = *this * other;
            return *this;
        }

        Matrix& operator*=(const T& sc) 
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    data[i][j] *= sc;
            return *this;
        }

        Matrix& operator++()
        {
            for(int i = 0; i < N; i++) 
                for(int j = 0; j < M; j++) 
                    data[i][j] += 1;
            return *this;
        }

        T dt() const
        {
            if (N == M)
            {
                if (N == 1)
                    return data[0][0];
                else if (N == 2)
                    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
                else if (N == 3)
                    return  data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                    data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                    data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);  
            }
            else if (N!=M)
            {
                return -1;
            }    
        }

        T& operator()(int i, int j) 
        {
            return data[i][j];
        }

}; 




int main()
{
    Matrix<int, 2, 2> A, B;

    std::cin >> A;
    std::cin >> B;
    std::cout<<"<<<<>>>>>"<<std::endl;

    Matrix<int, 2, 2> C = A + B;
    std::cout<<C<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    std::cout<<(A+=B)<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    A *= 2;
    std::cout<<A<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    std::cout<<(A*B)<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;
    
    std::cout<<(A*=B)<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    std::cout<<(++A)<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    std::cout<<(A(1,1))<<std::endl;
    std::cout<<"<<<<>>>>>"<<std::endl;

    std::cout<<A.dt()<< std::endl;

    return 0;
}
