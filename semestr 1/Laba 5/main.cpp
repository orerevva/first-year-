#include <iostream>
int main () {
    int a, i;
    int r=1;
    int n;
    long long m=-9223372036854775808;

    std::cin>>i;
    for(int k=0; k<i; k++)
    {
        std::cin>>a;
        if (a%10==2)
        {
            r= r*a;
            if (a>m)
            {
                m=a;
                n=k;
            } 
        } 
    }
    if (r==1)
    {
        std::cout<<"ERROR"<<std::endl;
    }
    else{
    std::cout<<"multiplying numbers:"<<r<<std::endl;
    std::cout<<"MAX:" << m<<std::endl;
    std::cout<<"highest number:"<<n<<std::endl;
    }

/*
int N;
    std::cin >> N;

    int n_digits = 0;
    int digit0 = 0, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0,
    digit5 = 0, digit6 = 0, digit7 = 0, digit8 = 0, digit9 = 0;

    while (N > 0)
    {
        switch (N % 10)
        {
            case 0: digit0 += 1; break;
            case 1: digit1 += 1; break;
            case 2: digit2 += 1; break;
            case 3: digit3 += 1; break;
            case 4: digit4 += 1; break;
            case 5: digit5 += 1; break;
            case 6: digit6 += 1; break;
            case 7: digit7 += 1; break;
            case 8: digit8 += 1; break;
            case 9: digit9 += 1; break;
        };
        n_digits += 1;
        N /= 10;
    }

    //int ans = std::max(digit0, std::max(digit1, std::max(digit2, std::max(digit3, std::max(digit4, std::max(digit5, std::max(digit6, std::max(digit7, std::max(digit8, digit9)))))))));
    while (n_digits > 0)
    {
        bool digit_found = false;
        if (digit0 == n_digits) {std::cout << 0 <<std:: endl; digit_found = true;}
        if (digit1 == n_digits) {std::cout << 1 <<std:: endl; digit_found = true;}
        if (digit2 == n_digits) {std::cout << 2 << std::endl; digit_found = true;}
        if (digit3 == n_digits) {std::cout << 3 << std::endl; digit_found = true;}
        if (digit4 == n_digits) {std::cout << 4 << std::endl; digit_found = true;}
        if (digit5 == n_digits) {std::cout << 5 << std::endl; digit_found = true;}
        if (digit6 == n_digits) {std::cout << 6 << std::endl; digit_found = true;}
        if (digit7 == n_digits) {std::cout << 7 << std::endl; digit_found = true;}
        if (digit8 == n_digits) {std::cout << 8 << std::endl; digit_found = true;}
        if (digit9 == n_digits) {std::cout << 9 << std::endl; digit_found = true;}
        if (digit_found) break;
        n_digits -= 1;
    }
    */
    return 0;

    /*int n;
    std::cin>>n;
    int digits[12] = {0};

    while (n>0)
    {
        digits[n % 10]++;
        n/=10;
    }
    int max = -1;
    for (int i =0; i<10; i++){
        if (digits[i]>max) max = digits[i];
    }
    std::cout<<max;*/
    


}