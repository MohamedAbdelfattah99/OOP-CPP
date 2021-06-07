#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include<cstring>
#include "User.h"

using namespace std;
class Book
{
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating=0;
    User author;
    int numofratings=0; ///To Store the count of rates of every book
public:
    static int count;
    Book();
    double getAva();
    Book(string title, string isbn, string category);
    Book(const Book& book);
    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setId(int id);
    int getId();
    void setCategory(string category);
    string getCategory();
    void setAuthor(User user);
    User getAuthor();
    void rateBook(int rating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output, const Book &book );
    friend istream &operator>>( istream &input, Book &book );

    void print();

};

#endif // BOOK_H
