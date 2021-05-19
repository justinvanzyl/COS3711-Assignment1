#include "bookinput.h"
#include "ui_bookinput.h"
#include <QMessageBox>
#include <QInputDialog>


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
    // receive book details:
    QString inTitle = ui->title_in->text();
    QStringList inAuthors = ui->authors_in->document()->toPlainText().split("\n");
    QString inIsbn = ui->isbn_in->text();
    QDate inPubDate = ui->pubDate_in->date();

    //(very) basic error checking:
    if(inTitle=="" || inAuthors[0]=="" || inIsbn=="")
        QMessageBox::critical(0,"Error","Please enter a valid book");
    else {
        //confirm a filename:
        bool save;        
        QString filename = QInputDialog::getText(this, "Save book file", "Filename:",
                                                 QLineEdit::Normal, inTitle, &save);
        if (save && !filename.isEmpty()) {
            filename.append(".txt");

            //create a book object:
            Book inBook;
            inBook.setProperty("title",inTitle);
            inBook.setProperty("authors",inAuthors);
            inBook.setProperty("isbn",inIsbn);
            inBook.setProperty("publicationDate",inPubDate);

            //write the book to a text file:
            BookWriter writer(&inBook);
            if (writer.saveBook(filename))
                QMessageBox::information(0,"File Saved", "Book has been saved as " + filename);
            else
                QMessageBox::critical(0,"Error","Book could not be saved");
        }
    }
}

void bookInput::on_buttonBox_rejected()
{
    qApp->quit();
}

