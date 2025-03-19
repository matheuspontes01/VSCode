# Verificar a tabela de reajuste salarial
# Ler o salario do funcionario, imprimir o novo salario, o reajuste ganho e o percentual

salario = float(input("Digite o salario do funcionario: "))

reajuste_ganho = 0
novo_salario = 0
percentual = 0

if salario > 2000:
    reajuste_ganho = salario*0.04
    novo_salario = salario + reajuste_ganho
    percentual = 0.04
elif salario > 1200:
    reajuste_ganho = salario*0.07
    novo_salario = salario + reajuste_ganho
    percentual = 0.07
elif salario > 800:
    reajuste_ganho = salario*0.1
    novo_salario = salario + reajuste_ganho
    percentual = 0.1
elif salario > 400:
    reajuste_ganho = salario*0.12
    novo_salario = salario + reajuste_ganho
    percentual = 0.12
else:
    reajuste_ganho = salario*0.15
    novo_salario = salario + reajuste_ganho
    percentual = 0.15


print("Novo salario:", novo_salario)
print("Reajuste ganho:", reajuste_ganho)
print("Em percentual:", percentual*100)