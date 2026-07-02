# Sistema-de-Monitoramento

Repositorio do exercicio integrador de Programacao Orientada a Objetos
(POO 2026.1): **Central de Alertas**.

O projeto consiste em um sistema simples de monitoramento que registra e exibe
alertas de diferentes tipos. A implementacao exercita os conceitos pedidos no
enunciado: interface pura, classe abstrata, heranca, `override`, `final`,
Template Method e polimorfismo dinamico com
`std::vector<std::unique_ptr<alerta>>`.

## Organizacao do projeto

```text
.
|-- CMakeLists.txt
|-- README.md
|-- alerta.hpp
|-- alerta.cpp
|-- central.hpp
|-- central.cpp
|-- main.cpp
|-- tests/
|   `-- test_alertas.cpp
`-- alertas/
    |-- alerta_critico.hpp
    |-- alerta_critico.cpp
    |-- alerta_aviso.hpp
    |-- alerta_aviso.cpp
    |-- alerta_info.hpp
    |-- alerta_info.cpp
    |-- alerta_debug.hpp
    `-- alerta_debug.cpp
```

### Responsabilidades principais

- `alerta.hpp` / `alerta.cpp`: definem a interface pura `formatavel` e a classe
  abstrata `alerta`, que concentra o estado comum e o Template Method `exibir()`.
- `alertas/`: reune as classes concretas de alerta (`alerta_critico`,
  `alerta_aviso`, `alerta_info`) e o desafio opcional `alerta_debug`.
- `central.hpp` / `central.cpp`: implementam a central que armazena os alertas
  usando `std::vector<std::unique_ptr<alerta>>`, evitando `new/delete` crus e
  object slicing.
- `main.cpp`: demonstra o uso da central, registra alertas e imprime a saida
  esperada.
- `tests/test_alertas.cpp`: verifica os principais comportamentos das classes
  sem depender de bibliotecas externas de teste.
- `CMakeLists.txt`: configura a compilacao do projeto em C++17.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
./build/central_alertas
```

No Windows, dependendo do gerador usado pelo CMake, o executavel pode ficar em
`build/Debug/central_alertas.exe`.

## Saida esperada

```text
Total: 4 alertas

[CRITICO] sensor1: temperatura 95.3 graus
[AVISO] sensor2: umidade 78.5 pct
[INFO] sistema: reinicio agendado
[INFO] sistema: diagnostico ativo (debug: verbose=true)
```

## Uso de IA

IA foi usada como apoio para interpretar o enunciado, revisar a organizacao do
repositorio e checar boas praticas de POO em C++17. O codigo foi revisado para
garantir que as decisoes principais estejam compreendidas: interface pura,
classe abstrata, destrutor virtual, Template Method, `override`, `final` e
polimorfismo com `std::unique_ptr`.
