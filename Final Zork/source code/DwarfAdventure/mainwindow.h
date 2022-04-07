#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <iterator>
#include <QPixmap>
#include <vector>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define MAX_WORDS 503

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

    void on_itemSelector_editingFinished();

    void on_buyButton_clicked();

    void on_sellButton_clicked();

    void on_collectButton_clicked();

    void on_mineButton_clicked();

    void on_wordleEdit_editingFinished();

    void on_teleportButton_clicked();

    void on_tradeButton_clicked();

private:
    Ui::MainWindow *ui;
    Game* game;

    QPushButton* north;
    QPushButton* east;
    QPushButton* souh;
    QPushButton* west;
    QPushButton* teleportButton;
    QPushButton* tradeButton;
    QPushButton* buyButton;
    QPushButton* sellButton;
    QPushButton* collectButton;
    QPushButton* mineButton;
    QLabel* mainLabel;
    QLabel* mapLabel;
    QLabel* captionLabel;
    QLabel* inventoryLabel;
    QLabel* moneyLabel;
    QLabel* shopLabel;
    QLabel* itemLabel;
    QLabel* actionLabel;
    QLabel* wordleLabel;
    QLabel* aLabel;
    QLabel* bLabel;
    QLabel* cLabel;
    QLabel* dLabel;
    QLabel* eLabel;
    QLabel* fLabel;
    QLabel* gLabel;
    QLabel* hLabel;
    QLineEdit* itemSelector;
    QLineEdit* wordleEdit;
    vector<QLabel*> letters;

    string inventory;
    string money;
    string shop;
    string itemSelection;
    string solution;
    int collectCoolDown;
    int trades;

    void InitPrint();
    bool InitSolution();
    void PrintMap();
    void UpdateInventory();
    void UpdateMoney();
    void UpdateRoom();
    void UpdatePrint();
    void SetBackground(QLabel* label);
    void InitLetters();
    string VectorToString(vector<QLabel*> word);
};
#endif // MAINWINDOW_H
