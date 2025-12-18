#include <iostream>
#include "specification.h"
using namespace std;

// article implementation

article :: article()
{
    title = "";
    category = "";
    description = "";
    publish_month = 0;
    publish_day = 0;
    rating = 0;
    id = 0;
    next = nullptr;
}

article :: article(string title, string category, string description, string author,int publish_month, int publish_day, int rating, int id, article* next)
{
    this->title = title;
    this->category = category;
    this->description = description;
    this->author = author;
    this->publish_month = publish_month;
    this->publish_day = publish_day;
    this->rating = rating;
    this->id = id;
    this->next = next;
}

newsCategory :: newsCategory()
{
    category = "";
    head = nullptr;
    tail = nullptr;
    numberOfArticles = 0;
}

newsCategory ::~newsCategory()
{
    article* temp = head;
    article* nextArticle;

    while (temp != nullptr)
    {
        nextArticle = temp->next;
        delete temp;
        temp = nextArticle;
    }
    head = nullptr;
    tail = nullptr;
    numberOfArticles = 0;
}


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

admin :: admin()
{
    idsCounter = 0;
}

admin ::admin(string userName, string password, string type, user* next, user* prev) : user(userName, password, type, next, prev)
{
    
}

int admin :: idGenerator()
{
    return ++idsCounter;
}





// 555555
// it's so lonely here
// it's so quiet
// it's so over