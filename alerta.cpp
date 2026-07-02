#include "alerta.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

alerta::alerta(std::string origem, int severidade)
    : origem_{std::move(origem)}, severidade_{severidade} {
    if (severidade < 1 || severidade > 3) {
        throw std::invalid_argument{"severidade deve estar entre 1 e 3"};
    }
}

void alerta::exibir() const {
    // Template Method: fixa o formato e delega tipo() e formatar() as derivadas.
    std::cout << "[" << tipo() << "] " << origem_ << ": "
              << formatar()
              << "\n";
}

std::string alerta::origem() const {
    return origem_;
}

int alerta::severidade() const {
    return severidade_;
}
