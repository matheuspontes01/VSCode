# Dados a serem lidos:
# 1) Peso levantado no braco esquerdo
# 2) Peso levantado no braco direito
# 3) Numero de repeticoes
# encerra o programa quando todos os dados acima forem 0

# Formula de RM: w * (1 + r/30)
# w -> peso levantado
# r -> n de repeticoes

# imprimir o bordao de acordo com o resultado que foi calculado 

# calcular a media de todos os casos, se for maior do que 40, imprima a frase "Aqui nois constroi fibra rapaz! Nao e agua com musculo!"

w1 = -1
w2 = -1
r = -1
contador = 0
media = 0

while w1 != 0 and w2 != 0 and r != 0:
    w1 = int(input("Peso levantado no braco esquerdo: "))
    w2 = int(input("Peso levantada no braco direito: "))
    r = int(input("Numero de repeticoes: "))

    if not (1 <= w1 <= 60 and 1 <= w2 <= 100 and 1 <= r <= 12):
        break

    M = (w1 + w2)/2 * (1 + (r/30))

    if M > 60:
        print("AQUI E BODYBUILDER!!")
    elif M >= 40:
        print("Ta saindo da jaula o monstro!")
    elif M >= 14:
        print("Bora, hora do show! BIIR!")
    elif M >= 13:
        print("E 13")
    elif M >= 1:
        print("Nao vai da nao")

    contador = contador + 1

    media = media + M

if media > 40:
    print("Aqui nois constroi fibra rapaz! Nao e agua com musculo!")

