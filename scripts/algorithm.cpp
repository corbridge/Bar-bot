int contador = 0;
int contadorAnt = 0;

int up = 20;
int mid = 25;
int down = 30;

int maxUp = 50;
int maxMid = 55;
int maxDown = 60;

int minUp = 20;
int minMid = 25;
int minDown = 30;

contador = encoder();

if(contador > contadorAnt){
    up += 10;
    mid += 10;
    down += 10;
}else if(contador < contadorAnt){
    up -= 10;
    mid -= 10;
    down -= 10;
}

contadorAnt = contador;

if(up > upMax){
    up = minUp;
    mid = minMid;
    down = minDown;
}else if(up < upMin){
    up = maxUp;
    mid = maxMid;
    down = maxDown;
}