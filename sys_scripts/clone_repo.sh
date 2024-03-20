#!/bin/bash

# Читаем REPO_URL из файла valid_libs.spv
while IFS= read -r REPO_URL
do
    # Указываем директорию, куда будет клонирован репозиторий
    REPO_DIR="./libs"
    
    # Клонируем репозиторий
    git clone $REPO_URL $REPO_DIR
done < valid_libs.spv