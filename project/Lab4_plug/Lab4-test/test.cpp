#include "pch.h"

#include <map>
#include <vector>
#include <fstream>

#include <clang-c/Index.h>


using namespace std;

map <string, string> classVariant = {
	{"V0", "Queue"},
	{"V1", "Set"},
	{"V2", "Bufer"},
	{"V3", "Heap"},
	{"V4", "Stack"}
};

string currentVariant;
char** gArgv;
int gArgc;

void printCursor(CXCursor cursor) {
    CXString displayName = clang_getCursorDisplayName(cursor);
    std::cout << clang_getCString(displayName) << "\n";
    clang_disposeString(displayName);
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

bool classCheck = false;

CXChildVisitResult searchClass(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
    CXSourceLocation location = clang_getCursorLocation(cursor);
    if (clang_Location_isFromMainFile(location) == 0)
        return CXChildVisit_Continue;


    // Основная часть - начало

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && clang_getCString(clang_getCursorDisplayName(cursor)) == currentVariant)
    {
        classCheck = true;
    }


    // Основная часть - конец

    clang_visitChildren(cursor, searchClass, nullptr);
    return CXChildVisit_Continue;
}

bool opPlusCheck = false;
bool opMinCheck = false;
bool opPlusRavnoCheck = false;
bool opMinRavnoCheck = false;
bool opRavnoCheck = false;

CXChildVisitResult searchAO(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
    CXSourceLocation location = clang_getCursorLocation(cursor);
    if (clang_Location_isFromMainFile(location) == 0)
        return CXChildVisit_Continue;


    // Основная часть - начало

    string name = clang_getCString(clang_getCursorDisplayName(cursor));

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("operator+(") !=  std::string::npos)
    {
        opPlusCheck = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("operator-(") != std::string::npos)
    {
        opMinCheck = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("operator+=(") != std::string::npos)
    {
        opPlusRavnoCheck = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("operator-=(") != std::string::npos)
    {
        opMinRavnoCheck = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("operator=(") != std::string::npos)
    {
        opRavnoCheck = true;
    }


    // Основная часть - конец

    clang_visitChildren(cursor, searchAO, nullptr);
    return CXChildVisit_Continue;
}

bool constrChecker = false;
bool destrChecker = false;

CXChildVisitResult searchCD(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
    CXSourceLocation location = clang_getCursorLocation(cursor);
    if (clang_Location_isFromMainFile(location) == 0)
        return CXChildVisit_Continue;


    // Основная часть - начало

    string name = clang_getCString(clang_getCursorDisplayName(cursor));
    string nameConstr = currentVariant;
    nameConstr.append("(");
    string nameDestr = "~";
    nameDestr.append(currentVariant);
    nameDestr.append("(");

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find(nameConstr) != std::string::npos)
    {
        constrChecker = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find(nameDestr) != std::string::npos)
    {
        destrChecker = true;
    }


    // Основная часть - конец

    clang_visitChildren(cursor, searchCD, nullptr);
    return CXChildVisit_Continue;
}

bool funcPushChecker = false;
bool funcPopChecker = false;
bool funcSearchChecker = false;
bool funcCompChecker = false;

bool funcGetPrChecker = false;
bool funcPopSeveralChecker = false;
bool funcNumAvChecker = false;

CXChildVisitResult searchMfunc(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
    CXSourceLocation location = clang_getCursorLocation(cursor);
    if (clang_Location_isFromMainFile(location) == 0)
        return CXChildVisit_Continue;


    // Основная часть - начало

    string name = clang_getCString(clang_getCursorDisplayName(cursor));

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("push(") != std::string::npos)
    {
        funcPushChecker = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("pop(") != std::string::npos)
    {
        funcPopChecker = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("search(") != std::string::npos)
    {
        funcSearchChecker = true;
    }

    if (clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("compareSize(") != std::string::npos)
    {
        funcCompChecker = true;
    }

    // для некоторых вариантов
    if (currentVariant == "Queue" && clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("getAllWithPriority(") != std::string::npos)
    {
        funcGetPrChecker = true;
    }

    if (currentVariant == "Bufer" && clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("popSeveral(") != std::string::npos)
    {
        funcPopSeveralChecker = true;
    }

    if (currentVariant == "Bufer" && clang_isDeclaration(clang_getCursorKind(cursor)) && name.find("numberAvailable(") != std::string::npos)
    {
        funcNumAvChecker = true;
    }


    // Основная часть - конец

    clang_visitChildren(cursor, searchMfunc, nullptr);
    return CXChildVisit_Continue;
}

