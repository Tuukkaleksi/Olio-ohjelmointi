#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectTime();
    void startGame();
    void switchPlayer();
    void updateTimer();
    void endGame();

private:
    void updateProgressBars();
    void setGameInfoText(const QString &text, short fontSize);

    QPushButton *timeButton120, *timeButton300, *startButton, *switchButton1, *switchButton2, *endButton;
    QProgressBar *player1Bar, *player2Bar;
    QLabel *infoLabel;
    QTimer *timer;

    int player1Time, player2Time, gameTime;
    bool isPlayer1Turn;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
