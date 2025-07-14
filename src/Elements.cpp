#include "Elements.h"
#include "Localization.h"
#include "SystemSpecific.h"

void Folder::PopFront() {
    if (!m_head) return;
    m_head = m_head->next;
}

void Folder::PopBack() {
    if (!m_head) return;
    if (!m_head->next) {
        m_head = nullptr;
        return;
    }

    auto temp = m_head;
    while (temp->next->next) {
        temp = temp->next;
    }
    temp->next = nullptr;
}

void Folder::DeleteFromPosition(int position) {
    if (position < 0) return;
    if (position == 0) {
        PopFront();
        return;
    }

    auto temp = m_head;
    for (int i = 0; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp || !temp->next) return;
    temp->next = temp->next->next;
}

void Folder::Print(int spaces) {
    if (spaces == -2) {
        std::cout << GetName() << " - " << GetType() << std::endl;
        return;
    }
    if (spaces == -1)
    {
        if (!m_head) {
            //std::cout << "List is empty." << std::endl;
            return;
        }

        std::shared_ptr<Node> temp = m_head;
        int i = 0;
        while (temp) {
            if (temp->data != nullptr)
            {
                std::cout << '[' << i << "] ";
                temp->data->Print(-2);
            }
            if (temp->folder != nullptr)
            {
                std::cout << '[' << i << "] ";
                temp->folder->Print(-2);
            }
            temp = temp->next;
            i++;
        }
        return;
    }

    int holdSpaces = spaces;
    while (spaces--) std::cout << "  ";
    std::cout << GetName() << ':' << std::endl;

    if (!m_head) return;

    auto temp = m_head;
    while (temp) {
        if (temp->data) temp->data->Print(holdSpaces + 1);
        if (temp->folder) temp->folder->Print(holdSpaces + 1);
        temp = temp->next;
    }
}

void Folder::PrintFolders(int spaces) {
    int holdSpaces = spaces;
    while (spaces--) std::cout << "  ";
    std::cout << GetName() << ':' << std::endl;

    if (!m_head) return;

    auto temp = m_head;
    while (temp) {
        if (temp->folder)
            temp->folder->PrintFolders(holdSpaces + 1);
        temp = temp->next;
    }
}

void Folder::PrintFull(int spaces) {
    int holdSpaces = spaces;
    while (spaces--) std::cout << "  ";
    std::cout << GetName() << ':' << std::endl;

    if (!m_head) return;

    auto temp = m_head;
    while (temp) {
        if (temp->data) temp->data->PrintFull(holdSpaces + 1);
        if (temp->folder) temp->folder->PrintFull(holdSpaces + 1);
        temp = temp->next;
    }
}

int Folder::Size() {
    if (!m_head) return 0;
    return m_head->Size();
}

std::string Folder::CreateElement(const std::string& s)
{
    int comas = 0;
    int x = -1;
    std::string z = "";
    std::string ans = "";
    if (s == "")
    {
        for (;;)
        {
			PRINTLN(Locale::STRING_ELEMENT_CREATION_MENU);
			PRINTLN(Locale::STRING_1_NEW_FOLDER);
			PRINTLN(Locale::STRING_2_NEW_LP);
			PRINTLN(Locale::STRING_0_GO_BACK);
            std::cin >> ans;
            x = std::stoi(ans);
            if (x < 0 || x>2)
            {
                CONSOLE_CLEAR();
                PRINTLN(Locale::STRING_WRONG_INPUT);
            }
            else
                break;
        }
        z = z + ans;
        switch (x)
        {
        case 1:
			z = z + "," + Folder::CreationMenu();
            break;
        case 2:
			z = z + "," + LP::CreationMenu();
            break;
        case 0:
            return "";
        default:
            break;
        }
        

    }
    else
    {
        z = s;
    }

    int comaCount = 0;
    int len = 0;
    for (size_t i = 0; i < z.length(); i++)
    {
        if (z[i] == ',')
            break;
        if (i == z.length() - 1)
            return "";
        len++;
    }
    std::string help = z.substr(0, len);
    int len1 = 0;
    int len2 = 0;
    int len3 = 0;
    int j = 0;
    int choice = std::stoi(help);
    switch (choice)
    {
    case 1:
        help = z.substr(len + 1, z.npos);
        PushBackFolder(Folder(help));
        break;
    case 2:
        help = z.substr(len + 1, z.npos);
        for (size_t i = 0; i < help.length(); i++)
        {
            if (help[i] == ',' && j == 0)
            {
                len1 = i; 
                j++;
            }
            else if(help[i] == ',' && j == 1)
            {
                len2 = i;
                j++;
            }
        }
        PushBack(LP(help.substr(0, len1), help.substr(len1 + 1, len2-len1-1), help.substr(len2 + 1, help.npos)));
        break;
    default:
        break;
    }

	CONSOLE_CLEAR();
	PRINTLN(Locale::STRING_ELEMENT_CREATION_SUCCESS);
    return z;
}

