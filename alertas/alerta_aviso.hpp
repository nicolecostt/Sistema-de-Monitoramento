#pragma once

#include "alerta.hpp"

#include <string>

class alerta_aviso : public alerta {
public:
    alerta_aviso(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;

private:
    std::string mensagem_;
};