// проверка класса
TEST(TestCaseName, Test_Class) {
    classCheck = false;

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
    string source_filename = "../../Lab4_plug/";
    source_filename.append(currentVariant);
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

        // Находим нужный класс
        clang_visitChildren(root, searchClass, nullptr);
    }
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);

    bool expected = true;

    EXPECT_EQ(classCheck, expected);
}

// проверка AS
TEST(TestCaseName, Test_AS) {
    bool privRes = false;
    bool publRes = false;
    countAS = 0;
    privPaM = false;
    publPaM = false;

    CXIndex index = clang_createIndex(0,1);

    // Добавление флага для компиляции c++, а не c
    char** new_argv = new char* [gArgc + 2];
    for (int i = 0; i < gArgc; i++)
    {
        new_argv[i] = gArgv[i];
    }
    new_argv[gArgc] = "-x";
    new_argv[gArgc + 1] = "c++";

    // Создание строки каталога исходного файла
    string source_filename = "../../Lab4_plug/";
    source_filename.append(currentVariant);
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

// проверка реализации арифметических операций
TEST(TestCaseName, Test_Arithmetic_operations) {
    opPlusCheck = false;
    opMinCheck = false;
    opPlusRavnoCheck = false;
    opMinRavnoCheck = false;
    opRavnoCheck = false;

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
    string source_filename = "../../Lab4_plug/";
    source_filename.append(currentVariant);
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

        // Находим нужный класс
        clang_visitChildren(root, searchAO, nullptr);
    }
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);


    bool expected = true;

    EXPECT_EQ(opPlusCheck, expected);
    EXPECT_EQ(opMinCheck, expected);
    EXPECT_EQ(opPlusRavnoCheck, expected);
    EXPECT_EQ(opMinRavnoCheck, expected);
    EXPECT_EQ(opRavnoCheck, expected);
}

// проверка реализации конструкторов и деструкторов
TEST(TestCaseName, Test_CD) {
    constrChecker = false;
    destrChecker = false;

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
    string source_filename = "../../Lab4_plug/";
    source_filename.append(currentVariant);
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

        // Находим нужный класс
        clang_visitChildren(root, searchCD, nullptr);
    }
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);


    bool expected = true;

    EXPECT_EQ(constrChecker, expected);
    EXPECT_EQ(destrChecker, expected);
}

// проверка основных функций
TEST(TestCaseName, Test_Mfunc) {
    funcPushChecker = false;
    funcPopChecker = false;
    funcSearchChecker = false;
    funcCompChecker = false;

    funcGetPrChecker = false;
    funcPopSeveralChecker = false;
    funcNumAvChecker = false;

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
    string source_filename = "../../Lab4_plug/";
    source_filename.append(currentVariant);
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

        // Находим нужный класс
        clang_visitChildren(root, searchMfunc, nullptr);
    }
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);


    bool expected = true;

    EXPECT_EQ(funcPushChecker, expected);
    EXPECT_EQ(funcPopChecker, expected);
    EXPECT_EQ(funcSearchChecker, expected);
    EXPECT_EQ(funcCompChecker, expected);

    if (currentVariant == "Queue")
    {
        EXPECT_EQ(funcGetPrChecker, expected);
    }

    if (currentVariant == "Bufer")
    {
        EXPECT_EQ(funcPopSeveralChecker, expected);
        EXPECT_EQ(funcNumAvChecker, expected);
    }
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	currentVariant = classVariant[argv[1]];
    gArgv = argv;
    gArgc = argc;


	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}