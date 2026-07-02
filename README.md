# Sistema-de-Monitoramento

Exercicio integrador de Programacao Orientada a Objetos: Central de Alertas.

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
