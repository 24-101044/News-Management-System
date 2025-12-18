#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include <iostream>
using namespace std;

struct article
{
    string title, category, description,author;
    int publish_month, publish_day;
    int rating, id;
    article* next;
    article();
    article(string title, string category, string description, string author,int publish_month, int publish_day, int rating, int id, article* next = nullptr);

};

class newsCategory
{
    
    public:
        string category;
        article *head, *tail;
        int numberOfArticles;
        
        newsCategory();
        ~newsCategory();
        int idGenerator(); 

};

class categories
{
    newsCategory* head;
    newsCategory* tail;
    int numberOfCategories;
    public:
        categories(/* args */);
        ~categories();
};


class most_recent
{
    public: 
        article*head;
        int size;
        most_recent();
        ~most_recent();
        void push(article);
        bool isempty();
        article* top();
        void pop();
        void clear();
};

class user
{
    private:
        string userName, password, type;
        article* bookmarkedHead = nullptr;
        article* bookmarkedTail = nullptr;
    public:
        user* next;
        user* prev;


        user();
        user(string userName, string password , string type, user *next, user *prev);
        string getType();
        string getUserName();
        string getPassword();
        article* searchByTitle(string title);
        article* searchByDate(int date);
        article* searchByKeywords(string words);
        void displayCategoryNews(string categoryName, categories* news);
        void  displayLatestNews(most_recent* allNews);
        void displayTrendingNews();
        void rateNews(int rate, article* news);
        void bookmark(article* news);

};


class admin : public user
{
    public:

        int idsCounter;
        admin();
        admin(string userName, string password, string type, user* next, user* prev);

        int idGenerator(); 
        void addArticle();
        void removeArticle(int id);
        void updateExisting(int id);
        void addCategory(); // Use this when doing my function youssef
        void displayAvgRateForCat(string categoryName, categories* news);

};




#endif