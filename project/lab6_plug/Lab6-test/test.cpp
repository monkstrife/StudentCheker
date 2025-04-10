#include "pch.h"

#include <map>
#include <vector>
#include <fstream>

#include <clang-c/Index.h>

using namespace std;


map <string, string> classVariant = {
	{"V0", "Author"},
	{"V1", "Book"},
	{"V2", "Country"},
	{"V3", "City"},
	{"V4", "Island"},
	{"V5", "Language"},
	{"V6", "Sea"},
	{"V7", "Football_Team"}
};

string currentVariant;
char** gArgv;
int gArgc;

void printCursor(CXCursor cursor) {
	CXString displayName = clang_getCursorDisplayName(cursor);
	std::cout << clang_getCString(displayName) << "\n";
	clang_disposeString(displayName);
}

bool condBaseClass = false;
CXChildVisitResult searchBase(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������

	if (clang_getCString(clang_getCursorDisplayName(cursor)) == currentVariant && clang_isDeclaration(clang_getCursorKind(cursor)))
	{
		condBaseClass = true;
	}
	

	// �������� ����� - �����

	clang_visitChildren(cursor, searchBase, nullptr);
	return CXChildVisit_Continue;
}

CXTypeKind diffTypeArray[3] = { CXType_Invalid, CXType_Invalid , CXType_Invalid };

CXChildVisitResult diffType2(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������

	if (clang_getCursorKind(cursor) == 6)
	{
		if (diffTypeArray[0] == CXType_Invalid)
		{
			diffTypeArray[0] = clang_getCursorType(cursor).kind;
		}
		else
		{
			if (diffTypeArray[1] == CXType_Invalid)
			{
				if (clang_getCursorType(cursor).kind != diffTypeArray[0])
				{
					diffTypeArray[1] = clang_getCursorType(cursor).kind;
				}
			}
			else
			{
				if (diffTypeArray[2] == CXType_Invalid)
				{
					if (clang_getCursorType(cursor).kind != diffTypeArray[0] && clang_getCursorType(cursor).kind != diffTypeArray[1])
					{
						diffTypeArray[2] = clang_getCursorType(cursor).kind;
					}
				}
			}
		}
	}
	
	//cout << clang_getCString(clang_getCursorDisplayName(cursor)) << " == " << clang_getCursorKind(cursor) << endl;


	// �������� ����� - �����

	return CXChildVisit_Continue;
}

CXChildVisitResult diffType1(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������

	// �������� ����� - �����

	clang_visitChildren(cursor, diffType2, nullptr);
	return CXChildVisit_Continue;
}

bool condSort = false;
CXChildVisitResult searchSort(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("sort") != std::string::npos)
	{
		condSort = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchSort, nullptr);
	return CXChildVisit_Continue;
}

bool condMin = false;
CXChildVisitResult searchMin(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("min_element") != std::string::npos)
	{
		condMin = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchMin, nullptr);
	return CXChildVisit_Continue;
}

bool condTrans = false;
CXChildVisitResult searchTrans(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("transform") != std::string::npos)
	{
		condTrans = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchTrans, nullptr);
	return CXChildVisit_Continue;
}

bool condAcc = false;
CXChildVisitResult searchAcc(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("accumulate") != std::string::npos)
	{
		condAcc = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchAcc, nullptr);
	return CXChildVisit_Continue;
}

bool condFor = false;
CXChildVisitResult searchFor(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("for_each") != std::string::npos)
	{
		condFor = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchFor, nullptr);
	return CXChildVisit_Continue;
}

bool condFind = false;
CXChildVisitResult searchFind(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("find_if") != std::string::npos)
	{
		condFind = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchFind, nullptr);
	return CXChildVisit_Continue;
}

