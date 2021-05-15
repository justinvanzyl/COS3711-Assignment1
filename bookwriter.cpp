#include "bookwriter.h"

BookWriter::BookWriter() : BookWriter(".\\")
{}

BookWriter::BookWriter(QString p) : path(p)
{}

void BookWriter::saveBook(Book &b)
{
    QFile file(path);
    file << b.toString();
}
