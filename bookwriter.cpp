#include "bookwriter.h"
#include <QTextStream>
#include <QFile>

BookWriter::BookWriter(Book *b) : book(b)
{}

bool BookWriter::saveBook(QString fn)
{
    QFile file(fn);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QTextStream fout(&file);
    const QMetaObject *metaObject = book->metaObject();
    for(int i = 1; i < metaObject->propertyCount(); i++) { //start at 1 to skip objectName property
        QString propertyName = QString(metaObject->property(i).name());
        QVariant propertyValue = metaObject->property(i).read(book);
        if (propertyValue.type() == QVariant::StringList)
            propertyValue = propertyValue.toStringList().join(", "); //parse stringLists to strings
        fout << QString("%1: %2\n").arg(propertyName, propertyValue.toString());
    }
    file.close();
    return true;

}
