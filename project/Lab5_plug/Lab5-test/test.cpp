#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED 
#include "pch.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <boost/filesystem.hpp>

#include <clang-c\Index.h>
#include <map>


using namespace std;
namespace fs = boost::filesystem;

struct TreeClass
{
	CXCursor cursorClass;
	string name;
	int numberParent;
	TreeClass** parents;
};

int maxLevel = 0;



void addAllClassInArray();
void addClassMap();
int searchLevelA(int level, TreeClass* curItem);



map <string, string> classVariant = {
	{"V0", "Person"},
	{"V1", "Animal"},
	{"V2", "Vehicle"},
	{"V3", "Instrument"},
	{"V4", "Figure"},
	{"V5", "ComputeUnit"},
	{"V6", "FlyingObject"},
	{"V7", "SwimmingObject"}
};

string* className;
int coutnClass = 0;

map <string, TreeClass*> allClassMap;

string currentVariant;
char** gArgv;
int gArgc;

void printCursor(CXCursor cursor) {
	CXString displayName = clang_getCursorDisplayName(cursor);
	std::cout << clang_getCString(displayName) << "\n";
	clang_disposeString(displayName);
}

int numberParent = 0;
CXCursor cursorClass;

CXChildVisitResult visitClass(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	if (clang_getCursorKind(cursor) == 4)
	{
		cursorClass = cursor;
	}

	if (clang_getCursorKind(cursor) == 44)
	{
		numberParent++;
	}

	// Основная часть - конец

	clang_visitChildren(cursor, visitClass, nullptr);
	return CXChildVisit_Continue;
}

// Массив родителей
map <string, string*> mapAppend;
// кол-во родителей
map <string, int> mapAppendSize;
string curClassname;
int chechParentsCounter = 0;

CXChildVisitResult chechParents(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало


	if (clang_getCursorKind(cursor) == 44)
	{
		mapAppend[curClassname][chechParentsCounter++] = (string)clang_getCString(clang_getCursorDisplayName(cursor));
	}

	// Основная часть - конец

	clang_visitChildren(cursor, chechParents, nullptr);
	return CXChildVisit_Continue;
}

CXCursor AccessSpecifier[2];
int countAS = 0;

CXChildVisitResult searchAccessSpecifier(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	if (clang_getCursorKind(cursor) == 39 && countAS < 2)
	{
		AccessSpecifier[countAS++] = cursor;
	}

	// Основная часть - конец

	clang_visitChildren(cursor, searchAccessSpecifier, nullptr);
	return CXChildVisit_Continue;
}

// 0 - not met
// 1 - 1 met
// 2 - 2 met
int checkerPaM = 0;

// условие, есть ли cursor элементы внутри public и private
bool privPaM = false;
bool publPaM = false;

CXChildVisitResult propertiesAndMethods(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	if (countAS > 0 && clang_equalCursors(cursor, AccessSpecifier[0]))
	{
		checkerPaM = 1;

		clang_visitChildren(cursor, propertiesAndMethods, nullptr);
		return CXChildVisit_Continue;
	}

	if (countAS > 1 && clang_equalCursors(cursor, AccessSpecifier[1]))
	{
		checkerPaM = 2;

		clang_visitChildren(cursor, propertiesAndMethods, nullptr);
		return CXChildVisit_Continue;
	}

	if (checkerPaM == 1)
	{
		privPaM = true;
	}

	if (checkerPaM == 2)
	{
		publPaM = true;
	}


	// Основная часть - конец

	clang_visitChildren(cursor, propertiesAndMethods, nullptr);
	return CXChildVisit_Continue;
}

bool condStat = false;

CXChildVisitResult findStatic2(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	if (clang_getCursorKind(cursor) == 9)
	{
		condStat = true;
	}


	// Основная часть - конец

	return CXChildVisit_Continue;
}

CXChildVisitResult findStatic1(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	// Основная часть - конец

	clang_visitChildren(cursor, findStatic2, nullptr);
	return CXChildVisit_Continue;
}

bool condVirt = false;

CXChildVisitResult findVirtual2(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	if (clang_CXXMethod_isVirtual(cursor) && clang_getCString(clang_getCursorDisplayName(cursor))[0] != '~')
	{
		condVirt = true;
	}


	// Основная часть - конец

	return CXChildVisit_Continue;
}

CXChildVisitResult findVirtual1(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// Основная часть - начало

	// Основная часть - конец

	clang_visitChildren(cursor, findVirtual2, nullptr);
	return CXChildVisit_Continue;
}

