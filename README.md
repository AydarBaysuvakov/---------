<h1 align="center">Решение квадратного уравнения</h1>
<h3 align="center">Первое задание на летней школе от Деда</h3>

## Описание программы

Программа решает квадратные уравнения вида ax^2 + bx + c = 0.

Также есть возможность решать линейные уравнения вида kx + b = 0.

Реализованы тестирующая система, система нахождения ошибок, системы ввода и вывода, а также функции для решения квадратного и линейного уравнений.

## Руководство пользователя

### Запуск программы

Запуск осуществляется при помощи скрипта release в командной строке.

```
./release
```

Для повторного запуска можно запустить исполняемый файл release.out.

```
./release.out
```

### Ответ программы

Если ошибок нет, программа попросит внести необходимые коэфиценты(три действительных числа a, b, c, которые являются членами уравнения ax^2 + bx + c = 0 в соответственном порядке).
Если были введены верные коэфиценты, выводится ответ.
Возможные сообщения:
- Корни, если они есть
- "No roots", если корней нет
- "Any number", если корнем уравнения является любое число

## Функции, константы и структуры

### Константы

Константы **RootsCount** и **IOError** содержатся в файле **"StructConst.h"**.
Константы **MEASURE_ERROR** и **boolean** содержатся в файле **"IsEqual.cpp"**.

#### RootsCount

Содержит четыре константы, каждая из которых обозначает колличество корней уравнения:
- **INF_ROOTS** = -1
- **ZERO_ROOTS** = 0
- **ONE_ROOT** = 1
- **TWO_ROOTS** = 2

#### IOError

Содержит две константы, которые означают успешность выполнения ввода или вывода:
- **OK** = 0
- **ERROR** = -1

#### MEASURE_ERROR

Погрешность для действительных чисел (MEASURE_ERROR=0.000001).

#### boolean

Булевый тип данных:
- **FALSE** = 0
- **TRUE** = 1

### Структуры

Все данные структуры содержатся в файле **"StructConst.h"**.

#### Coefs

Коеффиценты уравнения ax^2 + bx + c = 0.
- **Coefs.a** - Старший член.
- **Coefs.b** - Член при х.
- **Coefs.c** - Свободный член.

#### Roots

Корни уравнения ax^2 + bx + c = 0.
- **Roots.x1** - Меньший корень.
- **Roots.x2** - Больший корень.
x1 = x2 = 0, если корней нет или каждое число является корнем.

### Функции

#### InputCoeffsSTD
Файл: **IOcoef.cpp**

Запрашивает пользователя коэффиценты квадратного уравнения вида ax^2 + bx + c = 0.

Принимает указатель на структуру Coeffs.

На первой строке выводится информация о программе.
На второй строке выводится просьба ввести коэфиценты.
Далее пользователь должен ввести три действительных числа, коэффиценты a, b, c.

Возвращает константу типа **IOError**: OK=0, если пользователь вводит верные данные, при ошибке выводит ERROR=1.

#### OutputCoeffsSTD
Файл: **IOcoef.cpp**

Выводит корни квадратного уравнения вида ax^2 + bx + c = 0.

Принимает колличество корней в виде целого числа или константы **RootsCount**.

- Печатает корни, если они есть.
- No roots, если корней нет.
- Any number, если корнем уравнения является любое число.

Возвращает константу типа **IOError**: OK=0, если программа сработала корректно, при ошибке выводит ERROR=1.

#### SolveSquare
Файл: **SolveFunc.cpp**

Функция для решения квадратного уравнения вида ax^2 + bx + c = 0.

Принимает коэффиценты уравнения через структуру **Coeffs** и указатель на структуру **Roots** для того, чтобы вернуть корни.

Возвращает колличество корней в виде константы **RootsCount**.

#### SolveLinear
Файл: **SolveFunc.cpp**

Функция для решения линейного уравнения вида kx + b = 0.

Принимает действительные числа k и b - Коэфиценты уравнения.
Также принимает указатель, по адресу в который кладет корень уравнения.

Возвращает колличество корней в виде константы **RootsCount**.

#### IsEqual
Файл: **IsEqual.cpp**

Функция сравнивает действительные числа с учетом погрешности.

Принимает действительные числа a и b.
Возвращает тип **boolean** **True**, если a и b равны, и **False**, в ином случае.

#### myAssert
Файл: **myAssert.cpp**

Завершает работу программы и вызывает предупреждающее сообщение.
Функция создана для отлавливания ошибок программиста.
При использовании флага -DDEBUG запускает режим дебага, в ином случае все функции становятся недействительны.

### Тестирующая система

Отдельно про файл **Test.cpp**.

#### Константа TestFeedback

Содержит два значения:
- TestFailed = 0.
- TestAcepted = 1.

#### Структура TestData

- Структура **Coeffs** - коэфиценты уравнения.
- Целое число **nRootsRef** - ожидаемое колличество корней.
- Структура **RootsRef** - ожидаемые корни уравнения.
- Строка **name** - название теста.

#### TestOne

Функция для еденичного тестирования функции **SolveSquare**.

Принимает коэфиценты уравнения в структуре **Coeffs**, а также ожидаемые значения корней в структуре **Roots** и колличества корней.
Выполняет функцию **SolveSquare** на полученных коэффицентах и сравнивает полученный результат с ожидаемым.
При совпадении отправляет сообщение ОК зелёным цветов и возвращает константу **TestAcepted** типа **TestFeedback**.
При несовпадении отправляет сообщение об ошибке красным цветом с указанием ожидаемых и действительных результатов и возвращает константу **TestFailed** типа **TestFeedback**.

#### TestAll

Считывает из файла **test.txt** тестирующие данные, которые записаны в строках в следующем порядке:
- Коэффицент а.
- Коэффицент b.
- Коэффицент c.
- Ожидаемое колличество корней.
- Ожидаемый меньший корень(0, если корней нет или их бесконечное колличество).
- Ожидаемый больший корень(0, если корней нет или их бесконечное колличество).

Завпускает функцию **TestOne** с полученными данными.

Если тест написан некорректно, то печатает текст, оповещающий об ошибке, и завершает досрочно функцию.

Если все тесты были пройдены, печатается колличество пройденных тестов.

Функция возвращает колличество пройденных тестов.
