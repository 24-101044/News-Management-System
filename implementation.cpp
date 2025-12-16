#include <iostream>
#include "specification.h"
using namespace std;

// article implementation

article :: article()
{
    title = "";
    category = "";
    description = "";
    publishDate = "";
    rating = 0;
    id = 0;
    next = nullptr;
}

article :: article(string t, string c, string d, string pD, string a, int r, int i)
{
    title = t;
    category = c;
    description = d;
    publishDate = pD;
    rating = r;
    id = i;
    next = nullptr;
}

articleList :: articleList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

articleList ::~articleList()
{
    article* current = head;
    article* nextArticle;

    while (current != nullptr)
    {
        nextArticle = current->next;
        delete current;
        current = nextArticle;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// user implementation

user ::user()
{
    userName = "";
    password = "";
    type = "";
    next = nullptr;
    prev = nullptr;
}

user :: user(string userName, string password , string type, user *next, user *prev)
{
    this->userName = userName;
    this->password = password;
    this->type = type;
    this->next = next;
    this->prev = prev;
}

string user :: getUserName()
{
    return userName;
}

string user :: getPassword()
{
    return password;
}

string user :: getType()
{
    return type;
}

// admin implementation

admin ::admin(string u, string p, string t, user* next, user* prev) : user(u, p, t, next, prev)
{
    
}

// customers implementation

customers ::customers(string u, string p, string t) : user(u, p, t, nullptr, nullptr)
{
    
}

void customers :: displayCategoryNews(string Categoryname, articleList* news)
{
    article* current = news->head;
    while (current)
    {
        if (current->category == Categoryname)
        {
            cout << "\t\t\t\t" << current->title << endl
            << "\t\t\t\t" << current->description << endl
            << current->author << " | " << current->publishDate << " | " << current->rating << endl
            << "----------------------------------------" << endl;
        }
        current = current->next;
    }
}