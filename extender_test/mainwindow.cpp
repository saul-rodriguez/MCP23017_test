#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hardware_conf.h"
#include "mcp23017_isr.h"
#include <wiringPi.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int ret;

    state_B0 = 0;
    state_B1 = 0;

    ui->setupUi(this);

    //Raspberry ports setup (should already
    //be configured using the gpio command)
    wiringPiSetupSys();

    /*******************/
    /* Extender Config */
    /*******************/
    //General config: open descriptor, config I/O, pullups
    ret = myext.open(0x20); //Open MCP23017 at address 0x20
    ret = myext.setTris(PORTA,TRISA); // Set I/O
    ret = myext.setTris(PORTB,TRISB);
    ret = myext.setPullup(PORTA,A_PULLUP); // Set pullup resistors
    ret = myext.setPullup(PORTB,B_PULLUP);

    //Interruption setup and ISR signal/slot connections
    setupMcp23017_isr_ext1(&myext); //Setup and enable interruptions
    connect(&myext, SIGNAL(interrupt_A(quint8)),this,SLOT(int_A(quint8)));
    connect(&myext, SIGNAL(interrupt_B(quint8)),this,SLOT(int_B(quint8)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{
    if (state_B0) {
        LED_B0_OFF;
        state_B0 = 0;
    } else {
        LED_B0_ON;
        state_B0 = 1;
    }
}

void MainWindow::on_pushButton2_clicked()
{
    if (state_B1) {
        LED_B1_OFF;
        state_B1 = 0;
    } else {
        LED_B1_ON;
        state_B1 = 1;
    }
}

void MainWindow::on_pushButton3_clicked()
{

quint16 val;

val = READ_GPA5;

QString text = QString("%1").arg(val);
ui->lineEdit1->setText(text);

}

void MainWindow::int_A(quint8 value)
{
    qDebug("Int in port A, value: %d",value);
}

void MainWindow::int_B(quint8 value)
{
    qDebug("Int in port B, value: %d",value);
}
