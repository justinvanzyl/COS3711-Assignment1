#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>
#include <QDate>

class Book : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QStringList authors READ getAuthors WRITE setAuthors)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn)
    Q_PROPERTY(QDate publicationDate READ getPublicationDate WRITE setPublicationDate)


public:
    Book(); //default constructor
    Book(QString t, QStringList a, QString i, QDate p); //parameterized constructor

    void setTitle(QString t);   //title setter
    void setAuthors(QStringList a); //authors setter
    void setIsbn(QString i);    //ISBN setter
    void setPublicationDate(QDate p);   //publication date setter

    QString getTitle() const;   //title getter
    QStringList getAuthors() const; //authors getter
    QString getIsbn() const;    //ISBN getter
    QDate getPublicationDate() const;   //publication date getter

    void obtainBookInfo();

private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;
};

#endif // BOOK_H
