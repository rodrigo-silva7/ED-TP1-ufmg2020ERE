# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult

# === REGRAS =====
# ================
# 
# Aqui declaramos as nossas regras de compilacao.
# Para chamar uma regra, podemos simplesmente digitar
# 	make nome_regra
# Exs.:
# 	make ./tp1
# 	make foo.o
# 	make clean
# Cada regra de compilacao tem a seguinte sintaxe:
#
# NOME_OUTPUT: DEPENDENCIAS
# 	CMD
#
# NOME_OUTPUT eh o nome do arquivo que vai ser gerado (ou qualquer nome caso
# nenhum arquivo seja gerado, ex. clean)
# DEPENDENCIAS sao os nomes dos arquivos necessarios para executar essa regra
# de compilacao
# CMD sao os comandos necessarios para executar a regra (por exemplo, chamar o
# gcc)

$(EXEC): main.cc ShipManagementSystem.o
	$(CC) $(CFLAGS) main.cc ShipManagementSystem.o ShipNodeList.o ShipArrayList.o ShipQueue.o ShipStack.o ShipNode.o -o $(EXEC)

ShipManagementSystem.o: headers/ShipManagementSystem.cpp ShipNodeList.o ShipArrayList.o ShipQueue.o ShipStack.o
	$(CC) $(CFLAGS) -c headers/ShipManagementSystem.cpp -o ShipManagementSystem.o

ShipNode.o: headers/data/ShipNode.cpp
	$(CC) $(CFLAGS) -c headers/data/ShipNode.cpp -o ShipNode.o

ShipArrayList.o: headers/data/ShipArrayList.cpp
	$(CC) $(CFLAGS) -c headers/data/ShipArrayList.cpp -o ShipArrayList.o

ShipNodeList.o: headers/data/ShipNodeList.cpp ShipNode.o
	$(CC) $(CFLAGS) -c headers/data/ShipNodeList.cpp -o ShipNodeList.o

ShipQueue.o: headers/data/ShipQueue.cpp ShipNode.o
	$(CC) $(CFLAGS) -c headers/data/ShipQueue.cpp -o ShipQueue.o

ShipStack.o: headers/data/ShipStack.cpp ShipNode.o
	$(CC) $(CFLAGS) -c headers/data/ShipStack.cpp -o ShipStack.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm *.o

# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
