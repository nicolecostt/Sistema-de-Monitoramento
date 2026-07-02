#pragma once

#include "alertas/alerta_info.hpp"

#include <string>

class alerta_debug : public alerta_info {
public:
    alerta_debug(std::string origem, std::string mensagem, std::string contexto_tecnico);

    std::string formatar() const override;

private:
    std::string contexto_tecnico_;
};