bool condStream = false;
CXChildVisitResult searchStream(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������


	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("ifstream") != std::string::npos || ((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("ofstream") != std::string::npos)
	{
		condStream = true;
	}

	//printCursor(cursor);

	// �������� ����� - �����

	clang_visitChildren(cursor, searchStream, nullptr);
	return CXChildVisit_Continue;
}

bool condLamda = false;
CXChildVisitResult searchLamda(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������

	if (clang_getCursorKind(cursor) == 144)
	{
		condLamda = true;
	}

	// �������� ����� - �����

	clang_visitChildren(cursor, searchLamda, nullptr);
	return CXChildVisit_Continue;
}

bool condFunctor = false;
CXChildVisitResult searchFunctor(CXCursor cursor, CXCursor /* parent */, CXClientData /*clientData*/)
{
	CXSourceLocation location = clang_getCursorLocation(cursor);
	if (clang_Location_isFromMainFile(location) == 0)
		return CXChildVisit_Continue;


	// �������� ����� - ������

	if (((string)clang_getCString(clang_getCursorDisplayName(cursor))).find("operator()") != std::string::npos)
	{
		condFunctor = true;
	}

	// �������� ����� - �����

	clang_visitChildren(cursor, searchFunctor, nullptr);
	return CXChildVisit_Continue;
}

// ���� �� ����������� �������� ������
TEST(TestCaseName, Test_BC) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
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

		// ������� �������������
		clang_visitChildren(root, searchBase, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condBaseClass, expected);
}

// ���� �� ����������� ������� 3� ����� ������� ����
TEST(TestCaseName, Test_DT) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
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

		// ������� �������������
		clang_visitChildren(root, diffType1, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);
	
	bool result = true;
	bool expected = true;

	for (int i = 0; i < 3; i++)
	{
		if (diffTypeArray[i] == CXType_Invalid)
			result = false;
	}

	EXPECT_EQ(result, expected);
}

// ���� �� sort
TEST(TestCaseName, Test_Sort) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchSort, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condSort, expected);
}

// ���� �� min_element
TEST(TestCaseName, Test_Min_element) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchMin, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condMin, expected);
}

// ���� �� transform
TEST(TestCaseName, Test_Transform) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchTrans, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condTrans, expected);
}

// ���� �� acc
TEST(TestCaseName, Test_Acc) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchAcc, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condAcc, expected);
}

// ���� �� for_each
TEST(TestCaseName, Test_For) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchFor, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condFor, expected);
}

// ���� �� find_if
TEST(TestCaseName, Test_Find) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchFind, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condFind, expected);
}

// ���� �� if/ofstream
TEST(TestCaseName, Test_Stream) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchStream, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condStream, expected);
}

// ���� �� �����-���������
TEST(TestCaseName, Test_Lamda) {
	CXIndex index = clang_createIndex(0, 1);

	// ���������� ����� ��� ���������� c++, � �� c
	char** new_argv = new char* [gArgc + 2];
	for (int i = 0; i < gArgc; i++)
	{
		new_argv[i] = gArgv[i];
	}
	new_argv[gArgc] = "-x";
	new_argv[gArgc + 1] = "c++";

	// �������� ������ �������� ��������� �����
	string source_filename = "../../Lab6_plug/"; // ��������
	source_filename.append("Source.cpp");


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

		// ������� �������������
		clang_visitChildren(root, searchLamda, nullptr);
	}
	clang_disposeTranslationUnit(unit);
	clang_disposeIndex(index);

	bool expected = true;

	EXPECT_EQ(condLamda, expected);
}

// ����� ���������
TEST(TestCaseName, Test_Functor) {
	for (int i = 0; i < 2; i++)
	{
		CXIndex index = clang_createIndex(0, 1);

		// ���������� ����� ��� ���������� c++, � �� c
		char** new_argv = new char* [gArgc + 2];
		for (int i = 0; i < gArgc; i++)
		{
			new_argv[i] = gArgv[i];
		}
		new_argv[gArgc] = "-x";
		new_argv[gArgc + 1] = "c++";

		// �������� ������ �������� ��������� �����
		string source_filename = "../../Lab6_plug/"; // ��������
		if (i == 0)
		{
			source_filename.append("Source.cpp");
		}
		else
		{
			source_filename.append(currentVariant);
			source_filename.append(".h");
		}
		


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

			// ������� �������������
			clang_visitChildren(root, searchFunctor, nullptr);
		}
		clang_disposeTranslationUnit(unit);
		clang_disposeIndex(index);
	}

	bool expected = true;
	EXPECT_EQ(condFunctor, expected);
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