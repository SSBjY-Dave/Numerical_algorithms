#include <memory>

//
// Created by ssbjy-dave on 2019.07.01..
//
#include <iostream>
#include "menu.h"

const std::string menu_structure_file = "menu.json"; // NOLINT(cert-err58-cpp)

const MENU::menu_item* MENU::menu_item::create_menu_item(nlohmann::json json) {
    std::vector<const menu_item*> sub_items;
    if (json.contains("sub_item")) {
        auto sub_items_json = json["sub_item"];
        sub_items.reserve(sub_items_json.size());
        for (const auto& item : sub_items_json) sub_items.push_back(create_menu_item(item));
    }
    return new menu_item(utility::utf8_utf16_converter.from_bytes(json["value"].dump(0)), ((json.contains("command")) ? static_cast<MENU_OPTIONS >(std::stoi(json["command"].dump(0))) : MENU_OPTIONS::PLACEHOLDER), sub_items);
}

std::unique_ptr<MENU::menu> MENU::main_menu::instance = std::unique_ptr<MENU::menu>();

const MENU::menu MENU::main_menu::get_instance() {
    if (instance == nullptr) create_instance();
    return *instance;
}

void MENU::main_menu::create_instance() {
    std::ifstream file(PATHS::resources + menu_structure_file);
    nlohmann::json json;
    file>>json;

    std::vector<const menu_item*> items;
    auto menu_json = json["menu"];
    items.reserve(menu_json.size());
    for (const auto& item : menu_json) items.push_back(menu_item::create_menu_item(item));

    instance = std::make_unique<menu>(items);
}