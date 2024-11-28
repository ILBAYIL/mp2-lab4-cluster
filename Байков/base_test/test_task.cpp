#include "Task.h"
#include <gtest.h>

TEST(Task, can_create_task_with_valid_parameters) {
    // —оздание задачи с продолжительностью 10 и требуемым количеством узлов 3
    Task task(10, 3);

    EXPECT_EQ(task.duration, 10);  // ѕровер€ем продолжительность задачи
    EXPECT_EQ(task.nodesRequired, 3);  // ѕровер€ем количество требуемых узлов
}
TEST(Task, can_create_task_with_zero_values) {
    // —оздание задачи с нулевой продолжительностью и нулевым количеством узлов
    Task task(0, 0);

    EXPECT_EQ(task.duration, 0);  // ѕродолжительность задачи должна быть 0
    EXPECT_EQ(task.nodesRequired, 0);  //  оличество требуемых узлов должно быть 0
}
TEST(Task, can_create_task_with_negative_values) {
    // —оздание задачи с отрицательными значени€ми
    Task task(-5, -2);

    EXPECT_EQ(task.duration, -5);  // ѕродолжительность задачи должна быть -5
    EXPECT_EQ(task.nodesRequired, -2);  //  оличество требуемых узлов должно быть -2
}
TEST(Task, can_create_task_with_large_values) {
    // —оздание задачи с большими значени€ми
    Task task(1000000, 1000);

    EXPECT_EQ(task.duration, 1000000);  // ѕродолжительность задачи должна быть 1000000
    EXPECT_EQ(task.nodesRequired, 1000);  //  оличество требуемых узлов должно быть 1000
}
