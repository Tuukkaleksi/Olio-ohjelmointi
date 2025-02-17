#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count(0)
{
    ui->setupUi(this);

    ui->lineEditCount->setText(QString::number(count));

    connect(ui->btnCount, &QPushButton::clicked, this, &MainWindow::increaseCount);
    connect(ui->btnReset, &QPushButton::clicked, this, &MainWindow::resetCount);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::increaseCount()
{
    count++;
    ui->lineEditCount->setText(QString::number(count));
}

void MainWindow::resetCount()
{
    count = 0;
    ui->lineEditCount->setText(QString::number(count));
}
