#define HASHSIZE 101

struct nlist {
    struct nlist *next;     // 链表中下一表项
    char *name;             // 定义的名字
    char *defn;             // 替换文本
};
static struct nlist *hashtab[HASHSIZE]; // 指针表

char *strdup(char *);

// hash函数: 为字符串s生成散列值
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;  // 不能超过指针表范围
}

// lookup函数: 在hashtab中查找s
struct nlist *loopup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np-next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

// install函数: 将(name, defn)加入到hashtab中
struct nlist *intall(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  // 未找到
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn) == NULL))
        return NULL;
    return np;
}
