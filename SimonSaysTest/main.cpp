#include <gtest/gtest.h>
#include <gmock/gmock.h>




int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	std::cout << "Press Enter to exit...";
	std::cin.get();
}
