Дано:
сетевой супермаркет с множеством кассовых аппаратов самой минимальной конфигурации,
какая необходима только для выполнения кассовых операций. Кассовый аппарат
представляет из себя слабый компьютер с небольшим количеством ОЗУ. Его задача - при
включении загрузить по сети с удаленного хранилища список всех товаров магазина.
Список представляет из себя csv файл следующего формата:

Штрих Код (строка из цифр), наименование(строка), группа, подгруппа, цена, поставщик, срок поставки, срок годности, адрес полки с товаром и другие

Непосредственно содержимое csv-файла:

134123123;Антоновка;яблоко;зеленое;70;ООО Агрофирма;10.10.22;45;1/2/3/

567893234;Дюшес;груша;отечественная;75;ООО Агрофирма;05.10.22;30;1/10/3/

...и еще около 100 000 таких строк...

Требования к кассовому аппарату:
- загрузить после включения питания список товаров магазина. Список расположен в
локальном файле на файловой системе кассового аппарата (уже примонтировано удаленное
хранилище):
UINX системы : /mnt/data/products.csv
WINDOWS системы: \\data\products.csv
Используйте какой-то один путь. Чтение осуществляется обычными функциями по работе с
файлами: <fstream> или подобными.
- после загрузки списка товаров есть достаточно времени (можно применять длительные
алгоритмы в начале работы) на подготовку данных в ОЗУ таким образом, чтобы:
 а) осуществлять быстрый поиск товара по штрих коду
 б) осуществлять быстрый поиск товара по наименованию (после ввода полного имени
начинается поиск)
- печатать в чеке всю информацию о товаре

Требования к реализации:
- можно использовать C++20
- активно используем STL
- не используем никакие БД
- не дублируем данные в ОЗУ (сохраняем минимальные необходимые размеры ОЗУ)
В каком виде решать и подготавливать решение:
Суть задачи состоит в правильной организации данных в ОЗУ - нужно подготовить данные
таким образом, чтобы по ним можно было быстро искать по значению одного из двух полей:
штрих кода или наименования.
В ответе нужно
- словами и набросками схемы описать алгоритм решения, указывая точные типы данных,
которые будут использованы в программе
- описать процесс работы программы
- описать структуры данных и взаимосвязи между ними
- пояснить, почему данные в описанном алгоритме не дублируются в ОЗУ
- пояснить, почему поиск по штрих коду или наименованию будет быстрым, в сравнении с,
например, группой (терминами O()).
- ОПЦИОНАЛЬНО: приложить файл исходного кода cash-register.cpp с реализацией
алгоритма, но можно обойтись только наброском, если считаете, что изложили ход решения
понятно.
