#include "pch.h"
#include "../UniquePointerExercise/Unique_Ptr.h"

TEST(Sprint1, UniquePointerWithTypeEntity) {

	//	Arrange
	struct Entity {
		int id = -1;
	};

	int CompareValue = -1;

	//	Action
	unique_ptr<Entity> entityPointer(new Entity);

	//	Assert
	EXPECT_EQ(CompareValue, entityPointer->id);

}

TEST(Sprint1, UniquePointerWithTypeString) {

	//	Arrange
	unique_ptr<std::string> stringPointer(new std::string("Hello World"));

	std::string CompareValue = "Hello World";

	//	Action


	//	Assert

	EXPECT_STREQ(CompareValue.c_str(), stringPointer->c_str());
}

TEST(Sprint1, UniquePointerMoveConstructorAssignment) {

	//	Arrange
	unique_ptr<int> foo(new int(10));
	unique_ptr<int> bar(new int(20));
	unique_ptr<int> ComparePointer(new int(20));

	//	Action
	foo = std::move(bar);

	//	Assert
	EXPECT_EQ(*ComparePointer, *foo);
	EXPECT_FALSE(bar);

}

TEST(Sprint1, UniquePointerMoveConstructorSelfAssignment) {

	//	Arrange
	unique_ptr<int> foo(new int(10));
	unique_ptr<int> ComparePointer(new int(10));

	//	Action
	foo = std::move(foo);

	//	Assert
	EXPECT_EQ(*ComparePointer, *foo);
}

TEST(Sprint1, UniquePointerBoolOperator) {

	//	Arrange
	struct Entity {
		int id = -1;
	};

	//	Action
	unique_ptr<Entity> entityPointer(new Entity);

	//	Assert
	EXPECT_TRUE(entityPointer);

}

TEST(Sprint2, UniquePointerSwapMethodUniquePointer) {

	//	Arrange
	unique_ptr<int> foo(new int(10));
	unique_ptr<int> bar(new int(20));

	//	Action
	foo.Swap(bar);

	//	Assert
	EXPECT_EQ(10, *bar);
	EXPECT_EQ(20, *foo);

}

TEST(Sprint2, UniquePointerSwapMethodRawPointer) {

	//	Arrange
	unique_ptr<int> foo(new int(10));
	int* bar = new int(20);

	//	Action
	foo.Swap(bar);

	//	Assert
	EXPECT_EQ(10, *bar);
	EXPECT_EQ(20, *foo);
}

TEST(Sprint2, UniquePointerResetMethod) {

	//	Arrange
	unique_ptr<int> foo(new int(10));


	//	Action
	foo.Reset();

	//	Assert
	EXPECT_FALSE(foo);
}

TEST(Sprint2, UniquePointerReleaseMethod) {

	//	Arrange
	int* bar;

	{
		unique_ptr<int> foo(new int(10));
		bar = foo.Release();
		EXPECT_FALSE(foo);
	}

	//	Assert
	EXPECT_TRUE(bar);
}
