#include "alertas/alerta_debug.hpp"

#include <utility>

alerta_debug::alerta_debug(
    std::string origem,
    std::string mensagem,
    std::string contexto_tecnico)
    : alerta_info{std::move(origem), std::move(mensagem)},
      contexto_tecnico_{std::move(contexto_tecnico)} {}

std::string alerta_debug::formatar() const {
    return alerta_info::formatar() + " (debug: " + contexto_tecnico_ + ")";
}
