#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = new Game();
    InitPrint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintMap()
{
    QPixmap pixmap("C:/Users/maxen/Desktop/Event-Driven Programming/DwarfAdventure/Images/map");
    ui->mapLabel->setPixmap(pixmap);
    ui->mapLabel->setScaledContents(true);
    string caption = "\tCaption :";
    int count = 1;
    for (Room room : game->GetRoomList())
    {
        caption += '\n' + to_string(count) + "- " + room.GetName();
        count++;
    }
    ui->captionLabel->setText(QString::fromStdString(caption));
}

void MainWindow::InitLetters()
{
    letters.push_back(ui->aLabel);
    letters.push_back(ui->bLabel);
    letters.push_back(ui->cLabel);
    letters.push_back(ui->dLabel);
    letters.push_back(ui->eLabel);
    letters.push_back(ui->fLabel);
    letters.push_back(ui->gLabel);
    letters.push_back(ui->hLabel);
}

void MainWindow::InitPrint()
{
    shop = "\tSHOP :\n";
    for (string item : game->GetShopList())
    {
        if (game->prices[item] > 0)
        {
            shop += ' ' + item + " : " + to_string(game->prices[item]) + " coins\n";
        }
    }
    shop.pop_back();
    ui->shopLabel->setText(QString::fromStdString(shop));
    SetBackground(ui->mainLabel);
    ui->mainLabel->setAlignment(Qt::AlignCenter);
    ui->wordleLabel->setAlignment(Qt::AlignCenter);
    ui->actionLabel->setAlignment(Qt::AlignCenter);;
    ui->itemLabel->setAlignment(Qt::AlignCenter);
    ui->moneyLabel->setAlignment(Qt::AlignCenter);
    ui->wordleLabel->setText(QString::fromStdString("Wordle game :"));
    SetBackground(ui->inventoryLabel);
    //SetBackground(ui->moneyLabel);
    SetBackground(ui->shopLabel);
    PrintMap();
    UpdatePrint();
    UpdateRoom();
    collectCoolDown = 0;
    trades = 3;
    InitLetters();
    for (QLabel* label : letters)
    {
        label->setAlignment(Qt::AlignCenter);
        label->setText(QString::fromStdString("?"));
    }
    InitSolution();
}

void MainWindow::UpdateInventory()
{
    inventory = "\tINVENTORY :\n";
    map<string, int>::iterator i = game->inventory.begin();
    while (i != game->inventory.end())
    {
        inventory += ' ' + i->first + " : " + to_string(i->second) + '\n';
        i++;
    }
    inventory.pop_back();
    ui->inventoryLabel->setText(QString::fromStdString(inventory));
}

void MainWindow::UpdateMoney()
{
    money = " You have " + to_string(game->GetMoney()) + " coins";
    ui->moneyLabel->setText(QString::fromStdString(money));
}

void MainWindow::UpdateRoom()
{
    collectCoolDown--;
    ui->mainLabel->setText(QString::fromStdString(game->GetCurrentRoom()->GetDescription()));
}

void MainWindow::UpdatePrint()
{
    UpdateInventory();
    UpdateMoney();
}

void MainWindow::SetBackground(QLabel* label)
{
    QPalette palette = QPalette();
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush);
    label->setPalette(palette);
    label->setAutoFillBackground(true);
}

string MainWindow::VectorToString(vector<QLabel*> vector)
{
    string word = "";
    for (QLabel* letter : vector)
    {
        word += letter->text().toStdString();
    }
    return word;
}

bool MainWindow::InitSolution()
{
    int random = rand() % MAX_WORDS;
    string filename("C:/Users/maxen/Desktop/Event-Driven Programming/DwarfAdventure/list_of_words");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    solution = lines.at(random);

    input_file.close();
    return EXIT_SUCCESS;
}


void MainWindow::on_north_clicked()
{
    game->GoTo("north");
    UpdateRoom();
    UpdatePrint();
}


void MainWindow::on_east_clicked()
{
    game->GoTo("east");
    UpdateRoom();
    UpdatePrint();
}


void MainWindow::on_south_clicked()
{
    game->GoTo("south");
    UpdateRoom();
    UpdatePrint();
}


void MainWindow::on_west_clicked()
{
    game->GoTo("west");
    UpdateRoom();
    UpdatePrint();
}


void MainWindow::on_itemSelector_editingFinished()
{
    itemSelection = ui->itemSelector->text().toStdString();
    map<string, int>::iterator i = game->inventory.begin();
    while (i != game->inventory.end() && ui->itemSelector->text() != "")
    {
        if (itemSelection == i->first)
        {
            ui->itemLabel->setText(QString::fromStdString("Item selected : " + itemSelection));
            ui->itemSelector->setText(QString::fromStdString(""));
        }
        i++;
    }
    if (ui->itemSelector->text() != "")
    {
        ui->itemLabel->setText(QString::fromStdString("No item selected"));
    }
    ui->itemSelector->setText(QString::fromStdString(""));
    UpdatePrint();
}


