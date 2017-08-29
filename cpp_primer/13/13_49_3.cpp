// 为Message类添加移动构造函数和移动赋值运算符
#include<iostream>
#include<string>
#include<set>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::set;

class Folder;

class Message {
    friend class Folder;

public:
    explicit Message(const string &str = "") : contents(str) { }  // 默认构造函数
    // 先声明类class Folder;
    // 再声明类Message中需要用到addMsg()和remMsg()的成员
    // 再定义class Folder;
    // 最后定义Message的成员, 因为addMsg()定义在类Folders中
    Message(const Message&);            // 拷贝构造函数
    Message(Message&&);           // 移动构造函数
    Message& operator=(const Message&); // 拷贝赋值操作符
    Message& operator=(Message&&);    // 移动赋值运算符
    ~Message();                         // 析构函数
    void save(Folder&);         // 向一个给定的Folder添加该Message
    void remove(Folder&);       // 从一个给定的Folder删除该Message
    void swap(Message&, Message&);

private:
    string contents;        // 消息文本
    set<Folder*> folders;   // 包含该Message的Folder的指针

private:
    void move_folders(Message*);
};

class Folder {
    friend class Message;
public:
    Folder() = default;    // 默认构造函数
    Folder(const Folder &rhs) : messages(rhs.messages) {
        for (auto m : messages)
            m->save(*this);
    }    // 拷贝构造函数
    Folder& operator=(const Folder &rhs) {
        for (auto m : messages)
            m->remove(*this);
        messages = rhs.messages;
        for (auto m : messages)
            m->save(*this);
        return *this;
    }
    ~Folder() {
        for (auto m : messages)
            m->remove(*this);
    }
private:
    set<Message*> messages;
    void addMsg(Message *m) {
        messages.insert(m);
    }
    void remMsg(Message *m) {
        messages.erase(m);
    }
};

Message::Message(const Message &rhs) : contents(rhs.contents), folders(rhs.folders) {
    for (auto f : folders)
        f->addMsg(this);
}
Message& Message::operator=(const Message &rhs) {
    for (auto f : folders)
        f->remMsg(this);
    contents = rhs.contents;
    folders = rhs.folders;
    for (auto f : folders)
        f->addMsg(this);
    return *this;
}
Message::~Message() {
    for (auto f : folders)
        f->remMsg(this);
}
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}
void Message::swap(Message &lhs, Message &rhs) {
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
void Message::move_folders(Message *m) {
    folders = std::move(m->folders);    // 给成员folders赋值
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}
Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_folders(&m);
}
Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        for (auto f : folders)
            f->remMsg(this);    // 析构函数
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

int main() {
    return 0;
}