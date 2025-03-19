notas = []

media = 0

for x in range(4):
    nota = float(input("Digite a nota: "))
    notas.append(nota)
    media += nota


y = 0
for y in range(4):
    print(f"Nota do aluno {y + 1}:", notas[y])

media /= 4
print("Media da turma:", media)




