#ifndef TREM_H
#define TREM_H

#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Train: public QThread{
    Q_OBJECT
public:
    Train(int,int,int); //construtor
    void setSleep(int); //função a ser executada pela thread
    void setStopped(bool);
    void run(); //função a ser executada pela thread

    //Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
    int x;           //posição X do train na tela
    int y;           //posição Y do train na tela
    int size_movement = 5;
    int ID;          //ID do train
    int sleep;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do train
    bool stopped;

    void move();
};

#endif // TREM_H