ObjectTypes::ObjectType Folder::CheckType(int pos)
{
    if (pos < 0) {
		PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return ObjectTypes::NullType;
    }
    if (pos == 0) {
        if (m_head->data == nullptr)
        {
            return m_head->folder->GetType();
        }
        return m_head->data->GetType();
    }
    std::shared_ptr<Node> temp = m_head;
    for (int i = 0; i < pos && temp; ++i) {
        temp = temp->next;
    }
    if (!temp) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return ObjectTypes::NullType;
    }

    if (temp->data == nullptr)
    {
        return temp->folder->GetType();
    }
    return temp->data->GetType();
}

std::shared_ptr<Object> Folder::FromPosition(int pos)
{
    if (pos < 0) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return nullptr;
    }

    if (pos == 0) {
        return m_head->data;
    }

    std::shared_ptr<Node> temp = m_head;
    for (int i = 0; i < pos && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return nullptr;
    }
    return temp->data;
}

std::shared_ptr<Folder> Folder::FromPositionFolder(int pos)
{
    if (pos < 0) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return nullptr;
    }

    if (pos == 0) {
        return m_head->folder;
    }

    std::shared_ptr<Node> temp = m_head;
    for (int i = 0; i < pos && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return nullptr;
    }
    return temp->folder;
}

void Folder::PushBackFolder(Folder value)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->folder = std::make_shared<Folder>(value);
    newNode->next = NULL;

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

void Folder::InsertAtPositionFolder(Folder value, int position)
{
    if (position < 1) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return;
    }

    if (position == 1) {
        PushFront(value);
        return;
    }

    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->data = std::make_shared<Folder>(value);

    std::shared_ptr<Node> temp = m_head;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        PRINTLN(Locale::STRING_POSITION_OUT_OF_RANGE);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

