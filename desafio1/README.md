# Desafio 1

1. Compile os arquivos `requisicao.c` e `estrutura.c`
    ```bash
    gcc -c requisicao.c estrutura.c
    ```
2. Compile o arquivo de teste utilizando os arquivos compilados
    ```bash
    gcc teste.c requisicao.o estrutura.o -o teste
    ```
3. Execute
    ```bash
    ./teste
    ```

**Compilação e execução rápida:**
```bash
gcc -c requisicao.c estrutura.c && gcc teste.c requisicao.o estrutura.o -o teste && ./teste 
```