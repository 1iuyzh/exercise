#include<iostream>
#include<string>
#include<set>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::set;

class Message {
    friend class Folder;
public:
    explicit Message(const string &str = "") : contents(str) { }  // 默认构造函数
    Message(const Message &rhs) : contents(rhs.contents), folders(rhs.folders) {
        for (auto f : folders)
            f->addMsg(this);
    }            // 拷贝构造函数
    Message& operator=(const Message &rhs) {
        for (auto f : folders)
            f->remMsg(this);
        contents = rhs.contents;
        folders = rhs.folders;
        for (auto f : folders)
            f->addMsg(this);
        return *this;
    }           // 拷贝赋值操作符
    ~Message() {
        for (auto f : folders)
            f->remMsg(this);
    }           // 析构函数
    void save(Folder &f) {
        folders.insert(&f);
        f.addMsg(this);
    }           // 向一个给定的Folder添加该Message
    void remove(Folder &f) {
        folders.erase(&f);
        f.remMsg(this);
    }           // 从一个给定的Folder删除该Message
    void swap(Message &lhs, Message &rhs) {
        using std::swap;
        for (auto f : lhs.folders)
            f->remMsg(&lhs);
        for (auto f : rhs.folders)
            f->remMsg(&rhs);
        swap(lhs.folders, rhs.folders);
        swap(lhs.contents, rhs.contents);
        for (auto f : lhs.folders)
            f->addMsg(&lhs);
        for (auto f : rhs.folders)
            f->addMsg(&rhs);
    }
private:
    string contents;        // 消息文本
    set<Folder*> folders;   // 包含该Message的Folder的指针
};