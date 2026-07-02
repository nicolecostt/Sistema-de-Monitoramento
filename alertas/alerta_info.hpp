#pragma once

#include "alerta.hpp"

#include <string>

class alerta_info : public alerta {
public:
    alerta_info(std::string origem, std::string mensagem);

    std::string tipo() const override;
    std::string formatar() const override;

private:
    std::string mensagem_;
};
