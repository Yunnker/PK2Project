#pragma once
#include <iostream>
#include <string>

namespace ObjectEnum {
    enum ObjectType {
        NullType,
        Folder,
        Standard,
        LP
    };
};

class Object {
protected:
    ObjectEnum::ObjectType m_type = ObjectEnum::NullType;
    std::string m_name = "Default name";
public:
    void SetType(ObjectEnum::ObjectType type) { m_type = type; }
    ObjectEnum::ObjectType GetType() const { return m_type; }

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

    virtual std::string Edit(std::string s) { return ""; }
    virtual std::string Select(std::string s) { return ""; }
};