#pragma once

#include "alerta.hpp"

#include <memory>
#include <vector>

class central {
public:
    void registrar(std::unique_ptr<alerta> a);
    void exibir_todos() const;
    int total() const noexcept;

private:
    // Ponteiros polimorficos evitam object slicing e dispensam new/delete crus.
    std::vector<std::unique_ptr<alerta>> alertas_;
};
