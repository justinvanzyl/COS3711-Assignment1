#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"

class BookWriter {
public:
    BookWriter();
    BookWriter(QString fn);
    bool saveBook(Book &b);

private:
    QString fileName;
};

#endif // BOOKWRITER_H
