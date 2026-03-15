# Lista representando o estoque da loja (preços dos produtos)
estoque = [100, 200, 300, 400]

def aplicar_desconto(lista_precos, desconto):
    """
    A função recebe a lista e altera diretamente seus elementos.
    Como listas em Python são mutáveis, qualquer modificação
    feita aqui afeta o mesmo objeto que existe no programa principal.
    """
    for i in range(len(lista_precos)):
        lista_precos[i] -= desconto  # altera o próprio objeto lista

print("Estoque antes do desconto:", estoque)

# Passamos a lista para a função
aplicar_desconto(estoque, 20)

print("Estoque após o desconto:", estoque)