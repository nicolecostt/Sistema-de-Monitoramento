#pragma once

#include <string>

// Interface pura: define apenas o contrato de formatacao.
class formatavel {
public:
    virtual ~formatavel() = default;
    virtual std::string formatar() const = 0;
};

// Classe abstrata com estado; exibir() aplica o Template Method.
class alerta : public formatavel {
public:
    alerta(std::string origem, int severidade);
    virtual ~alerta() = default;

    void exibir() const;

    virtual std::string tipo() const = 0;

    std::string origem() const;
    int severidade() const;

private:
    std::string origem_;
    int severidade_;
};
