#include <stdio.h>
#include <string.h>

long long int computeHash(char *s){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hashValue = 0;
    long long pPower = 1;
    for(int i=0; i<strlen(s); i++){
        hashValue = (hashValue + (s[i] - 'A' + 1) * pPower) % m;
        pPower = (pPower * p) % m;
    }
    return hashValue;
}

int main()
{
    char s[1000];
    printf("Enter the String in upper case:\n");
    scanf("%[^\n]s", s);
    printf("Hash Value: %lld", computeHash(s));
    return 0;
}