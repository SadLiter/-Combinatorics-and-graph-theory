# Используем базовый образ Python с поддержкой компиляции C++
FROM python:3.9-slim

# Устанавливаем необходимые утилиты и компиляторы
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем все содержимое проекта
COPY . .

# Компилируем тесты для C++
RUN g++ -O2 -std=c++17 -DTESTING dinic/test_dinic.cpp -o dinic/test_dinic
RUN g++ -O2 -std=c++17 -DTESTING ford_fulkerson/test_ford_fulkerson.cpp -o ford_fulkerson/test_ford_fulkerson

# Устанавливаем точку входа
ENTRYPOINT ["/bin/bash"]
