#include <iostream>
#include <string>
#include <fstream>

const int N_MAX=2000;
bool Read (int&n, int& cnt, std::string words[N_MAX])
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
        //std::cout << "<"<< s<<">"<< std::endl;
    }
    return true;
}

void Write(int cnt, std::string words[N_MAX])
{
    for (int i=0;i<cnt;++i)
        std::cout<<"<"<<words[i]<<">"<<std::endl;
}

void ClearWords (int cnt, std::string words[N_MAX])
{
    for (int i=0; i<cnt;++i)
        for (int j=0; j<words[i].length();++j)
        {
            if(!isalpha(words[i][j]))
                words[i].erase(j,1);
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

    Write(cnt,words);
    return 0;
}