// Проверка числа классов
TEST(TestCaseName, Test1) {
	bool a = coutnClass >= 6;

	bool expected = true;
	EXPECT_EQ(expected, a);
}

// Проверка на глубину
TEST(TestCaseName, Test2) {
	bool a = maxLevel >= 3;

	bool expected = true;
	EXPECT_EQ(expected, a);
}

// Проверка на наличие базового класса
TEST(TestCaseName, Test3) {
	bool a = false;

	for (int i = 0; i < coutnClass; i++)
	{
		if (className[i] == currentVariant)
			a = true;
	}

	bool expected = true;
	EXPECT_EQ(expected, a);
}

// Проверка AS
TEST(TestCaseName, Test_AS) {
	for (int i = 0; i < coutnClass; i++)
	{
		bool privRes = false;
		bool publRes = false;
		countAS = 0;
		privPaM = false;
		publPaM = false;

		CXIndex index = clang_createIndex(0, 1);

		// Добавление флага для компиляции c++, а не c
		char** new_argv = new char* [gArgc + 2];
		for (int i = 0; i < gArgc; i++)
		{
			new_argv[i] = gArgv[i];
		}
		new_argv[gArgc] = "-x";
		new_argv[gArgc + 1] = "c++";

		// Создание строки каталога исходного файла
		string source_filename = "../../Lab5_plug/"; // ИЗМЕНИТЬ
		source_filename.append(className[i]);
		source_filename.append(".h");

		CXTranslationUnit unit = clang_parseTranslationUnit(
			index, // CIdx
			source_filename.c_str(), // source_filename
			new_argv, // command_line_args
			gArgc + 2, // num_command_line_args
			0, // unsave_files
			0, // num_unsaved_files
			CXTranslationUnit_None // options
		);
		if (!unit) {
			std::cout << "Translation unit was not created\n";
		}
		else {
			// content source file
			ifstream file(source_filename);
			istreambuf_iterator<char> begin(file), end;
			vector<char> v(begin, end);
			string contentOfTheFile = &v[0];

			if (contentOfTheFile.find("private:"))
			{
				privRes = true;
			}
			if (contentOfTheFile.find("private:"))
			{
				publRes = true;
			}


			CXCursor root = clang_getTranslationUnitCursor(unit);

			// Находим спецификаторы
			clang_visitChildren(root, searchAccessSpecifier, nullptr);

			// Определяем, существуют ли свойства и методы под этими спецификаторами
			clang_visitChildren(root, propertiesAndMethods, nullptr);
		}
		clang_disposeTranslationUnit(unit);
		clang_disposeIndex(index);


		bool privExpected = true;
		bool publExpected = true;

		// private:
		EXPECT_EQ(privExpected, privRes);
		// public:
		EXPECT_EQ(publExpected, publRes);

		// проверяет, есть ли в этих модификаторах доступа элементы
		EXPECT_EQ(privPaM, privExpected);
		EXPECT_EQ(publPaM, publExpected);
	}
}

// Проверка статических методов
TEST(TestCaseName, Test_Static) {
	int countRes = 0;
	for (int i = 0; i < coutnClass; i++)
	{
		condStat = false;
		CXIndex index = clang_createIndex(0, 1);

		// Добавление флага для компиляции c++, а не c
		char** new_argv = new char* [gArgc + 2];
		for (int i = 0; i < gArgc; i++)
		{
			new_argv[i] = gArgv[i];
		}
		new_argv[gArgc] = "-x";
		new_argv[gArgc + 1] = "c++";

		// Создание строки каталога исходного файла
		string source_filename = "../../Lab5_plug/"; // ИЗМЕНИТЬ
		source_filename.append(className[i]);
		source_filename.append(".h");

		CXTranslationUnit unit = clang_parseTranslationUnit(
			index, // CIdx
			source_filename.c_str(), // source_filename
			new_argv, // command_line_args
			gArgc + 2, // num_command_line_args
			0, // unsave_files
			0, // num_unsaved_files
			CXTranslationUnit_None // options
		);
		if (!unit) {
			std::cout << "Translation unit was not created\n";
		}
		else {

			CXCursor root = clang_getTranslationUnitCursor(unit);

			// Находим спецификаторы
			clang_visitChildren(root, findStatic1, nullptr);

			if (condStat)
				countRes++;
		}
		clang_disposeTranslationUnit(unit);
		clang_disposeIndex(index);
	}

	bool result = countRes >= 3;

	bool expected = true;

	EXPECT_EQ(expected, result);
}

