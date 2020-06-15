#include <iostream>

char s[] = "ABCDEFabcdef1234";
void func() { 
    std::cout << s << std::endl;
}

int main()
{
    
    for (size_t i = 0, n = strlen(s); i < n; ++i)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= 'A' - 'a';
    func();
    return 0;
}
