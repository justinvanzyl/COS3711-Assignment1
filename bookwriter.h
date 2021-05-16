#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"
#include <QMetaObject>
#include <QMetaProperty>

class BookWriter
{
public:
    BookWriter();
    BookWriter(QString fn);
    bool saveBook(QObject &b);

private:
    QString fileName;
};

#endif // BOOKWRITER_H
