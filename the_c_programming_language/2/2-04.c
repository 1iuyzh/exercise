#include <stdio.h>
void squeeze(char leftstr[], char rightstr[]);

int main()
{
    int c;
    char leftstr[] = "helloworld";
    char rightstr[] = "linux";
    squeeze(leftstr, rightstr);
    printf("result: %s\n", leftstr);
    c = getchar();
    return 0;
}

void squeeze(char leftstr[], char rightstr[])
{
    int i, j, k;
    int instr = 0;

    for (i=j=0; leftstr[i]!='\0'; i++)
    {
        for (k=0; rightstr[k]!='\0'; k++)
        {
            if (leftstr[i]==rightstr[k])
                instr = 1;
        }
        if (instr==0)
            leftstr[j++] = leftstr[i];
        instr = 0;
    }
    leftstr[j] = '\0';
}