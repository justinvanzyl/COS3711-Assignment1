#include "bookinput.h"
#include "ui_bookinput.h"
#include <QMessageBox>


bookInput::bookInput(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bookInput::~bookInput()
{
    delete ui;
}


void bookInput::on_buttonBox_accepted()
{
    QString inTitle = ui->title_in->text();
    QStringList inAuthors = ui->authors_in->document()->toPlainText().split("\n");
    QString inIsbn = ui->isbn_in->text();
    QDate inPubDate = ui->pubDate_in->date();

    if(inTitle=="" || inAuthors[0]=="" || inIsbn=="")
        QMessageBox::critical(0,"Error","Please enter a valid book");
    else {
        QMessageBox msgConfirm;
        msgConfirm.setText("Are you sure you want to save this book?");
        msgConfirm.setInformativeText("Click 'Show Details...' to view book information");
        msgConfirm.setDetailedText("\nTitle: " + inTitle +
                                   "\nAuthor(s): " + inAuthors.join(", ") +
                                   "\nISBN: " + inIsbn +
                                   "\nDate Published: " + inPubDate.toString(Qt::ISODate));
        msgConfirm.setStandardButtons(QMessageBox::Save|QMessageBox::Discard);
        msgConfirm.setDefaultButton(QMessageBox::Save);

        if(msgConfirm.exec() == QMessageBox::Save) {
            Book inBook(inTitle, inAuthors, inIsbn, inPubDate);
            BookWriter writer(inTitle + ".txt");
            if (writer.saveBook(inBook))
                QMessageBox::information(0,"File Saved",
                                         "Book has been saved successfully as " + inTitle + ".txt");
            else
                QMessageBox::critical(0,"Error","Book could not be saved");
        }
    }

}

void bookInput::on_buttonBox_rejected()
{
    qApp->quit();
}

