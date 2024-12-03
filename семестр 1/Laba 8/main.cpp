#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

const int N_MAX=2000;
/*
//1
bool Read (int& n, int& cnt, std::string words[N_MAX]) 
{
    std::ifstream in("input1.txt");
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
void Search(int& cnt, int& k, char m, std::string words[N_MAX], std::string new_words[N_MAX])
{  
    for (int i=0; i<cnt; ++i)
        if (tolower(words[i][0])==m)
        {
            new_words[k]=words[i];
            ++k;  
        }
}

void Sorting (int cnt, std::string words[N_MAX])
{
    for (int i=0; i<cnt;++i)
        for (int j=0; j<cnt; ++j)
            if ((words[i].length()>words[j].length()) || ((words[i].length()==words[j].length()) && (tolower(words[i][0])>(tolower(words[j][0])))))
                std::swap(words[i], words[j]); 
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
        if (n>0)
        {
            words[i][0]=tolower(words[i][0]);
            if (words[i]!=previous)
            {
                previous=words[i];
                std::cout<<"<"<<words[i]<<">"<<std::endl;
                --n;
            }
        }

}

int main ()
{

    int n, cnt, k=0;
    std::string words[N_MAX];
    char m='p';
    std::string new_words[N_MAX];

    if (!(Read (n, cnt, words)))
        return -1;
    Clear(cnt, words);
    Search(cnt, k, m, words, new_words);
    Sorting(k,new_words);
    Write(k,n, new_words);

    return 0;
}

*/

/*
//2
bool Read (int& n, std::string words[N_MAX])
{
    std::ifstream in("input2.txt");
    if (!in.is_open())
    {
        std::cerr<<"File error"<<std::endl;
        return false;
    }
    n=0;
    while (!in.eof())
    {
        in>> words[n];
        n++;
    }
    return true;
}

bool isPalindrome( int n, std::string words[N_MAX]) 
{   
    for (int i=0; i<n; i++)
    {
        if(words[i].length()>2)
        {
            std::string reversed = words[i];
            std::reverse(reversed.begin(), reversed.end());
            if (words[i] == reversed)  
                return true;
            continue;
        }
    }
    return false;
}

int count_vowels(int n,  std::string words[N_MAX])
{
    int vowelCount = 0; 
    std::string vowels = "aeiouyAEIOUY"; 
    for (int i=0; i<n;++i)
        for (char c : words[i])
        {
            if (vowels.find(c) != std::string::npos) 
                ++vowelCount; 
        }
    return vowelCount;
}

void wwrite(int n,std::string words[N_MAX])
{
    for (int i=0; i<n; i++)
        std::cout<<"<"<<words[i]<<">"<<std::endl;
        
}

void write_1(int vowelCount, int n,  std::string words[N_MAX] )
{ 
    
    for (int i=0; i<n; i++)
    {
        std::cout<< words[i]<< std::endl;
        vowelCount--;
        if (vowelCount <= 0)
            break; 
    }

}
void delete_vowels_double_consonants(int n, std::string words[N_MAX], std::string new_words[N_MAX])
{
    int k=0;
    std::string result; 
    std::string vowels = "aeiouyAEIOUY";
    for (int i=0; i<n;i++)
    {
        result="";
        for (char c : words[i]) 
        {
            if (vowels.find(c) == std::string::npos) 
            {
                result += c; 
                result += c;
            }
        }
        new_words[k]=result;
        k++;
    }
}

void write_2(int n, std::string new_words[N_MAX])
{
     std::sort(new_words, new_words + n);
    for (int i = 0; i < n; i++) 
        std::cout << new_words[i] << std::endl;
}

int main()
{
    int n;
    std::string new_words[N_MAX];
    std::string words[N_MAX];
    if (!(Read (n, words)))
        return -1;
    if (isPalindrome (n,words))
        write_1(count_vowels(n, words), n, words);
    else
    {
        delete_vowels_double_consonants(n, words, new_words);
        write_2(n,new_words);
    }
    return 0;
}
*/

//3
bool Read (int& n, std::string words[N_MAX])
{
    std::ifstream in("input3.txt");
    if (!in.is_open())
    {
        std::cerr<<"File error"<<std::endl;
        return false;
    }
    n=0;
    while (!in.eof())
    {
        in>> words[n];
        n++;
    }
    return true;
}

bool serch_7_letters(std::string word, std::string& unicue)
{   
    int count=0;
    unicue.clear();
    std::string mas;
    for (char c : word)  
        if ((std::isalpha(c)) && (mas.find(c)==std::string::npos))
        {
            mas+=c;
            unicue+=c;
            count++;
        }
    return count>7;
}

void upper_letters(int n, std::string words[N_MAX], std::string unicue[N_MAX])
{
    for (int i=0; i<n; i++)
        if (serch_7_letters(words[i], unicue[i]))
            for (int j=0; j<words[i].length();j++)
                words[i][j]=toupper(words[i][j]);
        else 
        {
            unicue[i].clear();
        }
}

void write(int n,std::string words[N_MAX],std::string unique[N_MAX])
{
    for (int i=0; i<n; i++)
    {
        
        if(!unique[i].empty())
        {
            std::cout<<words[i]<<"("<<unique[i]<<")"<<std::endl;
        }
        else
        {
            std::cout<<words[i]<<std::endl;
        }
    }
}     

int main ()
{
    int n;
    std::string unique[N_MAX];
    std::string words[N_MAX];
    if (!(Read (n, words)))
        return -1;
    upper_letters(n,words,unique);
    write(n, words, unique);

    return 0;
}

