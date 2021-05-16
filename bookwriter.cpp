#include "bookwriter.h"
#include <QTextStream>
#include <QFile>

BookWriter::BookWriter() : BookWriter("")
{}

BookWriter::BookWriter(QString fn) : fileName(fn)
{}

bool BookWriter::saveBook(Book &b)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream fout(&file);
        QString outBook = QString("{title: %1, authors: %2, ISBN: %3, Publication Date: %4}\n")
                .arg(b.getTitle(),
                     "{"+b.getAuthors().join(", ")+"}",
                     b.getIsbn(),
                     b.getPublicationDate().toString(Qt::ISODate));
        fout << outBook;
        file.close();
        return true;
    }
    return false;
}
