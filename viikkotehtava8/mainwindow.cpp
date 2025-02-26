#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , gameTime(0)
    , isPlayer1Turn(true)
{
    ui->setupUi(this);

    // Yhdistetään napit metodeihin
    connect(ui->timeButton120, &QPushButton::clicked, this, &MainWindow::selectTime);
    connect(ui->timeButton300, &QPushButton::clicked, this, &MainWindow::selectTime);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->endButton, &QPushButton::clicked, this, &MainWindow::endGame);
    connect(ui->switchButton1, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(ui->switchButton2, &QPushButton::clicked, this, &MainWindow::switchPlayer);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    ui->infoLabel->setText("Valitse peliaika");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::selectTime() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button == ui->timeButton120) {
        gameTime = 120; // 120 sekuntia
    } else if (button == ui->timeButton300) {
        gameTime = 300; // 5 minuuttia
    }

    player1Time = player2Time = gameTime;
    updateProgressBars();
    setGameInfoText("Peliaika valittu. Paina START GAME aloittaaksesi.", 12);
}

void MainWindow::startGame() {
    isPlayer1Turn = true;
    timer->start(1000); // 1 sekunnin välein päivitys
    setGameInfoText("Pelaaja 1 aloitti.", 12);
}

void MainWindow::switchPlayer() {
    isPlayer1Turn = !isPlayer1Turn;
    setGameInfoText(isPlayer1Turn ? "Pelaaja 1 vuoro." : "Pelaaja 2 vuoro.", 12);
}

void MainWindow::updateTimer() {
    if (isPlayer1Turn && player1Time > 0) player1Time--;
    else if (!isPlayer1Turn && player2Time > 0) player2Time--;

    updateProgressBars();

    if (player1Time == 0 || player2Time == 0) {
        timer->stop();
        setGameInfoText(player1Time == 0 ? "Pelaaja 2 voitti!" : "Pelaaja 1 voitti!", 14);
    }
}

void MainWindow::updateProgressBars() {
    int player1Value = static_cast<int>((double)player1Time / gameTime * 100);
    int player2Value = static_cast<int>((double)player2Time / gameTime * 100);

    ui->player1Bar->setValue(player1Value);
    ui->player2Bar->setValue(player2Value);

    ui->player1Bar->setFormat(QString::number(player1Value) + "%");
    ui->player2Bar->setFormat(QString::number(player2Value) + "%");
}

void MainWindow::setGameInfoText(const QString &text, short fontSize) {
    ui->infoLabel->setText(text);
    QFont font = ui->infoLabel->font();
    font.setPointSize(fontSize);
    ui->infoLabel->setFont(font);
}

void MainWindow::endGame() {
    timer->stop();
    setGameInfoText("Peli lopetettu. Valitse uusi peliaika.", 12);
    player1Time = player2Time = gameTime = 0;
    updateProgressBars();
}
