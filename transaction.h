#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class Transaction; }
QT_END_NAMESPACE

class Transaction : public QMainWindow
{
    Q_OBJECT

public:
    Transaction(QWidget *parent = nullptr);
    ~Transaction();

    void startTransaction();

private:
    Ui::Transaction *ui;
};
#endif // TRANSACTION_H