// Проверка виртуальных методов
TEST(TestCaseName, Test_Virtual) {
	condVirt = false;
	for (int i = 0; i < coutnClass; i++)
	{
		condStat = false;
		CXIndex index = clang_createIndex(0, 1);

		// Добавление флага для компиляции c++, а не c
		char** new_argv = new char* [gArgc + 2];
		for (int i = 0; i < gArgc; i++)
		{
			new_argv[i] = gArgv[i];
		}
		new_argv[gArgc] = "-x";
		new_argv[gArgc + 1] = "c++";

		// Создание строки каталога исходного файла
		string source_filename = "../../Lab5_plug/"; // ИЗМЕНИТЬ
		source_filename.append(className[i]);
		source_filename.append(".h");

		CXTranslationUnit unit = clang_parseTranslationUnit(
			index, // CIdx
			source_filename.c_str(), // source_filename
			new_argv, // command_line_args
			gArgc + 2, // num_command_line_args
			0, // unsave_files
			0, // num_unsaved_files
			CXTranslationUnit_None // options
		);
		if (!unit) {
			std::cout << "Translation unit was not created\n";
		}
		else {

			CXCursor root = clang_getTranslationUnitCursor(unit);

			// Находим спецификаторы
			clang_visitChildren(root, findVirtual1, nullptr);

		}
		clang_disposeTranslationUnit(unit);
		clang_disposeIndex(index);

	}

	bool expected = true;
	EXPECT_EQ(expected, condVirt);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	currentVariant = classVariant[argv[1]];
	gArgv = argv;
	gArgc = argc;

	// Находим все классы
	addAllClassInArray();
	// Строим иерархию классов
	addClassMap();
	// Ищем глубину
	for (int i = 0; i < coutnClass; i++)
	{
		searchLevelA(0, allClassMap[className[i]]);
	}

	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}

void addAllClassInArray()
{
	// добавляем все классы
	std::string path("../../Lab5_plug/");
	std::string ext(".h");
	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (p.path().extension() == ext)
		{
			coutnClass++;
		}
	}

	className = new string[coutnClass];
	int i = 0;

	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (p.path().extension() == ext)
		{
			className[i++] = p.path().stem().string();
		}
	}
}

void addClassMap()
{

	for (int i = 0; i < coutnClass; i++)
	{
		numberParent = 0;

		CXIndex index = clang_createIndex(0, 1);

		// Добавление флага для компиляции c++, а не c
		char** new_argv = new char* [gArgc + 2];
		for (int i = 0; i < gArgc; i++)
		{
			new_argv[i] = gArgv[i];
		}
		new_argv[gArgc] = "-x";
		new_argv[gArgc + 1] = "c++";

		// Создание строки каталога исходного файла
		string source_filename = "../../Lab5_plug/";  // ТУТ ПОМЕНЯТЬ !!!
		source_filename.append(className[i]);
		source_filename.append(".h");

		CXTranslationUnit unit = clang_parseTranslationUnit(
			index, // CIdx
			source_filename.c_str(), // source_filename
			new_argv, // command_line_args
			gArgc + 2, // num_command_line_args
			0, // unsave_files
			0, // num_unsaved_files
			CXTranslationUnit_None // options
		);
		if (!unit) {
			std::cout << "Translation unit was not created\n";
		}
		else {

			CXCursor root = clang_getTranslationUnitCursor(unit);

			// Проходим по элементам дерева
			clang_visitChildren(root, visitClass, nullptr);

			mapAppend[className[i]] = new string[numberParent];
			curClassname = className[i];
			mapAppendSize[className[i]] = numberParent;
			chechParentsCounter = 0;

			// Помечаем наследуемые классы (их число)
			clang_visitChildren(root, chechParents, nullptr);

			TreeClass* newItem = new TreeClass;
			newItem->cursorClass = cursorClass;
			newItem->name = className[i];
			newItem->numberParent = numberParent;

			allClassMap[className[i]] = newItem;

		}
		clang_disposeTranslationUnit(unit);
		clang_disposeIndex(index);
	}
	
	for (int i = 0; i < coutnClass; i++)
	{
		allClassMap[className[i]]->parents = new TreeClass*[mapAppendSize[className[i]]];

		for (int z = 0; z < mapAppendSize[className[i]]; z++)
		{
			allClassMap[className[i]]->parents[z] = allClassMap[mapAppend[className[i]][z]];
		}
	}
}

// поиск глубины массива
int searchLevelA(int level, TreeClass* curItem)
{
	level++;

	if (level > maxLevel)
		maxLevel = level;

	for (int i = 0; i < mapAppendSize[curItem->name]; i++)
	{
		searchLevelA(level, curItem->parents[i]);
	}
	return 0;
}