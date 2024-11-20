#include <iostream>
#include <string>
#include <fstream>

const int N_MAX=2000;

int main ()
{
    int n;
    int cnt;
    std::string words[N_MAX];
    char m='a';
    std::string new_words[N_MAX];
    int mas[N_MAX];

// считываем файл, узнаем кол-во слов
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cerr<<"File error"<<std::endl;
        return -1;
    }
    in>>n;
    cnt=0; 
    while (!in.eof())
    {
        in>> words[cnt];
        cnt++;
    }

//очищаем от посторонних знаков
    for (int i=0; i<cnt;++i)
        for (int j=0; j<words[i].length();++j)
        {
            if(!isalpha(words[i][j]))
            {
                words[i].erase(j,1);
                --j;
            }
        }

// поиск слов с определенной буквой
    for ( int i=0; i<cnt; ++i)
        if (words[i].find(m)==0)
        {
            new_words[i]=words[i];
            mas[i]= (words[i].length());
        }
    
// сортировка
    for (int i=0; i<cnt;++i)
        for (int j=0; j<cnt; ++j)
            if ((mas[i]<mas[j]) ||((mas[i]==mas[j]) && (new_words[i]<new_words[j])))
            {
                std::swap(mas[i], mas[j]);
                std::swap(new_words[i], new_words[j]);
            }
//вывод
    std:: string previous = "";           
    for (int i=0;i<cnt;++i)
        if (! new_words[i].empty())
            if(new_words[i]!= previous)
            {
                previous =new_words[i];
                std::cout<<"<"<<new_words[i]<<">"<<std::endl;
            }
    return 0;
}





/*
bool Read (int&n, int& cnt, std::string words[N_MAX])
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cerr<<"File error"<<std::endl;
        return false;
    }
    in>>n;
    cnt=0; // сколько слов в массиве  
    while (!in.eof())
    {
        in>> words[cnt];
        cnt++;
        //std::cout << "<"<< s<<">"<< std::endl;
    }
        return true;
    }

    void Write(int cnt, std::string words[N_MAX])
{
    for (int i=0;i<cnt;++i)
        std::cout<<"<"<<words[i]<<">"<<std::endl;
}

void Write1(int n, int cnt, std::string words[N_MAX])
{   
    bool first=true;
    for (int i=0;i<cnt;++i)
        {   
            if (n==0)
                break;
            n--;
            if (first)
            {
                
            }
            std::cout<<"<"<<words[i]<<">"<<std::endl;
        }
}

void ClearWords (int cnt, std::string words[N_MAX])
{
    for (int i=0; i<cnt;++i)
        for (int j=0; j<words[i].length();++j)
        {
            if(!isalpha(words[i][j]))
            {
                words[i].erase(j,1);
                --j;
            }
        }
}

int main()
{   
    int n;
    int cnt=0;
    std::string words[N_MAX];
    if (!Read(n,cnt,words))
        return -1;
    ClearWords(cnt,words);
    char m;
    std::cin>> m;
    Write(cnt,words);
    return 0;
}


int main ()
{
    std::string new_words[1000];
    std::string words[1000];
    char t= 'a';
    for (int i=0; i<5;i++)
        std::getline(std::cin, words[i]);
    for (int i=0; i<10; i++)
    {
        //std::size_t m= (words[i].length());
        if (t==words[i][0])
            new_words[i]=words[i];
        //std::cout<<m <<std::endl;
        std::cout<<new_words<<std::endl;
    }

    return 0;
}
*/