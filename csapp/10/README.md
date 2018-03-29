STDIN_FILENO's k how to move?
## 10.1
fd2=3 or fd2=-1
## 10.2
c = f
## 10.3
c = o
## 10.4
dup2(5, 0);
## 10.5
c = o
## 10.6
fd2 = 4
## 10.9
./fstatcheck 3 < foobar.txt  
type: other, read: no  
./fstatcheck 0 < foobar.txt  
type: regular, read: yes
```c
if (Fork() == 0) {
    int fd = open("foobar.txt", O_RDONLY, 0);
    dup2(fd, STDIN_FILENO);
    close(fd);
    Execve("fstatcheck", argv, envp);
}
```