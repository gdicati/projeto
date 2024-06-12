# Makefile para compilar e executar o programa principal

# O executável final
main: main.o medalha.o
    gcc main.o medalha.o -o main

# Compilando o arquivo objeto principal
main.o: main.c medalha.h
    gcc -c main.c

# Compilando o arquivo objeto medalhas
medalha.o: medalha.c medalha.h
    gcc -c medalha.c

# Limpa os arquivos objeto e o executável
clean:
    rm -f *.o main

# Executa o programa
run:
    ./main