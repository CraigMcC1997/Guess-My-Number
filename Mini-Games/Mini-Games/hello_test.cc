#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <iostream>
#include "File_Handler.h"
#include "File_Handler.cpp" /* currently required to bypass linker2019 error as file can't find definitions */

// Demonstrate some basic assertions. Used to confirm testing is working
TEST(HelloTest, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}

TEST(FileHandlerTest, testingInputPath)
{
	/* Test set up */
	HandleFile file_handler = HandleFile();
	string file_lines[10]{};

	/* TEST 1: testing incorrect file name */
	string wrong_path_name = "Incorrect_String";
	int err = file_handler.loadAll(wrong_path_name, file_lines);

	EXPECT_EQ(err, 0);

	/* TEST 2: testing empty file name */
	string empty_path_name = "";
	err = file_handler.loadAll(empty_path_name, file_lines);

	EXPECT_EQ(err, 0);

	/* TEST 3: testing correct file name is able to load file */
	string correct_path_name = "N:/Code Repositories/Mini-Games-Repo/Mini-Games/Resources/GuessMyNumber/highscores.txt";
	err = file_handler.loadAll(correct_path_name, file_lines);

	EXPECT_NE(err, 0);
}

TEST(FileHandlerTest, testingInputArray)
{
	/* Test set up */
	HandleFile file_handler = HandleFile();
	string correct_path_name = "N:/Code Repositories/Mini-Games-Repo/Mini-Games/Resources/GuessMyNumber/highscores.txt";
	string file_lines[10]{};

	/* TEST 1: testing array size is as expected. Max highscores = 10 */
	int err = file_handler.loadAll(correct_path_name, file_lines);
	const int NUM_HIGHSCORES{ 10 };

	EXPECT_EQ(err, NUM_HIGHSCORES);
}

/* ! Update these tests to use fake test files instead of working data before working on this ! */
//TEST(FileHandlerTest, testingOutputPath)
//{
//	/* Test set up */
//	HandleFile file_handler = HandleFile();
//	string file_lines[10]{};
//
//	/* TEST 1: testing incorrect file name */
//	string wrong_path_name = "Incorrect_String";
//	int err = file_handler.saveToFile(wrong_path_name, file_lines);
//
//	EXPECT_EQ(err, 0);
//
//	/* TEST 2: testing empty file name */
//	string empty_path_name = "";
//	err = file_handler.saveToFile(empty_path_name, file_lines);
//
//	EXPECT_EQ(err, 0);
//
//	/* TEST 3: testing correct file name is able to load file */
//	string correct_path_name = "N:/Code Repositories/Mini-Games-Repo/Mini-Games/Resources/GuessMyNumber/highscores.txt";
//	err = file_handler.saveToFile(correct_path_name, file_lines);
//
//	EXPECT_NE(err, 0);
//}
