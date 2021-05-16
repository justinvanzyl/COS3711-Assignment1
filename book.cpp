#include "book.h"

//Default Constructor
Book::Book() : Book("unknown",{},"unknown",QDate(0001,01,01))
{}

//Parameterized Constructor
Book::Book(QString t, QStringList a, QString i, QDate p)
    : title(t), authors(a), isbn(i), publicationDate(p)
{}

//Setter for 'title'
void Book::setTitle(QString t)
{
    title = t;
}

//Setter for 'authors'
void Book::setAuthors(QStringList a)
{
    authors = a;
}

//Setter for 'isbn'
void Book::setIsbn(QString i)
{
    isbn = i;
}

//Setter for 'publicationDate'
void Book::setPublicationDate(QDate p)
{
    publicationDate = p;
}

//getter for 'title'
QString Book::getTitle() const
{
    return title;
}

//getter for 'authors'
QStringList Book::getAuthors() const
{
    return authors;
}

//getter for 'isbn'
QString Book::getIsbn() const
{
    return isbn;
}

//getter for 'publicationDate'
QDate Book::getPublicationDate() const
{
    return publicationDate;
}

void Book::obtainBookInfo()
{
    //run BookInput
    //serialize!
}
