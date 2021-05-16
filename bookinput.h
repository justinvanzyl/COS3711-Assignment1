#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QMainWindow>
#include "book.h"
#include "bookwriter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class bookInput : public QMainWindow
{
    Q_OBJECT

public:
    bookInput(QWidget *parent = nullptr);
    ~bookInput();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::MainWindow *ui;
};
#endif // BOOKINPUT_H
