def calcularExpo(n):
    
    numero = 9 ** n
    
    return numero % 10



instancias = int(input())

while instancias > 0:
    potencia = int(input())
    print(calcularExpo(potencia))
    instancias = instancias - 1
