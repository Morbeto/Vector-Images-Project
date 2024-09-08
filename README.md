ТЕМА - Реализиране на векторни изображения
В рамките на този проект трябва да се реализира приложение, което може да нарежда фигури (елементи) във векторни изображения. Фигурите могат да се припокриват, т.е. могат да бъдат в различни слоеве на изображението. Приложението трябва да може да зарежда фигури от файл, да извършва върху тях дадени операции, след което да може да записва промените обратно на диска.
Поддържат се четири основни вида фигури: отсечки, дъги от окръжности, правоъгълници и многоъгълници. Дизайнът на приложението обаче трябва да е такъв, че да позволява при нужда лесно да може да се добави поддръжка на нови фигури. За всяка фигура се задава цвят на контурната линия, както и цвят на запълване или прозрачно (където това има смисъ л).
Отсечките се определят от координатите на двата си края; дъгите - с координати на центъра, радиуса си, ориентиран ъгъл на началото на дъгата и ширина на дъгата (и двете в градуси); правоъгълниците  - с координати на горен-ляв ъгъл, ширина и дължина; а многоъгълниците - с последователните координатите на всичките си върхове. Обърнете внимание, че дъга с ширина по-голяма или равна на 360 градуса е окръжност.
Потребителят трябва да може да изпълнява следните команди.
Отваряне на файл с изображение
> open <файл>
Прочита съдържанието на даден файл и го зарежда в паметта. Когато се зарежда съдържанието на даден файл, трябва да се прочетат само фигурите, които се разпознават от приложението. Всички останали елементи на файла се игнорират, но се извежда подходяща информация за потребителя. 
Файлът може да се зададе с пълния си път, в противен случай се търси в папка по подразбиране.
Пример:
> open figures.svg
Successfully opened figures.svg
Извеждане на изображение
> print 
Извежда на екрана фигурите, прочетени от файла. 
Пример:
> print
1.	rectangle 5 5 10 10 green orange
2.	arc 5 5 10 20 360 blue green
3.	rectangle 100 60 10 10 red white
Създаване на нова фигура
> create <тип на фигура> <компоненти на фигурата>
Създава нова фигура и я добавя към изображението.
<тип на фигура> е някой от типовете фигури, които се разпознават от приложението. 
<компоненти на фигурата> са всички необходими за инициализиране на фигурата параметри. Всяка фигура получава уникален идентификатор при създаването си.
Пример:
> create rectangle 100 100 10 20 yellow white
Successfully created rectangle. ID 4.
Групиране на елементи
> group <region>
<region> се задава от потребителя като координати на горен-ляв и долен-десен ъгъл.
Пример:
> group 10 10 15 15
Командата групира в нов елемент всички фигури, които изцяло се съдържат в указания регион. Резултатът е нова фигура, като всички операции, прилагани върху нея,  се случват върху елементите в нея. Върху елементи, част от група, не могат да се прилагат индивидуални операции.

> ungroup <id>
Прекратява групирането на елементите в посочената с <id> група. Групата вече не съществува (няма фигура с такъв идентификатор), а фигурите, съставляващи групата, могат да се променят индивидуално.

> insert <gr_id> <elem_id>
Добавя елемента с <elem_id> към групата с <gr_id>. Добавеният елемент сам по себе си може да е група.

> extract <gr_id> <elem_id>
Премахва елемента с <elem_id> от групата с <gr_id>. 
Промяна на видимост
> hide <id>
Скрива елемента <id>. Върху него продължават да се прилагат всички трансформации, но не се записва при save и не се извежда при print.

> show <id>
Отменя действието на извършено скриване на елемента <id>. 
Транслиране на елементи
> translate [<id>] vertical=<v> horizontal=<h>
Ако е посочен номер на елемент в изображението, то избраният елемент се транслира с указания вектор. Ако не е посочен номер на елемент, то операцията се прилага за всички елементи в изображението.
Пример:
> translate 2 vertical=10 horizontal=100
> print
1.	rectangle 5 5 10 10 green orange
2.	rectangle 110 160 10 10 red white
3.	arc 5 5 10 20 360 black green
Транслира се единствено правоъгълникът, който се намира във втория слой на изображението.
Записване на изображение
> save
> save as <форматът, който се поддържа от вашето приложение>
Приложението трябва да поддържа два вида извеждане: в избран от вас формат и в някакъв графичен формат, който може да се визуализира (ppm, bmp, svg или друг).
Извеждане на познатите команди
> help
Извежда списък на командите, които се поддържат от приложението.
