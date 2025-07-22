# 🐸 Jogo do Sapo

## 📋 Descrição

O **Jogo do Sapo** é um jogo de tabuleiro em C para dois jogadores, onde cada um controla um time de sapos: **Azuis** e **Vermelhos**. O objetivo é atravessar o campo adversário, evitar armadilhas (`X`) e capturar os sapos inimigos.

## 🎮 Regras do Jogo

- O tabuleiro é uma matriz 10x10.
- Os **sapos azuis (A)** começam na **linha 0** (topo).
- Os **sapos vermelhos (V)** começam na **linha 9** (base).
- Há **armadilhas (X)** distribuídas aleatoriamente no campo.
- Os jogadores se revezam escolhendo um sapo do seu time e movimentando-o.
- Movimentos válidos:
  - CIMA: `W`
  - BAIXO: `S`
  - ESQUERDA: `A`
  - DIREITA: `D`
  - DIAGONAIS SUPERIORES: `Q` (esq.) e `E` (dir.)
  - DIAGONAIS INFERIORES: `Z` (esq.) e `C` (dir.)
- Se o sapo tentar se mover para fora dos limites ou para uma casa ocupada por outro sapo do mesmo time, ele perde a vez.
- Se o sapo cair numa armadilha (`X`), ele é eliminado.
- Se um sapo for cercado por inimigos, ele é **preso**.
- Ao alcançar a última linha do adversário, o sapo é marcado como `W`.

## 🏆 Condições de Vitória

- O jogo termina quando **não houver mais sapos vivos** no tabuleiro (todos foram capturados ou presos).
- Vence o time com **mais sapos que chegaram ao lado oposto** (`W`).
- Em caso de empate, o jogo termina empatado.

## ▶️ Como Executar

1. Compile o código:
   ```bash
   gcc SAPO2.0.c -o jogo_do_sapo
   ```

2. Execute o jogo:
   ```bash
   ./jogo_do_sapo
   ```

## ⌨️ Controles

Durante sua vez, o jogador deve:

1. Escolher a **linha e coluna** do sapo que deseja mover.
2. Escolher a **direção** do movimento com as seguintes teclas:
   - `W`: cima
   - `S`: baixo
   - `A`: esquerda
   - `D`: direita
   - `Q`: diagonal superior esquerda
   - `E`: diagonal superior direita
   - `Z`: diagonal inferior esquerda
   - `C`: diagonal inferior direita

## ⚠️ Observações Técnicas

- O jogo é baseado em **entrada via terminal**.
- Utiliza `system("cls")` para limpar a tela (pode exigir Windows).
- Usa `sleep(1)` para pausar brevemente entre ações.
- As armadilhas são sorteadas com `srand(time(NULL))` ao iniciar o jogo.

## 🧠 Lógica de Implementação

- `PreencherMatriz`: inicializa o tabuleiro com sapos e armadilhas.
- `movimentar`: realiza o movimento do sapo conforme a direção escolhida.
- `LimitarMovimento`: impede que o sapo ultrapasse os limites.
- `PrenderSapo`: detecta se um sapo foi cercado.
- `Vitoria`: verifica se o jogo terminou e determina o vencedor.