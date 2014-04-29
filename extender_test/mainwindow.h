#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mcp23017.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    Mcp23017 myext;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void int_A(quint8 value);
    void int_B(quint8 value);

private:
    Ui::MainWindow *ui;

    quint16 state_B0;
    quint16 state_B1;

};

#endif // MAINWINDOW_H
