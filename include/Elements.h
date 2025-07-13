#include "Object.h"

class LP : public Object {
    std::string m_login;
    std::string m_pass;
public:

    LP();
    LP(std::string login, std::string pass);
    LP(std::string name, std::string login, std::string pass);


    void PrintFull(int spaces = 0) override;
    std::string Edit(const std::string &s) override;
    std::string Select(const std::string& s) override;

    static std::string CreationMenu();
};

class Folder : public Object {
    struct Node {
        std::shared_ptr<Object> data;
        std::shared_ptr<Folder> folder;
        std::shared_ptr<Node> next;

        int Size();
    public:
        std::shared_ptr<Object> operator[](int index)
        {
            if (index == 0) return data;
            if (next == nullptr) return nullptr;
            return next->operator[](index - 1);
        }
    };
    std::shared_ptr<Node> m_head;

public:
    Folder() : m_head(nullptr) {
        SetName("Folder");
        SetType(ObjectTypes::Folder);
    }
    Folder(std::string name) : m_head(nullptr) {
        SetName(name);
        SetType(ObjectTypes::Folder);
    }

    int Size();
    void Print(int spaces = 0) override;
    void PrintFolders(int spaces = 0);
    void PrintFull(int spaces = 0) override;

    static std::string CreationMenu();

    std::string CreateElement(const std::string& s) override;
    std::string Select(const std::string& s) override;
    std::string Edit(const std::string& s) override;    //TODO

    std::string Find(const std::string& s);

    ObjectTypes::ObjectType CheckType(int pos);


    std::shared_ptr<Object> FromPosition(int pos);
    std::shared_ptr<Folder> FromPositionFolder(int pos);
    void PopFront();
    void PopBack();
    void DeleteFromPosition(int position);
     
    template<class T>
    void PushFront(T value) {
        static_assert(std::is_base_of<Object, T>::value, "T must be a descendant of Object");
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = std::make_shared<T>(value);
        newNode->next = m_head;
        m_head = newNode;
    }

    void PushFrontFolder(Folder value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->folder = std::make_shared<Folder>(value);
        newNode->next = m_head;
        m_head = newNode;
    }

    template<class T>
    void PushBack(T value) {
        static_assert(std::is_base_of<Object, T>::value, "T must be a descendant of Object");
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = std::make_shared<T>(value);
        newNode->next = nullptr;

        if (!m_head) {
            m_head = newNode;
            return;
        }

        std::shared_ptr<Node> temp = m_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void PushBackFolder(Folder value);

    template<class T>
    void InsertAtPosition(T value, int position) {
        static_assert(std::is_base_of<Object, T>::value, "T must be a descendant of Object");
        if (position < 0) return;
        if (position == 0) {
            PushFront(value);
            return;
        }

        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = std::make_shared<T>(value);

        std::shared_ptr<Node> temp = m_head;
        for (int i = 0; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void InsertAtPositionFolder(Folder value, int position);
};