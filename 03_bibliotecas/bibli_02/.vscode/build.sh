#!/usr/bin/env bash
# Compila o exercicio atual com simbolos de debug (-g) e gera ./prog
# Regras:
#   - inclui todos os .c seus (ignora Gabarito-src/ e Resultados/)
#   - adiciona -IIncludes se a pasta existir
#   - liga os .o de Gabarito-obj/ que NAO tem .c seu correspondente
set -eo pipefail

# vai para a raiz do exercicio (pasta acima de .vscode)
cd "$(dirname "$(readlink -f "$0")")/.."

INC=()
[ -d Includes ] && INC+=(-IIncludes)

# fontes .c do aluno
mapfile -t SRCS < <(find . -name '*.c' \
  -not -path './Gabarito-src/*' \
  -not -path './Resultados/*' \
  -not -path './.vscode/*' | sort)

if [ ${#SRCS[@]} -eq 0 ]; then
  echo "ERRO: nenhum arquivo .c encontrado em $(pwd)" >&2
  exit 1
fi

# objetos do gabarito sem .c correspondente (ex.: main.o quando voce nao escreve o main)
OBJS=()
if [ -d Gabarito-obj ]; then
  for o in Gabarito-obj/*.o; do
    [ -e "$o" ] || continue
    b=$(basename "$o" .o)
    dup=0
    for s in "${SRCS[@]}"; do
      [ "$(basename "$s" .c)" = "$b" ] && dup=1 && break
    done
    [ $dup -eq 0 ] && OBJS+=("$o")
  done
fi

echo "==> gcc -g ${INC[*]} ${SRCS[*]} ${OBJS[*]} -o prog"
gcc -fdiagnostics-color=always -g -O0 -Wall \
    "${INC[@]}" "${SRCS[@]}" ${OBJS[@]+"${OBJS[@]}"} -o prog -lm
echo "==> OK: ./prog gerado com simbolos de debug"
