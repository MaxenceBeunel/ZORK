#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_north_clicked()
{
    //game->SetCurrentRoom(game->GetCurrentRoom()->GetNeighbor('n'));
    ui->textEdit->setText("north");
}


void MainWindow::on_east_clicked()
{
    //game->SetCurrentRoom(game->GetCurrentRoom()->GetNeighbor('e'));
    ui->textEdit->setText("east");
}


void MainWindow::on_south_clicked()
{
    //game->SetCurrentRoom(game->GetCurrentRoom()->GetNeighbor('s'));
    ui->textEdit->setText("south");
}


void MainWindow::on_west_clicked()
{
    //game->SetCurrentRoom(game->GetCurrentRoom()->GetNeighbor('w'));
    ui->textEdit->setText("west");
}

