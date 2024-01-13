import random

def main():
    palavras = ["banana", "maçã", "pera", "uva", "melão"]
    palavra_secreta = random.choice(palavras)
    letras_acertadas = []
    vidas = 6

    while vidas > 0:
        print("A palavra tem {} letras.".format(len(palavra_secreta)))
        print("Letras acertadas:", letras_acertadas)

        palpite = input("Digite uma letra: ")
        if palpite in palavra_secreta:
            letras_acertadas.append(palpite)
        else:
            vidas -= 1

        for letra in palavra_secreta:
            if letra in letras_acertadas:
                print(letra, end="")
            else:
                print("_", end="")
        print()

        if len(letras_acertadas) == len(palavra_secreta):
            print("Parabéns! Você acertou!")
            break
        else:
            print("Você ainda tem {} vidas.".format(vidas))

    if vidas == 0:
        print("Game over! A palavra era {}".format(palavra_secreta))

if __name__ == "__main__":
    main()

