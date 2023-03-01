#include <gtest/gtest.h>
#include "File_Handler.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}

TEST(FileHandlerTest, testingInput)
{
	/* test set up */
	HandleFile file_handler = HandleFile();
	string file_lines[10]{};

	/* testing incorrect file name */
	const string wrong_path_name = "Incorrect_String";

	/* testing empty file */
	int load_all_wrong_path_name = file_handler.loadAll(wrong_path_name, file_lines);
	EXPECT_EQ(load_all_wrong_path_name, 0);
	/* testing empty file name */

	/* testing empty array */
}

//TEST(FileHandlerTest, testingOutput)
//{
//	/* testing incorrect file name */
//
//	/* testing empty file */
//
//	/* testing empty file name */
//
//	/* testing empty array */
//
//	/* testing size = 0 */
//}
