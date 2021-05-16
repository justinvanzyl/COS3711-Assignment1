#include "bookwriter.h"
#include <QTextStream>
#include <QFile>

BookWriter::BookWriter() : BookWriter("")
{}

BookWriter::BookWriter(QString fn) : fileName(fn)
{}

bool BookWriter::saveBook(QObject &b)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QTextStream fout(&file);
    const QMetaObject *metaObject = b.metaObject();
    for(int i = 1; i < metaObject->propertyCount(); i++) { //start at 1 to skip objectName property
        QString propertyName = QString(metaObject->property(i).name());
        QVariant propertyValue = metaObject->property(i).read(&b);
        if (propertyValue.type() == QVariant::StringList)
            propertyValue = propertyValue.toStringList().join(", ");
        fout << QString("%1: %2\n").arg(propertyName, propertyValue.toString());
    }
    file.close();
    return true;

}
