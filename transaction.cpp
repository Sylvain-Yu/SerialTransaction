#include "transaction.h"
#include "ui_transaction.h"
#include <QtDebug>

Transaction::Transaction(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Transaction)
{
    ui->setupUi(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->comboBox->addItem(info.portName());
    ui->ptxtWrite->setText(QStringLiteral("aba"));
    connect(ui->btnWrite, &QPushButton::clicked, this, &Transaction::startTransaction);
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::startTransaction()
{
    QSerialPort port;
    port.setPortName(ui->comboBox->currentText());
    qDebug()<< "working";
    port.setParity(QSerialPort::NoParity);
    port.setBaudRate(QSerialPort::Baud115200);
    port.setDataBits(QSerialPort::Data8);
    port.setStopBits(QSerialPort::OneStop);
    port.setFlowControl(QSerialPort::NoFlowControl);
    port.open(QIODevice::ReadWrite);
    QString w = ui->ptxtWrite->toPlainText();
    port.write(w.toUtf8());
    port.waitForBytesWritten(1000);
    port.waitForReadyRead(1000);
    QByteArray a = port.readAll();
    while (port.waitForReadyRead(10))
        a += port.readAll();
    const QString response = QString::fromUtf8(a);
    ui->ptxtRead->setText(response);
    port.close();

}
