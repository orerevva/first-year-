#include <iostream>
#include <string>
#include <fstream>

const int N_MAX=2000;

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
void Search(int& cnt, char m, int mas[N_MAX], std::string words[N_MAX])
{   
    int k=0;
    for (int i=0; i<cnt; ++i)
        for (int j=0; j<words[i].length(); j++)
            {   int k=0;
                tolower(words[i][j]);
                if (words[i].find(m)==0)
                {
                    mas[i]= (words[i].length());
                    continue;
                }
                words[k]=words[i];
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
void wwrite(int cnt,std::string words[N_MAX])
{
    for (int i=0; i<cnt; i++)
        std::cout<<"<"<<words[i]<<">"<<std::endl;
        
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
    Search(cnt, m, mas, words);
    Sorting(cnt,mas, words);
    Write(cnt,n, words);
    return 0;
}