std::string Folder::Select(const std::string& s)
{
    std::string z = "";
    if (s == "")
    {
        bool cont = true;
        while (cont)
        {
            int ans = 5;

            PRINTLN(Locale::STRING_MENU);
            PRINTLN(Locale::STRING_1_PRINT_ALL_NAMES_AND_CONTENTS);
			PRINTLN(Locale::STRING_2_PRINT_ALL_NAMES);
			PRINTLN(Locale::STRING_3_PRINT_ONLY_FOLDERS);
            PRINTLN(Locale::STRING_4_SELECT_ELEMENT);
            PRINTLN(Locale::STRING_5_ADD_ELEMENT);
            PRINTLN(Locale::STRING_6_DELETE_ELEMENT);
            PRINTLN(Locale::STRING_0_GO_BACK);

            std::cin >> ans;

            std::string answ = "";
            int x = 0;
            std::string y = "";
            ObjectTypes::ObjectType type = ObjectTypes::NullType;
            switch (ans)
            {
            case 1:
				CONSOLE_CLEAR();
                PrintFull();
                std::cout << '\n';
                break;
            case 2:
                CONSOLE_CLEAR();
                Print();
                std::cout << '\n';
                break;
            case 3:
                CONSOLE_CLEAR();
                PrintFolders();
                std::cout << '\n';
                break;
            case 4:
                CONSOLE_CLEAR();
                std::cout << '\n';
                Print(-1);
                std::cout << '\n';
                
				PRINTLN(Locale::STRING_ENTER_ELEMENTS_INDEX);
                
                std::cin >> answ;
                
                if (answ == "/")
                {
                    CONSOLE_CLEAR();
                    break;
                }
                
                x = std::stoi(answ);
                if (x >= Size() || x < 0)
                {
                    CONSOLE_CLEAR();
                    PRINTLN(Locale::STRING_INCORRECT_INDEX);
                    break;
                }
                type = CheckType(x);
                switch (type)
                {
                case ObjectTypes::NullType:
                    CONSOLE_CLEAR();
                    PRINTLN(Locale::STRING_INCORRECT_ELEMENT_TYPE);
                    break;
                case ObjectTypes::Folder:
                    CONSOLE_CLEAR();
                    y = FromPositionFolder(x)->Select("");
                    break;
                default:
                    CONSOLE_CLEAR();
                    y = m_head->operator[](x)->Select("");
                    
                    break;
                }
                if (y != "")
                    z = z + "4("+ answ + "," + y + ")";
                break;
            case 5:
                CONSOLE_CLEAR();
                z = z + "5(" + CreateElement("") + ")";
                break;
            case 6:
                std::cout << '\n';
                Print(-1);
                PRINTLN(Locale::STRING_ENTER_ELEMENTS_INDEX);

                std::cin >> answ;

                if (answ == "/")
                {
                    CONSOLE_CLEAR();
                    break;
                }

                x = std::stoi(answ);
                if (x >= Size() || x < 0)
                {
                    CONSOLE_CLEAR();
                    PRINTLN(Locale::STRING_INCORRECT_INDEX);
                    break;
                }

                DeleteFromPosition(x);

                z = z + "6(" + std::to_string(x) + ")";

                break;
            case 0:
                CONSOLE_CLEAR();
                std::cout << z << std::endl;
                return z;
            default:
                break;
            }
        }
    }
    else
    {
        int leftCounter = 0;
        int rightCounter = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                if (leftCounter == 0)
                    start = i;
                leftCounter++;
            }
            else if (s[i] == ')')
            {
                rightCounter++;
            }
            if (leftCounter == rightCounter && leftCounter != 0)
            {
                leftCounter = 0;
                rightCounter = 0;
                end = i;
                int ed = s.find(',', start);
                std::string st1 = "";
                std::string st2 = "";
                ObjectTypes::ObjectType type = ObjectTypes::NullType;
                if(ed - 1 - start>0)
                    st1 = s.substr(start + 1, ed - 1 - start);
                if(end - 1 - start>0)
                    st2 = s.substr(start + 1, end - 1 - start);
                if (st1 != "")
                    type = CheckType(std::stoi(st1));
                else
                    continue;
                switch (s[start - 1])
                {
                case '4':
                    switch (type)
                    {
                    case ObjectTypes::NullType:
						CONSOLE_CLEAR();
                        PRINTLN(Locale::STRING_INCORRECT_ELEMENT_TYPE);
                        break;
                    case ObjectTypes::Folder:
                        CONSOLE_CLEAR();
                        FromPositionFolder(std::stoi(st1))->Select(s.substr(ed + 1, end - 1 - ed));
                        break;
                    default:
                        CONSOLE_CLEAR();
                        FromPosition(std::stoi(st1))->Select(s.substr(ed + 1, end - 1 - ed));
                        break;
                    }
                    break;
                case '5':
                    CreateElement(st2);
                    break;
                case '6':
                    DeleteFromPosition(std::stoi(st2));
                    break;
                default:
                    
                    break;
                }
            }
        }
    }
    return z;
}

std::string Folder::Edit(const std::string& s)
{
    return std::string("");
}

std::string Folder::Find(const std::string& s)
{
    std::shared_ptr<LP> name = std::make_shared<LP>(s,"","");
    std::string z = "";
    if (!m_head) return std::string("");
    std::shared_ptr<Node> temp = m_head;
    for (int i = 0; i < Size(); i++)
    {
        if (CheckType(i) == ObjectTypes::Folder)
        {
            std::string y = temp->folder->Find(s);
            if (y != "")
            {
                z = z + "4(" + std::to_string(i) + "," + y + ")";
                return z;
            }
        }
        else
        {
            if (temp->data->operator==(*name))
            {
                std::string y = temp->data->Select("");
                if (y != "")
                {
                    z = z + "4(" + std::to_string(i) + "," + y + ")";
                    return z;
                }
            }
        }
        temp = temp->next;
    }

    return std::string("");
}

LP::LP()
{
    std::string ans = "";
    for (;;)
    {
        PRINTLN(Locale::STRING_ENTER_ELEMENTS_NAME);
        std::cin >> ans;
        if (ans != "")
            break;
    }
    SetName(ans);
    PRINTLN(Locale::STRING_ENTER_ELEMENTS_LOGIN);
    std::cin >> ans;
    m_login = ans;
    PRINTLN(Locale::STRING_ENTER_ELEMENTS_PASSWORD);
    std::cin >> ans;
    m_pass = ans;
    SetType(ObjectTypes::LP);
}

LP::LP(std::string login, std::string pass)
    : m_login(login), m_pass(pass) {
    SetName("LP"); SetType(ObjectTypes::LP);
}

