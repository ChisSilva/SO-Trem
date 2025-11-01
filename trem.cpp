#include "trem.h"
#include <QtCore>
#include <pthread.h>
#include <semaphore.h>

#define N 7

sem_t s[N];

//Construtor
Train::Train(int ID, int x, int y) {
    // for (int i = 0; i < N; i++)
    //     sem_init(&s[i], 0, i == 5 ? 1 : 0);
    sem_init(&s[0], 0, 0);
    sem_init(&s[1], 0, 0);
    sem_init(&s[2], 0, 0);
    sem_init(&s[3], 0, 1);
    sem_init(&s[4], 0, 0);
    sem_init(&s[5], 0, 1);
    sem_init(&s[6], 0, 0);


    this->ID = ID;
    this->x = x;
    this->y = y;
    sleep = 99;
    stopped = true;
}

void Train::setSleep(int value) {
    this->sleep = value;
}

void Train::setStopped(bool value) {
    this->stopped = value;
}

//Função a ser executada após executar Train->START
void Train::run() {
    while(true) {
        if(!stopped) {
            switch(ID) {
            case 1: // Train 1
                if (y == 50 && x < 370) { // DIREITA
                    if (x == 350)
                        sem_wait(&s[0]);

                    x += size_movement;
                } else if (x == 370 && y < 180) { // DESCE
                    if (y == 160)
                        sem_wait(&s[2]);

                    y += size_movement;
                } else if (x > 100 && y == 180) { // ESQUERDA
                    if (x == 380)
                        sem_post(&s[0]);

                    x -= size_movement;
                } else { // SOBE
                    if (y == 160)
                        sem_post(&s[2]);

                    y -= size_movement;
                }
                emit updateGUI(ID, x, y);


                break;
            case 2: // Train 2
                if (y == 50 && x < 640) { // DIREITA
                    if (x == 380)
                        sem_post(&s[0]);

                    if (x == 620) {
                        sem_wait(&s[1]);
                        // sem_wait(&s[4]);
                    }

                    x += size_movement;
                } else if (x == 640 && y < 180) { // DESCE
                    if (y == 160)
                        sem_wait(&s[4]);

                    y += size_movement;
                } else if (x > 370 && y == 180) { // ESQIERDA
                    if (x == 620)
                        sem_post(&s[1]);

                    if (x == 530)
                        sem_wait(&s[3]);

                    if (x == 490)
                        sem_post(&s[4]);

                    if (x == 400)
                        sem_wait(&s[0]);

                    x -= size_movement;
                } else { // SOBE
                    if (y == 160)
                        sem_post(&s[3]);

                    y -= size_movement;
                }
                emit updateGUI(ID, x, y);

                break;
            case 3: // Train 3
                if (y == 50 && x < 910) { // DIREITA
                    if (x == 660)
                        sem_post(&s[1]);

                    x += size_movement;
                } else if (x >= 910 && y < 180) { // DESCE
                    if (y == 160) {
                        sem_wait(&s[5]);
                        // sem_wait(&s[4]);
                        // sem_wait(&s[1]);
                    }

                    y += size_movement;
                }
                else if (x > 640 && y == 180) { // ESQUERDA
                    if (x == 660)
                        sem_wait(&s[1]);

                    x -= size_movement;
                } else { // SOBE
                    if (y == 160)
                        sem_post(&s[5]);

                    y -= size_movement;
                }

                emit updateGUI(ID, x, y);

                break;
            case 4: // Train 4
                if (y == 180 && x < 510) { // DIREITA
                    if (x == 350)
                        sem_wait(&s[3]);

                    if (x == 390)
                        sem_post(&s[2]);

                    if (x == 490)
                        sem_wait(&s[6]);

                    x += size_movement;
                } else if (x == 510 && y < 310) { // DESCE
                    if (y == 200)
                        sem_post(&s[3]);

                    y += size_movement;
                } else if (x > 100 && y == 310) { // ESQUERDA
                    if (x == 480)
                        sem_post(&s[6]);

                    x -= size_movement;
                } else if (x == 100 && y > 180) { // SOBE
                    if (y == 200) {
                        sem_wait(&s[2]);
                    }

                    y -= size_movement;
                }

                emit updateGUI(ID, x, y);

                break;
            case 5: // Train 5
                if (y == 180 && x < 910) {// DIREITA
                    if (x == 520)
                        sem_post(&s[6]);

                    if (x == 620)
                        sem_wait(&s[5]);

                    if (x == 660)
                        sem_post(&s[4]);

                    x += size_movement;
                } else if (x == 910 && y < 310) { // DESCE
                    if (y == 200)
                        sem_post(&s[5]);

                    y += size_movement;
                } else if (x > 510 && y == 310) { // ESQUERDA
                    if (x == 520)
                        sem_wait(&s[6]);

                    x -= size_movement;
                }
                else { // SOBE
                    if (y == 200) {
                        sem_wait(&s[4]);
                        sem_wait(&s[5]);
                    }

                    y -= size_movement;
                }

                emit updateGUI(ID, x, y);

                break;
            case 6: // Train 6
                if (y == 50 && x < 910) { // DIREITA

                    x += size_movement;
                } else if (x == 910 && y > 310) { // SOBE

                    y -= size_movement;
                } else if (y == 50 && x > 100) { // ESQUERDA

                    x -= size_movement;
                }
                else { // DESCE

                    y += size_movement;
                }
                emit updateGUI(ID, x, y);
                break;

            default:
                break;
            }

            msleep(sleep);
        }
    }
}





