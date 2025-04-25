# Desafio 1

## Passo a passo para compilação e execução
1. Compile os arquivos `requisicao.c` e `estrutura.c`
    ```bash
    gcc -c requisicao.c estrutura.c
    ```
2. Compile o arquivo de teste utilizando os arquivos compilados
    ```bash
    gcc teste.c requisicao.o estrutura.o -o teste
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
gcc -c requisicao.c estrutura.c && gcc teste.c requisicao.o estrutura.o -o teste && ./teste
```

**Windows**
```bash
gcc -c requisicao.c estrutura.c && gcc teste.c requisicao.o estrutura.o -o teste && teste.exe
```