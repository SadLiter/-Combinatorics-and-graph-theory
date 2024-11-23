# Использование Docker для запуска алгоритмов

Этот документ описывает, как использовать Docker и Docker Compose для сборки и запуска контейнера, содержащего алгоритмы **Диница**, **Heapsort**, и **Форда-Фалкерсона**.

---

## Требования

Перед началом работы убедитесь, что на вашем компьютере установлены:
- **Docker** (версия 20.10 или выше)
- **Docker Compose** (версия 1.29 или выше)

Чтобы проверить, выполните:
```bash
docker --version
docker-compose --version
```

---

## Сборка контейнера

1. Перейдите в корневую папку проекта (где находится `docker-compose.yml`):
   ```bash
   cd путь/к/папке/проекта
   ```

2. Соберите Docker-образ с помощью команды:
   ```bash
   docker-compose build
   ```

---

## Запуск контейнера

Запустите контейнер:
```bash
docker-compose up -d
```

- Флаг `-d` запускает контейнер в фоновом режиме.

---

## Вход в контейнер

Чтобы войти в запущенный контейнер и использовать алгоритмы, выполните:
```bash
docker exec -it algorithms_container bash
```

Теперь вы находитесь внутри контейнера.

---

## Использование алгоритмов

### Запуск Python-алгоритмов
- **Алгоритм Диница:**
  ```bash
  python dinic/dinic.py < dinic/input.txt
  ```
- **Heapsort:**
  ```bash
  python heapsort/heapsort.py < heapsort/input.txt
  ```
- **Алгоритм Форда-Фалкерсона:**
  ```bash
  python ford_fulkerson/ford_fulkerson.py < ford_fulkerson/input.txt
  ```

### Компиляция и запуск C++-алгоритмов
1. Скомпилируйте алгоритмы:
   ```bash
   g++ -O2 -std=c++17 dinic/dinic.cpp -o dinic/dinic
   g++ -O2 -std=c++17 heapsort/heapsort.cpp -o heapsort/heapsort
   g++ -O2 -std=c++17 ford_fulkerson/ford_fulkerson.cpp -o ford_fulkerson/ford_fulkerson
   ```

2. Запустите их:
   - Алгоритм Диница:
     ```bash
     ./dinic/dinic < dinic/input.txt
     ```
   - Heapsort:
     ```bash
     ./heapsort/heapsort < heapsort/input.txt
     ```
   - Алгоритм Форда-Фалкерсона:
     ```bash
     ./ford_fulkerson/ford_fulkerson < ford_fulkerson/input.txt
     ```

---

## Остановка контейнера

Когда вы закончите работу, остановите контейнер:
```bash
docker-compose down
```

---

## Очистка

Если вы хотите полностью удалить контейнер и связанные с ним файлы:
1. Удалите контейнер:
   ```bash
   docker rm algorithms_container
   ```

2. Удалите образ:
   ```bash
   docker rmi algorithms
   ```

3. Удалите кэш сборки:
   ```bash
   docker builder prune
   ```