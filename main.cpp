#include "alerta.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_debug.hpp"
#include "alertas/alerta_info.hpp"
#include "central.hpp"

#include <iostream>
#include <memory>

int main() {
    central c;

    c.registrar(std::make_unique<alerta_critico>(
        "sensor1", "temperatura 95.3 graus"));
    c.registrar(std::make_unique<alerta_aviso>(
        "sensor2", "umidade 78.5 pct"));
    c.registrar(std::make_unique<alerta_info>(
        "sistema", "reinicio agendado"));
    c.registrar(std::make_unique<alerta_debug>(
        "sistema", "diagnostico ativo", "verbose=true"));

    std::cout << "Total: " << c.total() << " alertas\n\n";

    c.exibir_todos();

    return 0;
}
