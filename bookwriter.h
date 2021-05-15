#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"
#include <QFile>

class BookWriter {
public:
    BookWriter();
    BookWriter(QString f);
    void saveBook(Book &b);

private:
    QString path;
};

#endif // BOOKWRITER_H
