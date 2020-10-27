﻿/*************************************************************
	Практическое занятие №3. Директивы препроцессора.
							Указатели.
*************************************************************/
#define _USE_MATH_DEFINES		// для константы  M_PI
#include <cmath>

#include <iostream>
#include <tchar.h>


#define	  stop __asm nop	//с помощью директивы препроцессора задаем
							//макроподстановку

int _tmain()
{
// ********************************************************
	//Задание 1. Директивы препроцессора

	//1.1. Использование "математических" макросов стандартной библиотеки:
	//в заголовочном файле <cmath> (который в свою очередь включает старый
	//файл math.h) определены часто используемые математические
	//константы, например M_PI. Воспользуйтесь этой константой для
	//вычисления длины окружности.
	//Обратите внимание: определения констант в свою очередь тоже заключены
	//в директивы условной трансляции. Что еще, кроме подключения заголовочного
	//файла, требуется сделать???

	// #define _USE_MATH_DEFINES		// для константы  M_PI
	
	#define calculateCircle(radius)	(M_PI)*(pow(radius, 2))
	
	// *******************************************************


	
	//1.2.Макросы с параметрами.
	//1.2.1 Напишите свою макроподстановку LENGHT которая вычисляет длину окружности.
	// протестируйте написанный макрос для следующих ситуаций:
	{
		//float l1 = LENGHT(1 + 2); // должно быть 18.8495...
		//float l2 = 1 / LENGHT(2); // должно быть 0.07957...

		#define PI 3.14
		#define LENGHT(radius)	static_cast<float>(2.0 * PI * static_cast<float>(radius))		// первое преобразование для второго теста. Второе преобр. для первого теста
		stop
	}
// *******************************************************

	//1.2.2 (B) определите макрос MAX(A, B)  для вычисления б'ольшего
	//значения из двух.
	
	//Используйте макрос следующим образом. Следите за изменением
	//значений переменных k, i, j. Объясните результат.
	//Постарайтесь убрать побочные эффекты.
	//Отметьте случаи, когда избежать побочных эффектов невозможно
	//В комментариях  укажите значения переменных i, j, k


	#define MAX(i, j)	(( (i) > (j) )? (i) : (j))
/*
	int i = 10, j = 12, k;
	k = MAX(i, j);					//i= 10	, j= 12	, k= 12
	k = MAX(j, i) * 2;				//i= 10	, j= 12	, k= 24
	k = MAX(j, i+3);				//i= 13	, j= 12	, k= 13
	k = MAX(i--, j++);				//i= 9	, j= 13	, k= 13
*/
	
// *******************************************************

	//1.2.3 определите макрос EXCHANGE(X, Y)  для перестановки
	//двух объектов типа int в памяти местами. Проверьте для приведенного
	//фрагмента. Подумайте, что будет делать макроподстановка, 
		
	//если переставляемые значения разного типа???
	// переставит, также по условию

	#define	EXCHANGE(x,y) int tmp = x; x = y; y = tmp

	// int x1=1, y1=-1;
	// EXCHANGE(x1,y1);

	// int x2=100, y2=-100;
	// EXCHANGE(x2,y2);


	stop
// *******************************************************

/*
	//1.3. Директивы условной трансляции
	//Выполняя следующий фрагмент, посмотрите, какое
	//значение принимает переменная iNN. Что нужно сделать
	//для того, чтобы результат был равен 0? 1? 2?

int iNN;
#if defined NNN && defined MMM
	iNN = 0;
#elif defined MMM
	iNN = 1;
#elif defined NNN 
	iNN = 2;

#else
	iNN = -1;
#endif

	#define	NNN
	#define MMM

	// Если определена константа NNN и  MMM , то iNN = 0
	// Если определена константа NNN , то iNN = 2
	// Если определена константа MMM , то iNN = 1
	// Если не определены константы , то iNN = -1
	
	stop
*/
	
// *******************************************************

	//Задание 1.4. Загляните в Project/Properties -> диалоговая панель
	//- Property Pages/C\C++/Preprocessor/Preprocessor definitions.
	//В опциях командной строки в зависимости от мишени сборки проекта
	//(Debug или Release) может быть определено с помощью ключа /D
	//имя _DEBUG. С помощью директив условной
	//трансляции напишите фрагмент кода, который в зависимости от типа
	//мишени выводит с помощью cout разный текст на консоль. Проверьте
	//при разных мишенях сборки.

	//Пусть
	//для мишени Debug в процессе выполнения данного участка
	//кода на экран выводится информация об
	//имени файла, номере строки с функцией вывода, дате и времени 
	//компиляции файла, содержащего данную функцию вывода,
	//а также имя функции, содержащей данную строку.

	//Для мишени Release должна быть просто выведена строка
	//"Release configuration!"

	//Подсказка: 
	//Для получения имени функции можно использовать предопределенный макрос __FUNCTION__.
	//__FUNCTION__  определяется как строковый литерал, содержащий недекорированное имя включающей функции.
	//Макрос определен только в пределах функции.
	//Макрос __FUNCTION__ не разворачивается, если используется параметр компилятора /EP или /P .
	// https://docs.microsoft.com/ru-ru/cpp/preprocessor/predefined-macros?view=vs-2019

	// ИЛИ для получения полной информации о предопределенных макросах зайдите в online справку
	//(Help/View Help), выберете язык C++ и в поле поиска введите 
	//следующую ключевую фразу: Predefined Macros
	
	//Подсказка: мишень сборки проекта можно
	//поменять следующим образом - Build/Configuration Manager/Configuration

	//_DEBUG — определяется как 1, если заданы параметры компилятора / LDd, / MDd или / MTd
	// может быть определено с помощью ключа /D _DEBUG
	#ifdef _DEBUG
		std::cout << "File name: " << __FILE__ << \
					 "\nString number: " << __LINE__ << \
					 "\nTime compile: " << __TIME__ << \
					 "\nDate compile: " << __DATE__ << \
					 "\nFunction name: " << __FUNCTION__ << \
					 "\nFunction decor_name: " << __FUNCDNAME__ << std::endl;
	#else
		std::cout << "Release configuration!" << std::endl;
	#endif // _DEBUG


// *******************************************************
	{
		//Задание 1.5  Управляя определенностью идентификатора _UNICODE и используя
		//возможности заголовочного <tchar.h>, определим и проинициализируем переменную,
		//которая может становиться как однобайтовой, так и расширенной без 
		//изменения исходного текста.
		//С помощью отладчика проверьте результат (определите значение в 10-чной и 16-чной системе счисления).
		// #define __T(x)      L ## x
		// typedef wchar_t     TCHAR;
		// typedef unsigned int     size_t;
		// без L('Ф') считает как unsigned char
									//  при установке _UNICODE		// без установки _UNICODE 
		TCHAR ch1 = __T('A');		// ch1 = 65 / 0x0041			// ch1 = 65 / 0x0041
		size_t s1 = sizeof(ch1);	// s1 = 2 / 0x00000002			// s1 = 1 / 0x00000001
		TCHAR ch2 = __T('Ф');		// ch2 = 1060 / 0x0424			// ch2=	-44 'Ф' / 0xd4
		TCHAR ch3 = 'Ф';			// ch3 = 65492 /	0xffd4 'ￔ'	// ch3= -44 'Ф' / 0xd4
		stop
	}
// ********************************************************
	//Задание 2.Заголовочные файлы. Директива #include
	//Создайте и подключите к проекту два заголовочных файла 1.h и 2.h
	//В каждом заголовочном файле объявите перечисление с одинаковыми именами
	//констант, но сопоставьте именованным константам разные значения, например:
	//1.h - enum MyEnum{My1, My2, My3};  . 2.h - enum MyEnum{My1=5, My2, My3};
	//С помощью директив условной трансляции в DEBUG-версии пользуйтесь значениями
	//констант из 1.h, а в RELEASE-версии значениями констант из 2.h

	//_DEBUG — определяется как 1, если заданы параметры компилятора / LDd, / MDd или / MTd


	#ifdef _DEBUG
		#include "1.h"
	#else
		#include "2.h"
	#endif	// _DEBUG

// ********************************************************

	//Задание 3. Указатели
	//Объявите объекты разных типов и проинициализируйте их.
	//Объявите указатели соответствующих типов и проинициализируйте их
	//адресами заданных объектов. 
	//Выполняя задание, с помощью отладчика посмотрите, какие значения
	//будут присвоены переменным-указателям и на что эти указатели
	//"указывают"
	char value1 = 'A';
	int value2 = 5;
	double value3 = 2.5;
	// Он считает, что укзатель указвает на нультерминированную строку и пытается найти там ноль.
	// Он делает pValue1++ пока не встретится ноль.
	char* pValue1 = &value1;	// pValue1	0x0076fb13 "AММММММММФяММММММММММ$\x4ММММММММММ\x2"	char *
	int* pValue2 = &value2;		// pValue2	0x006ff9a4 {5}	int *
	double* pValue3 = &value3;	// pValue3	0x006ff994 {2.5000000000000000}	double*

	stop
// *******************************************************

	//Задание 3а. Объявите указатель на тип char и проинициализируйте
	//его адресом строкового литерала. Присвойте переменной типа char значение
	//любого элемента строки.
	//Проверьте - возможно ли присвоить какое-либо значение по адресу,
	//задаваемому указателем?

	const char* pString = "Hello1";
	pString = "Hello2";				//  pString = Hello2	изменять сам указатель можно // ошибка в том, что в памяти где то будет висеть Hello1 без адреса.
	// *pString = "Hello2";			// ошибка: изменять содержимое по адресу запрещено

	stop

// *******************************************************

	//Задание 4. Арифметика указателей. Операция разименования указателя.
	//Выполняя задание, следите за изменением значений
	//указателей и значений объектов, на которые они указывают.
	//Интерпретируте наблюдаемые результаты
	{
		int nAr[3] = {1,3};
		int* pn = &nAr[0];				//pn указывает на адрес первого элемента
		(*pn)++;						//*pn= 2   // инкрементирует первый элемент массива
		pn++;							//pn указывает на адрес второго элемента массива

		char cAr[]={'A','B','C','D'};
		char* pc = &cAr[0];				//pc указывает на адрес первого элемента
		(*pc)=(*pc)+5;					//*pc= 'F' // изменит значение 'A' и заменит первый элемент на 'F', будет ['F','B','C','D']
		pc=pc+3;						//pc указывает на адрес 'D' - 4-й элемент
	
		double dAr[3]={1.0,2.0};
		double* pd1 = &dAr[0];			//pd1 указывает на адрес первого элемента
		double* pd2 = pd1;				//pd2 указывает  на адрес  pd1 , а pd1 на первый элемент массива dAr
		(*pd2)+=2;						//*pd2=	3.0  // изменит	первый элемент массива dAr
		pd2+=2;							//pd2 указывает на адрес за границей массива

		//Объясните результат выполнения операции
		//вычитания двух указателей
		pd1 = &dAr[0];					//pd1 указывает на адрес первого элемента массива  
		pd2 = &dAr[1];					//pd2 указывает на адрес второго элемента массива  
		int nNumber=pd2 - pd1;			//   nNumber= 1	   pd1= 0x0048f830 (3.0)   pd2= 0x0048f83  (2.0)
		// результат означает, на сколько элементов "double" один адрес отстает от другого

		//Сравните указатели pd2 и pd1 и с помощью cout
		//выведите результаты сравнения.

 		stop
	}


// *******************************************************

	//Задание 5. Void-указатель. 
	//5.1. Выполняя задание, посмотрите - какие значения присваиваются
	//void-указателю. Обратите внимание: средствами отладчика Вы
	//не можете посмотреть значения, на которые "указывает"
	//void-указатель
	void*	pVoid;				//объявление void-указателя
	int	nObject3=5;
	char cObject3='A';			// 65
	int*	pInt = &nObject3;	// адрес - 0x0135fbcc 	int *
	pVoid=&nObject3;			// адрес - 0x0135fbcc 	void *
	pVoid=&cObject3;			// адрес - 0x0135fbc3	void *

	pVoid=pInt;					// адрес - 0x0135fbcc   void *
	
	//Прежде, чем раскомментировать следующую строчку, вспомните:
	//что нужно сделать, чтобы выражение стало корректным 

	// необходимо для компилятора уточнить какого типа содержит void* указатель
	pInt= static_cast<int*>(pVoid);		// адрес - 0x0135fbcc 	int *

	//Что нужно сделать для того, чтобы следующее закомментированное выражение
	//стало корректным?
	{
		
		const int n = 1;
		const void* pVoid2 = &n;	//????объявить слева void-указатель
		// указатель будет использоваться только для чтения значений
	}
// *******************************************************

	//5.2. При выполнении следующего фрагмента посмотрите, какие неприятности
	//могут Вас ожидать при явном приведении типа void-указателя,
	//который в момент времени (1) указывает на double, к типу 
	//указателя на int (2) 

	double dObject3 = 33.33;
	pVoid = &dObject3;	//(1)
	// появление неожиданного значения  вместо 33,  nTmp = 1889785610
	// причина формат представления в памяти плавающих чисел
	// отбрасывает старшую часть, сотавляя младшую. А младшая у нас мантисса
	int nTmp = *(static_cast<int*>(pVoid) ); //(2) 
	stop
// *******************************************************


	//Задание 6.При выполнении задания обратите внимание на то,
	//как наглядно отладчик "раскрывает" конструкции типа
	//"указатель на указатель" и на способы получения конечного
	//объекта по таким "иерархическим" указателям
	int	n1=1;

    //Объявите указатель pn и проинициализируйте его так, чтобы он
	//"указывал" на n1
	int* pn1 = &n1;			// содержит  адрес n1

    //Объявите указатель ppn и проинициализируйте его так, чтобы он
	//"указывал" на pn
	int** ppn1 = &pn1;		// содержит  адрес pn1

    //Объявите указатель pppn и проинициализируйте его так, чтобы он
	//"указывал" на ppn
	int*** pppn1 = &ppn1;	// содержит  адрес ppn1
  
	//С помощью указателей pn, ppn и pppn получите значение объекта n1
	//и присвойте его n2

	int n2 = *pn1;
	n2 = **ppn1;
	n2 = ***pppn1;  // n2 = 1

	stop

	return 0;
}//end main
