contador = 0
contadorAnt = 0

up = 20
mid = 25
down = 30

maxUp = 50
maxMid = 55
maxDown = 60

minUp = 20
minMid = 25
minDown = 30


while True:
    a = int(input())

    if a == 1:
        contador += 1
    else:
        contador -= 1

    if a == 666:
        break

    print(f"Contador: {contador}")

    if contador > contadorAnt:
        up += 10
        down += 10
        mid += 10
    else:
        up -= 10
        down -= 10
        mid -= 10
    
    contadorAnt = contador
    
    if up > maxUp:
        up = minUp
        mid = minMid
        down = minDown
    if up < minUp:
        up = maxUp
        mid = maxMid
        down = maxDown

    print(f"Up: {up}")
    print(f"Mid: {mid}")
    print(f"Down: {down}")