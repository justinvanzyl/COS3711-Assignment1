#include "book.h"

Book::Book() : Book("unknown",{},"unknown",QDate(0001,01,01))
{}

Book::Book(QString t, QStringList a, QString i, QDate p)
    : title(t), authors(a), isbn(i), publicationDate(p)
{}

void Book::setTitle(QString t)
{
    title = t;
}

void Book::setAuthors(QStringList a)
{
    authors = a;
}

void Book::setIsbn(QString i)
{
    isbn = i;
}

void Book::setPublicationDate(QDate p)
{
    publicationDate = p;
}

QString Book::getTitle() const
{
    return title;
}

QStringList Book::getAuthors() const
{
    return authors;
}

QString Book::getIsbn() const
{
    return isbn;
}

QDate Book::getPublicationDate() const
{
    return publicationDate;
}

void Book::obtainBookInfo()
{
    //run BookInput
    //serialize!
}

QString Book::toString()
{
    return title + "\t" + authors.join(", ") + "\t" + isbn + "\t" + publicationDate.toString(Qt::ISODate);
}
