Проект часов на 64х32 RGB матрицы и модуля ESP-WROOM-32. 
Применены общедоступные датчики температуры, влажности, давления. 

Автор проекта Игорь Шилов - https://vk.com/id570315884 
Шрифты от Alex Adresat - https://vk.com/public204990074
vk.link/clock64x32rgbledmatrix
https://vk.com/topic-204990074_49057697?offset=0

Функционал часов:
01. Время, день недели, число, год.
02. Будильники на каждый день с возможностью повтора и установкой мелодии.
03. Вывод погоды и прогноза погоды, в бегущей строке и отдельном экране с анимацией.
04. Поддержка датчиков (авто определение) BME280, BMP280, BMP180, GY21, DS18B20, AHT10/20.
Отображение в бегущей строке и или на отдельном экране с анимацией.
05. Поддержка датчика качества воздуха SGP30, вывод данных на отдельный экран.
06. Работа с MQTT. Вывод данных в бегущей строке или на отдельный экран.
07. Работа с "Народным мониторингом", вывод информации в бегущей строке.
08. Вывод в бегущей строке, "Новостей" с возможностью выбора категории
09. Вывод в бегущей строке "Афоризмов"
10. Коррекция датчиков.
11. Регулировка скорости бегущих строк.
12. Регулировка времени показа доп. экранов.
13. Выбор цифровых шрифтов
14. Настройка цвета как основного экрана, так и бегущих строк (по отдельности каждую)
15. Выбор яркости, шесть градаций.
16. Веб радио или FM радио (в зависимости от версии).
17. Отображение в бегущей строке композиции и станции при проигрывании веб радио.
18. МР3 плеер. Воспроизведение как одиночной мелодии, так и заданных папок в цикле.
19. Озвучка времени на выбор. Произношение Мужским и Женским голосом, Куранты, Зуммер.
20. Управление нагрузкой по MQTT (3 шт.) по времени, влажности, качеству воздуха.
21. Работа с модулем RTC. При пропадании WiFi часы переходят на RTC и при восстановлении WiFi
переходит на NTC.
22. Возможность быстрой перезагрузки (без анимации)
23. Возможность включать или отключать вывод в ком порт.
24. Возможность обновления прошивки по ОТА.
25. Простой и понятный веб интерфейс (на основе библиотеки Alexa Gyvera) с множеством настроек.
26. Четыре режима работы - основной, ночной, аналоговые часы, большие часы. Все переходы (кроме
аналоговых) можно задать по времени.
27. Несколько режимов ночного режима (выключенный экран, время с всплывающими установками
будильника, время с установками будильника, два варианта анимации часов по экрану)
28. Возможность включать и отключать экраны или бегущие строки информации.
