#pragma once
#include <iostream>
#include <string>

namespace ObjectTypes {
    enum ObjectType {
        NullType,
        Folder,
        LP
    };
}

class Object {
public:
    void SetType(ObjectTypes::ObjectType type) { m_type = type; }
    ObjectTypes::ObjectType GetType() const { return m_type; }

    void SetName(const std::string& newName) { m_name = newName; }
    const std::string& GetName() const { return m_name; }

    bool operator==(const Object& other) const { return m_name == other.m_name; }

    virtual void Print(int spaces = 0) {
        if (spaces == -2) {
            std::cout << GetName() << " - " << GetType() << std::endl;
            return;
        }
        while (spaces) { std::cout << "  "; spaces--; }
        std::cout << m_name << std::endl;
    }

    virtual void PrintFull(int spaces = 0) {
        while (spaces) { std::cout << "  "; spaces--; }
        std::cout << m_name << std::endl;
    }

    virtual void PrintFolders(int spaces = 0) {};
    virtual std::string Edit(const std::string &s) { return ""; }
    virtual std::string Select(const std::string &s) { return ""; }
    virtual std::string CreateElement(const std::string &s) { return ""; }

protected:

    ObjectTypes::ObjectType m_type = ObjectTypes::NullType;

    std::string m_name = "Default name";
};