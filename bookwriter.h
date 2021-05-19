#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"
#include <QMetaObject>
#include <QMetaProperty>

class BookWriter
{
public:
    BookWriter(Book *b);
    bool saveBook(QString fn);

private:
    Book *book;
};

#endif // BOOKWRITER_H