void MainWindow::on_buyButton_clicked()
{
    if (itemSelection == "")
        ui->actionLabel->setText(QString::fromStdString("You need to choose an item to buy"));
    else
    {
        if (game->BuyItem(game->ToItem(itemSelection)))
            ui->actionLabel->setText(QString::fromStdString("You bought " + itemSelection));
        else
            ui->actionLabel->setText(QString::fromStdString("You can't buy " + itemSelection));
    }
    UpdatePrint();
}


void MainWindow::on_sellButton_clicked()
{
    if (itemSelection == "")
        ui->actionLabel->setText(QString::fromStdString("You need to choose an item to sell"));
    else
    {
        if (game->SellItem(game->ToItem(itemSelection)))
            ui->actionLabel->setText(QString::fromStdString("You sold " + itemSelection));
        else
            ui->actionLabel->setText(QString::fromStdString("You can't sell " + itemSelection));
    }
    UpdatePrint();
}


void MainWindow::on_collectButton_clicked()
{
    if (collectCoolDown <= 0)
    {
        if (game->Collect())
        {
            collectCoolDown = 4;
            ui->actionLabel->setText(QString::fromStdString("You collected resources"));
        }
        else
            ui->actionLabel->setText(QString::fromStdString("There is nothing to collect here"));
    }
    else
        ui->actionLabel->setText(QString::fromStdString("No more resources available, come again later"));
    UpdatePrint();
}


void MainWindow::on_mineButton_clicked()
{
    if (collectCoolDown <= 0)
    {
        if (game->inventory["Pickaxe"] > 0)
        {
            if (game->Mine())
            {
                collectCoolDown = 4;
                ui->actionLabel->setText(QString::fromStdString("You collected minerals"));
            }
            else
                ui->actionLabel->setText(QString::fromStdString("There is nothing to mine here"));
        }
        else
            ui->actionLabel->setText(QString::fromStdString("You need a pickaxe to mine minerals"));
    }
    else
        ui->actionLabel->setText(QString::fromStdString("No more minerals available, come again later"));
    UpdatePrint();
}


void MainWindow::on_wordleEdit_editingFinished()
{
    string word = ui->wordleEdit->text().toStdString();
    if (word.length() == 8)
    {
        for (size_t i = 0; i < 8; i++)
        {
            if (word[i] == solution[i])
            {
                string letter(1, word[i]);
                letters[i]->setText(QString::fromStdString(letter));
            }
        }
    }
    if (solution == VectorToString(letters))
        game->conditions["Big diamond room"] = true;
    UpdatePrint();
}


void MainWindow::on_teleportButton_clicked()
{
    if (game->Teleport())
        ui->actionLabel->setText(QString::fromStdString("You went back at spawn"));
    else
        ui->actionLabel->setText(QString::fromStdString("You need a runaway powder unit to teleport"));
    UpdateRoom();
    UpdatePrint();
}


void MainWindow::on_tradeButton_clicked()
{
    string room = game->GetCurrentRoom()->GetName();
    if (room == "Chief's hut" || room == "Dwarf village center" || room == "Fishermen's hut")
    {
        if (trades > 0)
        {
            if (game->Trade())
            {
                int hint = rand() % 8;
                trades--;
                string letter(1, solution[hint]);
                letters[hint]->setText(QString::fromStdString(letter));
                ui->actionLabel->setText(QString::fromStdString("You received a hint, you may already have it"));
            }
            else
                ui->actionLabel->setText(QString::fromStdString("You don't have the necessary resources\nfor the trade"));
        }
    }
    else if (room == "Forge")
    {
        if (game->Forge())
            ui->actionLabel->setText(QString::fromStdString("You crafted a key"));
        else
            ui->actionLabel->setText(QString::fromStdString("You don't have enough materials"));
    }
    else if (room == "Treasure room")
    {
        if (game->OpenChest())
            ui->actionLabel->setText(QString::fromStdString("You opened the chest and found a sacred scroll"));
        else
            ui->actionLabel->setText(QString::fromStdString("You need a key to open this chest"));
    }
    else if (room == "Ancient dwarf statue")
    {
        if (game->ToWin())
            ui->actionLabel->setText(QString::fromStdString("GOOD JOB !!! U WON THIS GAME !!!"));
        else
            ui->actionLabel->setText(QString::fromStdString("Maybe some rare items are very useful here..."));
    }
    else
        ui->actionLabel->setText(QString::fromStdString("Nothing happened..."));
    UpdatePrint();
}

