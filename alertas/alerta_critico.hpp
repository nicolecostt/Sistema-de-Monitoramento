#pragma once

#include "alerta.hpp"

#include <string>

class alerta_critico final : public alerta {
public:
    alerta_critico(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;

private:
    std::string mensagem_;
};
