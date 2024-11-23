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
RUN g++ "Алгоритм Диницы/test_dinic.cpp" -o "Алгоритм Диницы/test_dinic"
RUN g++ "Алгоритм Форда-Фалкерсона/test_ford_fulkerson.cpp" -o "Алгоритм Форда-Фалкерсона/test_ford_fulkerson"

# Устанавливаем точку входа
ENTRYPOINT ["/bin/bash"]
