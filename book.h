#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDate>

class Book
{
public:
    Book();
    Book(QString t, QStringList a, QString i, QDate p);

    void setTitle(QString t);
    void setAuthors(QStringList a);
    void setIsbn(QString i);
    void setPublicationDate(QDate p);

    QString getTitle() const;
    QStringList getAuthors() const;
    QString getIsbn() const;
    QDate getPublicationDate() const;

    void obtainBookInfo();
    QString toString();

private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;
};

#endif // BOOK_H
