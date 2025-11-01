#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o train com seu (ID, posição X, posição Y)
    train1 = new Train(1,95,50);
    train2 = new Train(2,365,50);
    train3 = new Train(3,635,50);
    train4 = new Train(4,95,180);
    train5 = new Train(5,500,180);
    train6 = new Train(6,95,310);

    train1->start();
    train2->start();
    train3->start();
    train4->start();
    train5->start();

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Train1 e Train2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(train1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(train2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(train3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(train4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(train5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(train6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o train1
        ui->label_trem1->setGeometry(x,y,20,20);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o train2
        ui->label_trem2->setGeometry(x,y,20,20);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o train3
        ui->label_trem3->setGeometry(x,y,20,20);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o train4
        ui->label_trem4->setGeometry(x,y,20,20);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o train5
        ui->label_trem5->setGeometry(x,y,20,20);
        break;
    // case 6: //Atualiza a posição do objeto da tela (quadrado) que representa o train5
    //     ui->label_trem6->setGeometry(x,y,20,20);
    //     break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_1_valueChanged(int value)
{
    if (value == 0)
        train1->setStopped(true);
    else {
        train1->setStopped(false);
        train1->setSleep(99 - value);
    }
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (value == 0)
        train2->setStopped(true);
    else {
        train2->setStopped(false);
        train2->setSleep(99 - value);
    }
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    if (value == 0)
        train3->setStopped(true);
    else {
        train3->setStopped(false);
        train3->setSleep(99 - value);
    }
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    if (value == 0)
        train4->setStopped(true);
    else {
        train4->setStopped(false);
        train4->setSleep(99 - value);
    }
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    if (value == 0)
        train5->setStopped(true);
    else {
        train5->setStopped(false);
        train5->setSleep(99 - value);
    }
}

void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    if (value == 0)
        train6->setStopped(true);
    else {
        train6->setStopped(false);
        train6->setSleep(99 - value);
    }
}
