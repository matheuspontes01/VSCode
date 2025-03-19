# Fazer um menu que mostrar as seguintes opcoes:
# Cadastrar itens do cardápio (nome do prato, preço, descrição).
# Registrar pedidos feitos pelos clientes, associando um ou mais itens do cardápio ao pedido.
# Calcular o total do pedido com base nos itens escolhidos.
# Gerar um relatório com todos os pedidos feitos, mostrando o total arrecadado pelo restaurante no dia

# Gerando Menu com opcoes (if-else, porque em phyton nao existe switch case)
def mostrar_opcoes():
    print("[1] Cadastrar itens do cardápio (nome do prato, preço, descrição)")
    print("[2] Registrar pedidos feitos pelos clientes, associando um ou mais itens do cardápio ao pedido")
    print("[3] Calcular o total do pedido com base nos itens escolhidos")
    print("[4] Gerar um relatório com todos os pedidos feitos, mostrando o total arrecadado pelo restaurante no dia")

def cadastrar_pedido(menu):
    prato = input("Digite o nome do prato: ")
    preco = float(input("Digite o preco do prato: "))

    menu["prato"] = preco
    return menu

def registrar_pedido(menu):
    total_dia = 0
    total_pedido = 0
    pedido_cliente = {}
    print("\n         CARDAPIO           \n")

    print(menu)

    accept_sandwich = input("Aceita sanduiche? (s ou n)").lower()
    if accept_sandwich == 's':
        more_sandwich = "s"
        while more_sandwich != "n":
            sandwich = input("Selecione o sanduiche desejado: ").lower()
            qty = int(input("Quantidade: "))
            pedido_cliente[sandwich] = qty
            if sandwich in menu:
                total_pedido += qty * menu[sandwich]
            more_sandwich = input("Aceita mais sanduiche? (s ou n)")

    accept_drink = input("Aceita bedida? (s ou n)").lower()
    if accept_drink == "s":
        more_drink = "s"
        while more_drink != "n":
            drink = input("Selecione a bebida desejada: ").lower()
            qty = int(input("Quantidade: "))
            pedido_cliente[drink] = qty
            if drink in menu:
                    total_pedido += qty * menu[drink]
            more_drink = input("Aceita mais bebida? (s ou n)")

    print("Seu pedido: ITEM | QUANTIDADE")
    print(pedido_cliente)
    pedido_cliente["total"] = total_pedido
    return pedido_cliente


menu = {}
pedido_cliente = {}
total_dia = {}

mostrar_opcoes()
op = int(input("Selecione o que deseja: "))
if op == 1:
    menu = cadastrar_pedido(menu)
elif op == 2:
    pedido_cliente = registrar_pedido(menu)
    total_dia
elif op == 3:
    print(f"Total do pedido do cliente: {pedido_cliente["total"]}")
elif op == 4:





menu = {
    "x-burguer": 12.0,
    "x-salada": 15.0,
    "x-bacon": 17.0,
    "x-tudo": 20.0,

    "lata": 3.0,
    "refri 600ml": 5.0,
    "refri 2l": 8.0
}

work_done = "n"
total_dia = 0
while work_done != "s":
    total_pedido = 0
    pedido_cliente = {}
    print("\n         CARDAPIO           \n")

    print(menu)

    accept_sandwich = input("Aceita sanduiche? (s ou n)").lower()
    if accept_sandwich == 's':
        more_sandwich = "s"
        while more_sandwich != "n":
            sandwich = input("Selecione o sanduiche desejado: ").lower()
            qty = int(input("Quantidade: "))
            pedido_cliente[sandwich] = qty
            if sandwich in menu:
                total_pedido += qty * menu[sandwich]
            more_sandwich = input("Aceita mais sanduiche? (s ou n)")

    accept_drink = input("Aceita bedida? (s ou n)").lower()
    if accept_drink == "s":
        more_drink = "s"
        while more_drink != "n":
            drink = input("Selecione a bebida desejada: ").lower()
            qty = int(input("Quantidade: "))
            pedido_cliente[drink] = qty
            if drink in menu:
                total_pedido += qty * menu[drink]
            more_drink = input("Aceita mais bebida? (s ou n)")

    print("Seu pedido: ITEM | QUANTIDADE")
    print(pedido_cliente)
    print(f"Total: {total_pedido}")
    total_dia += total_pedido

    work_done = input("O trabalho de hoje acabou? (s ou n)").lower()


print(f"Venda total do dia: {total_dia}")
            


    