LP::LP(std::string name, std::string login, std::string pass)
    : m_login(login), m_pass(pass) {
    SetName(name); SetType(ObjectTypes::LP);
}

void LP::PrintFull(int spaces)
{
    int holdSpaces = spaces;
    while (spaces) { std::cout << "  "; spaces--; }
    std::cout << GetName() << " ";
    std::cout << std::endl;

    spaces = holdSpaces;
    while (spaces) { std::cout << "  "; spaces--; }
    std::cout << "|L:" << m_login << std::endl;

    spaces = holdSpaces;
    while (spaces) { std::cout << "  "; spaces--; }
    std::cout << "|P:" << m_pass << std::endl;
}

std::string LP::Edit(const std::string& s)
{
    int comas = 2;
    std::string z = "";
    if (s == "")
    {
        std::string segment = "";
        std::string prz = ",";
		PRINTLN(Locale::STRING_ENTER_ELEMENTS_NEW_NAME);
        std::cin >> z;
        if (segment == "/")
            segment = "";
		PRINTLN(Locale::STRING_ENTER_ELEMENTS_NEW_LOGIN);
        std::cin >> segment;
        if (segment == "/")
            segment = "";
        z.append(prz);
        z.append(segment);
        segment = "";
		PRINTLN(Locale::STRING_ENTER_ELEMENTS_NEW_PASSWORD);
        std::cin >> segment;
        if (segment == "/")
            segment = "";
        z.append(prz);
        z.append(segment);
    }
    else
    {
        z = s;
    }
    int comaCount = 0;
    for (size_t i = 0; i < z.length(); i++)
    {
        if (z[i] == ',')
            comaCount++;
    }
    if (comaCount != comas)
    {
		PRINTLN(Locale::STRING_SYNTAX_ERROR_WHILE_TRYING_TO_EDIT_LP);
        return std::string("");
    }

    std::string line = "";
    int j = 0;
    int i = z.length() - 1;
    while (i >= 0)
    {
        if (z[i] != ',')
            line = z[i] + line;
        if (z[i] == ',' || i == 0)
        {
            switch (j)
            {
            case 0:
                if (line != "")
                    m_pass = line;
                break;
            case 1:
                if (line != "")
                    m_login = line;
                break;
            case 2:
                if (line != "")
                    SetName(line);
                break;
            default:
                break;
            }
            line = "";
            j++;
        }
        i--;
    }
	CONSOLE_CLEAR();
	PRINTLN(Locale::STRING_SUCCESSFULLY_EDITED_LP);
    return z;
}

std::string LP::Select(const std::string& s)
{
    std::string z = "";
    if (s == "")
    {
        bool cont = true;
        while (cont)
        {
            int ans = 5;
			PRINTLN(Locale::STRING_MENU);
            PRINTLN(Locale::STRING_1_PRINT_CONENTS);
            PRINTLN(Locale::STRING_2_EDIT);
            PRINTLN(Locale::STRING_0_GO_BACK);
            std::cin >> ans;
            switch (ans)
            {
            case 1:
				CONSOLE_CLEAR();
                PrintFull();
                std::cout << '\n';
                break;
            case 2:
                CONSOLE_CLEAR();
                z = z + "2(" + Edit("") + ")";
                break;
            case 0:
                CONSOLE_CLEAR();
                std::cout << z << std::endl;
                return z;
            default:
                break;
            }
        }
    }
    else
    {
        Edit(s.substr(2, s.length() - 3));
    }
    return z;
}

std::string Folder::CreationMenu()
{
	std::string answer = "";
    PRINTLN(Locale::STRING_ENTER_ELEMENTS_NAME);
    std::cin >> answer;
    if (answer == "/")
		return std::string("");
    else
        return std::string(answer);
}

std::string LP::CreationMenu()
{
    std::string ans = "";
    std::string seg = "";
	PRINTLN(Locale::STRING_ENTER_ELEMENTS_NAME);
    std::cin >> ans;
	PRINTLN(Locale::STRING_ENTER_ELEMENTS_LOGIN);
    std::cin >> seg;
    ans = ans + "," + seg;
	PRINTLN(Locale::STRING_ENTER_ELEMENTS_PASSWORD);
    std::cin >> seg;
    ans = ans + "," + seg;
    return ans;
}

int Folder::Node::Size()
{
    if (next != nullptr)
        return 1 + next->Size();
    else
        return 1;
    
}
