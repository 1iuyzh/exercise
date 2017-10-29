## 4.1
a. A  
b. G H I L M K
## 4.2
node:   parent  child   siblings    depth   height  
A:      null    [B C]   null        0       4  
B:      A       [D E]   C           1       3  
C:      A       F       B           1       2  
D:      B       [G H]   E           2       1  
E:      B       [I J]   D           2       2  
F:      C       K       null        2       1
G:      D       null    H           3       0
H:      D       null    G           3       0
I:      E       null    J           3       0  
J:      E       [L M]   I           3       1  
K:      F       null    null        3       0
L:      J       null    M           4       0  
M:      J       null    L           4       0
## 4.3
4