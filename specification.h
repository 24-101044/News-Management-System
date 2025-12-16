#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include <iostream>
using namespace std;

struct article
{
    string title, category, description,publishDate,author;
    int rating, id;
    article* next;
    article();
    article(string t, string c, string d, string pD, string a, int r, int i);

};

class articleList // aka news
{
    
    public:
        article *head, *tail;
        int size;
        
        articleList();
        ~articleList();
        void idGenerator();
};


class user
{
    private:
        string userName, password, type;
    public:
        user* next;
        user* prev;


        user();
        user(string userName, string password , string type, user *next, user *prev);
        string getType();
        string getUserName();
        string getPassword();

};


class admin : public user
{
    public:
  
        admin(string, string, string, user*, user*);

        void postNews(article toAdd);
        void removeNews(int id);
        void updateExisting(int id);
        void addCategory(string categoryName);
        void displayAvgRateForCat(string categoryName);

};

class customers : public user
{
    public:
        customers(string, string, string);

        article* searchByTitle(string title);
        article* searchByDate(int date);
        article* searchByKeywords(string words);
        void displayCategoryNews(string Categoryname, articleList* news);
        void  displayLatestNews();
        void displayTrendingNews();
        void rateNews();
        void bookmark();

};


#endif