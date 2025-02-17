#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    state = 1;
    number1 = "";
    number2 = "";

    //Yhdistetään numeronäppäimet
    QList<QPushButton*> numButtons = {ui->N0, ui->N1, ui->N2, ui->N3, ui->N4, ui->N5, ui->N6, ui->N7, ui->N8, ui->N9};
    for (QPushButton* button : numButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    }

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::operationClickHandler);

    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::calculate);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    qDebug() << "Button pressed:" << button->text();

    if (state == 1) {
        number1 += button->text();
        ui->num1->setText(number1);
    } else {
        number2 += button->text();
        ui->num2->setText(number2);
    }

    qDebug() << "Number1: " << number1 << ", Number2: " << number2;
}

void MainWindow::operationClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->add) operand = 0;
    else if (button == ui->sub) operand = 1;
    else if (button == ui->mul) operand = 2;
    else if (button == ui->div) operand = 3;

    state = 2; // Vaihda num2-kenttään
}

void MainWindow::clear()
{
    number1 = "";
    number2 = "";
    state = 1;
    operand = -1;
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

void MainWindow::calculate()
{
    if (number1.isEmpty() || number2.isEmpty() || operand == -1) return;

    float num1_f = number1.toFloat();
    float num2_f = number2.toFloat();
    float result_f = 0;

    switch (operand) {
    case 0: result_f = num1_f + num2_f; break;
    case 1: result_f = num1_f - num2_f; break;
    case 2: result_f = num1_f * num2_f; break;
    case 3: result_f = (num2_f != 0) ? num1_f / num2_f : 0; break;
    }

    ui->result->setText(QString::number(result_f));
}
