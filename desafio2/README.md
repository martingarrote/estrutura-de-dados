# Desafio 2

## Passo a passo para compilação e execução
1. Compile os arquivos `cliente.c`, `node.c`, `lista.c` e `estrutura.c`
    ```bash
    gcc -c cliente.c node.c lista.c estrutura.c
    ```
2. Compile o arquivo de teste utilizando os arquivos compilados
    ```bash
    gcc teste.c cliente.o node.o lista.o estrutura.o -o teste
    ```
3. Execute
    - **Linux**
        ```bash
        ./teste
        ```
    - **Windows**
        ```bash
        teste.exe
        ```

## Compilação e execução rápida

**Linux**
```bash
gcc -c cliente.c node.c lista.c estrutura.c && gcc teste.c cliente.o node.o lista.o estrutura.o -o teste && ./teste
```

**Windows**
```bash
gcc -c cliente.c node.c lista.c estrutura.c && gcc teste.c cliente.o node.o lista.o estrutura.o -o teste && teste.exe
```