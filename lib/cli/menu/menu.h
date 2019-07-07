#include <utility>

#include <utility>

//
// Created by ssbjy-dave on 2019.06.30..
//
#pragma once

#include "dependency.h"

namespace MENU {
    enum MENU_OPTIONS {
        PLACEHOLDER = -2,
        QUIT = -1,
        GAUSS_ELIMINATION = 0,
        PROGONKA_METHOD,
        LU_DECOMPOSITION,
        ILU_DECOMPOSITION,
        QR_DECOMPOSITION,
        JACOBI_ITERATION,
        GAUSS_SEIDEL_ITERATION,
        RICHARDSON_ITERATION,
        ILU_DECOMPOSITION_ALGORITHM
    };

    struct menu_item {
    public:
        const std::wstring title;
        const MENU_OPTIONS command;
        const std::vector<const menu_item*> sub_items;

        menu_item(std::wstring _title, const MENU_OPTIONS& _command, std::vector<const menu_item *> _sub_items)
            : title(std::move(_title)), command(_command), sub_items(std::move(_sub_items)) {}

        ~menu_item() {
            for (auto sub_item : sub_items) delete sub_item;
        }
        static const menu_item* create_menu_item(nlohmann::json json);
    };

    struct menu {
    public:
        explicit menu(std::vector<const menu_item *> _items) : items(std::move(_items)) {}
        const std::vector<const menu_item*> items;
        ~menu() {
            for (auto item : items) delete item;
        }
    };

    struct main_menu : public menu {
    private:
        static void create_instance();

        static std::unique_ptr<menu> instance;

    public:
        main_menu(std::vector<const menu_item *> _items) = delete;
        static const menu get_instance();
    };
}