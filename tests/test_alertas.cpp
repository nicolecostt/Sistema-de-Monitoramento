#include "alerta.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_debug.hpp"
#include "alertas/alerta_info.hpp"
#include "central.hpp"

#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

class alerta_teste final : public alerta {
public:
    explicit alerta_teste(int severidade)
        : alerta{"origem-teste", severidade} {}

    std::string tipo() const override {
        return "TESTE";
    }

    std::string formatar() const override {
        return "mensagem teste";
    }
};

void exigir(bool condicao, const std::string& mensagem) {
    if (!condicao) {
        throw std::runtime_error{mensagem};
    }
}

} // namespace

int main() {
    alerta_critico critico{"sensor1", "temperatura 95.3 graus"};
    alerta_aviso aviso{"sensor2", "umidade 78.5 pct"};
    alerta_info info{"sistema", "reinicio agendado"};
    alerta_debug debug{"sistema", "diagnostico ativo", "verbose=true"};

    exigir(critico.tipo() == "CRITICO", "alerta_critico deve retornar CRITICO");
    exigir(critico.formatar() == "temperatura 95.3 graus",
           "alerta_critico deve formatar a mensagem");
    exigir(critico.severidade() == 3, "alerta_critico deve ter severidade 3");

    exigir(aviso.tipo() == "AVISO", "alerta_aviso deve retornar AVISO");
    exigir(aviso.severidade() == 2, "alerta_aviso deve ter severidade 2");

    exigir(info.tipo() == "INFO", "alerta_info deve retornar INFO");
    exigir(info.severidade() == 1, "alerta_info deve ter severidade 1");

    exigir(debug.tipo() == "INFO", "alerta_debug deve continuar sendo INFO");
    exigir(debug.formatar() == "diagnostico ativo (debug: verbose=true)",
           "alerta_debug deve anexar contexto tecnico");

    bool lancou = false;
    try {
        alerta_teste invalido{4};
    } catch (const std::invalid_argument&) {
        lancou = true;
    }
    exigir(lancou, "alerta deve rejeitar severidade fora de [1, 3]");

    central c;
    c.registrar(std::make_unique<alerta_critico>("sensor1", "temperatura 95.3 graus"));
    c.registrar(std::make_unique<alerta_aviso>("sensor2", "umidade 78.5 pct"));
    c.registrar(std::make_unique<alerta_info>("sistema", "reinicio agendado"));
    c.registrar(std::make_unique<alerta_debug>("sistema", "diagnostico ativo", "verbose=true"));

    exigir(c.total() == 4, "central deve registrar quatro alertas");

    return 0;
}
