#include "My_linear_array.cpp"

#include <gtest/gtest.h>

struct My_linear_array_fixture : public testing::Test {
    My_linear_array<int> test_array;

    void SetUp() override {
        for (int i = 0; i < 10; ++i) {
            test_array.push_back(i);
        }
    }

    void TearDown() override {

    }
};

TEST(My_linear_array, Empty) {
    // Arrange
    My_linear_array<int> test_array;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(test_array.get_size(), 0);
}

TEST(My_linear_array, push_back) {
    // Arrange
    My_linear_array<int> test_array;

    // Act
    const int ref = 10;
    test_array.push_back(ref);

    // Assert
    ASSERT_EQ(test_array.get_last(), ref);
}

TEST(My_linear_array, push_front) {
    // Arrange
    My_linear_array<int> test_array;

    // Act
    const int ref = 5;
    test_array.push_front(ref);

    // Assert
    ASSERT_EQ(test_array.get_first(), ref);
}

TEST_F(My_linear_array_fixture, push_middle) {
    // Arrange
    const size_t ref_size = test_array.get_size();

    // Act
    const int ref = 42;
    const size_t position = test_array.get_size()-1;
    test_array.insert(ref, position);

    // Assert
    ASSERT_EQ(test_array[position], ref);
    ASSERT_EQ(test_array.get_size(), ref_size+1);
}

TEST_F(My_linear_array_fixture, erase_first) {
    // Arrange
    const size_t ref_size = test_array.get_size();
    const int ref_value = test_array[0];

    // Act
    test_array.erase(0);

    // Assert
    ASSERT_NE(test_array[0], ref_value);
    ASSERT_EQ(test_array.get_size(), ref_size-1);
}

TEST_F(My_linear_array_fixture, erase_last) {
    // Arrange
    const size_t ref_size = test_array.get_size();
    const int ref_value = test_array[ref_size-1];

    // Act
    test_array.erase(ref_size-1);

    // Assert
    ASSERT_NE(test_array[ref_size-2], ref_value);
    ASSERT_EQ(test_array.get_size(), ref_size-1);
}

TEST_F(My_linear_array_fixture, erase_middle) {
    // Arrange
    const size_t ref_size = test_array.get_size();
    const int ref_value = test_array[ref_size/2];

    // Act
    test_array.erase(ref_size/2);

    // Assert
    ASSERT_NE(test_array[ref_size/2-1], ref_value);
    ASSERT_EQ(test_array.get_size(), ref_size-1);
}

TEST_F(My_linear_array_fixture, get_element) {
    // Arrange

    // Act

    // Assert
    ASSERT_EQ(test_array[0], 0);
    ASSERT_EQ(test_array[3], 3);
}

TEST(My_linear_array, get_size) {
    // Arrange
    My_linear_array<int> test_array;
    size_t ref_size = 6;
    for (int i = 0; i < ref_size; ++i) {
        test_array.push_back(i);
    }

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(test_array.get_size(), ref_size);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

