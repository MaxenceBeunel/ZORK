#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_north_clicked();

    void on_east_clicked();

    void on_south_clicked();

    void on_west_clicked();

private:
    Ui::MainWindow *ui;
    Game* game;

    QPushButton* north;
    QPushButton* east;
    QPushButton* souh;
    QPushButton* west;
};
#endif // MAINWINDOW_H
