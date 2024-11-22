#include <iostream>
#include <string>
#include <fstream>

const int N_MAX=2000;
// чтение
bool Read (int& n, int& cnt, std::string words[N_MAX]) 
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cerr<<"File error"<<std::endl;
        return false;
    }
    in>>n;
    cnt=0; 
    while (!in.eof())
    {
        in>> words[cnt];
        cnt++;
    }
    return true;
}

void Clear (int cnt, std::string words[N_MAX])
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
void Search(int& cnt, char m, int mas[N_MAX], std::string words[N_MAX], std::string new_words[N_MAX])
{   
    int k=0;
    for (int i=0; i<cnt; ++i)
        for (int j=0; j<words[i].length(); j++)
            {   int k=0;
                new_words[i]=tolower(words[i][j]);
                if (new_words[i].find(m)==0)
                {
                    mas[i]= (new_words[i].length());
                    continue;
                }
                new_words[k]=new_words[i];
                k++;
            }
    cnt=k;
}

void Sorting (int cnt, int mas[N_MAX], std::string words[N_MAX])
{
    for (int i=0; i<cnt;++i)
        for (int j=0; j<cnt; ++j)
            if ((mas[i]<mas[j]) ||((mas[i]==mas[j]) && (words[i]<words[j])))
            {
                std::swap(mas[i], mas[j]);
                std::swap(words[i], words[j]);
            }   
}
void wwrite(int cnt,std::string new_words[N_MAX])
{
    for (int i=0; i<cnt; i++)
        std::cout<<"<"<<new_words[i]<<">"<<std::endl;
        
}

void Write (int cnt,int& n, std::string words[N_MAX])
{
    std:: string previous = "";           
    for (int i=0;i<cnt;++i)
        if ((! words[i].empty())&& (n>0))
            if(words[i]!= previous)
            {
                previous =words[i];
                std::cout<<"<"<<words[i]<<">"<<std::endl;
                n--;
            }

}

int main ()
{
    int n;
    int cnt;
    std::string words[N_MAX];
    char m='a';
    std::string new_words[N_MAX];
    int mas[N_MAX];
    if (!(Read (n, cnt, words)))
        return -1;
    Clear(cnt, words);
    Search(cnt, m, mas, words, new_words);
    //Sorting(cnt,mas, words);
    //Write(cnt,n, words);
    wwrite(cnt, new_words);
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



*/