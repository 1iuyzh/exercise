#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;             // 指向单词的指针
    int count;              // 单词出现的次数
    struct tnode *left;     // 左子节点
    struct tnode *right;    // 右子节点
};

struct tnode *talloc(void);
char *my_strdup(char *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(void) {
    int c;
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    c = getchar();
    return 0;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getchar()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {    // 该单词是一个新单词
        p = talloc();   // 创建一个新节点
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)  // 如果小于该节点中的单词，则进入左子树
        p->left = addtree(p->left, w);  // 最终保存在父节点中
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);  // '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}